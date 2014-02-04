#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "libpnm.h"


const unsigned int max_search_buffer_size = 8191;	// 0..8190, 8192 is the EOF marker.
unsigned int search_buffer_size = 8190;	            // this can be LESS: ARG[1] on command line
char	LZ77filename[256];				            // saved LZ77 filename
int decodeLZ77array[999999];
int *LZ77array;						                // this will point to encoded array 'large enough' (3 * size of PGM array)
int LZ77 = 0;						                // this is the subscript for the above array
int offsetvalues[999999];			                // this will point to offset values array malloc'd enough to fit assignment
int offsetlength[999999];
int offsetcount = 0;				                // count of above
int width, height;

struct PGM_Image pgmImage;
struct PGM_Image origpgmImage;	// PGM image a 1 byte greyscale image 0=Black, 255=White.
char filename[1048];
char originalFilename[1048];


void putcolor(struct PGM_Image * pgmImage, int offset, unsigned char color)		// convert offset to X,Y and save that color
{
		if (offset >= (pgmImage->width * pgmImage->height)) printf("*** Offset Overflow ***\n");
		pgmImage->image[offset / pgmImage->width][offset % pgmImage->width] = color;
}


void save_encoded_char(int value)						// save a literal into 'encoded' array
{
	LZ77array[LZ77++] = value & 255;					// guarantees less than 256
}

//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

void save_encoded_refer(int longest_p, int longest_len)	// save a reference into 'encoded' array
{
	LZ77array[LZ77++] = longest_p | 8192;				// offset to longest match with bit 14 set
	LZ77array[LZ77++] = longest_len;					// length of longest match

	offsetvalues[offsetcount] = longest_p;				// needed for stats, bit 14 not set here
	offsetlength[offsetcount] = longest_len;
	offsetcount++;
}

//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

unsigned char getcolor(struct PGM_Image * pgmImage, int offset)	// convert an offset to X,Y and return that color
{
	if (offset >= (pgmImage->width * pgmImage->height)) printf("*** Offset Overflow (should never happen) *** offset=%d\n", offset);
	return pgmImage->image[offset / pgmImage->width][offset % pgmImage->width];	// return color
}

void encode(){
	if (0 != load_PGM_Image(&pgmImage, filename))				// problem with loading
	{ printf("\tError loading PGM Image file.\n");
	exit(3);
	}
	printf("\tPGM file read successfully: %s\n", filename);
	printf("\tImage is %d  %d\n", pgmImage.width, pgmImage.height);



	printf("\tAllocating buffer: %d bytes\n", 3 * pgmImage.height * pgmImage.width *sizeof(unsigned char));	// 3 times larger allocation.
	LZ77array = (int *)malloc(pgmImage.height * pgmImage.width * sizeof(int));


	printf("\tLZ77 Encoding...\n");

	clock_t clock1 = clock();



	// - - - - Encode_Using_LZ77 - - - - - - -

	int p=0;													// this is the current pointer in the PGM file
	while (p < (pgmImage.width *  pgmImage.height))				// main loop control. Go thru all p (all colors in image)
	{ 
		int i;
		int win_p = p - search_buffer_size;						// what pointer does the window go back to
		if (win_p < 0) win_p = 0;								// not less than the beginning

		int longest_p;											// used to determine the longest match found in the search buffer
		int longest_len=0;		

		int scan_p = p - 1;										// scan pointer starts at p-1
		while (scan_p >= win_p) 								// scanning backwards in search window and not past beginning
		{														// ..to find a match (ie. first of a possible matching string)
			if (getcolor(&pgmImage, scan_p) != getcolor(&pgmImage, p))
			{	scan_p--;
			continue;										// No, not equal...continue with while
			}
			// yes, find length of matching string
			for (i=0; i < (p-scan_p); i++)						// start with current and work forwards
			{													// see how long matching a string
				if ((p + i) >= (pgmImage.width *  pgmImage.height)) break;					// too far
				if (getcolor(&pgmImage, scan_p + i) != (getcolor(&pgmImage, p + i))) break;	// no match, done.
			}

			if (i > longest_len)								// i is the length of matching string (base 1, not base 0)
			{	longest_len = i; longest_p = scan_p;			// this is the longest found so far
			}
			// now, continue finding next first match
			scan_p--;
		}//while

		if (longest_len > 0)	//we found a match
		{
			save_encoded_refer(p-longest_p, longest_len);		// save a reference to an already known match earlier in the file
			p = p + longest_len;								// a few lines down will also spit out the non-matching char too
		}

		if (p < (pgmImage.width *  pgmImage.height))			// past end of image protection (only 1 case)
		{
			save_encoded_char((int)getcolor(&pgmImage, p));		// no match. save literal current p color
			p++;
		}

	}//while all p

	save_encoded_refer(16383, 0);								// EOF marker: 14 bits of 1's is the marker

	printf("\tElapsed Time (sec): %f\n", ((float)(clock() - (float)clock1) / CLOCKS_PER_SEC) );



	// - - - - Save Offsets and Lenghts in a separate file - - - -
	
	char buffersize[256];
	sprintf(buffersize, "%i", search_buffer_size);
	
	strcpy(LZ77filename, filename);						// offset values are placed in a starting with the input filename and
	strcat(LZ77filename, buffersize);
	strcat(LZ77filename, ".OffsetValues" );     		// ...we add the (dot)OffsetValues to the end of it.	
	printf("\tEncoded array contains %d entries.\n", LZ77);
	printf("\tThere are %d 'Offset Values' saved in the text file: %s\n", offsetcount, LZ77filename);

	// write Offset and Lengths in a separate file, so we can analyise
	FILE * afile = fileOpener(WRITE, LZ77filename);
	if (afile == NULL)
		printf("\tCannot save Offsets and Lengths. Error opening file.\n");
	else
	{
		fprintf(afile, "%d Offsets and Lenghts for PGM %s with width %d and height %d\n", offsetcount, filename, pgmImage.width, pgmImage.height);
		fprintf(afile, "Offset Values, Offset Length, Value Freq, Length Freq\n");
		
		int i;
		
		for (i=0; i <= search_buffer_size; i++){
			int freq = 0;
			int freq2 = 0;
			int x;
				
				for(x=0; x<=offsetcount;x++){
					if(offsetvalues[x] == i)
						freq++;		
				}
				for(x=0; x<=offsetcount;x++){
					if(offsetlength[x] == i)
						freq2++;		
				}

				
			
		
			if(i <= offsetcount){
			fprintf(afile, "%d, %d, %d, %d\n", offsetvalues[i], offsetlength[i], freq, freq2);
			}else{
			fprintf(afile, " , ,%d, %d\n", freq, freq2);
			}
		}
		fclose(afile);
	}



	// - - - - Save LZ77 encoded array in a separate file - - - -

	strcpy(LZ77filename, filename);						// input filename becomes output filename...but...
	strcat(LZ77filename, buffersize);
	strcat(LZ77filename, ".LZ77" );     				// ...we add the (dot)LZ77 to the end of it.

	afile = fileOpener(WRITE, LZ77filename);
	if (afile == NULL)
		printf("\tCannot save LZ77 encoded file. Error opening file.\n");
	else
	{													// the first line is a comment line, the second has width, the third has height
		fprintf(afile, "# cs4481a - Assignment 3 - LZ77 encoding. %s - First line title, second width, third height, then ASCII integer data\n", LZ77filename);
		fprintf(afile, "%d\n%d\n", pgmImage.width, pgmImage.height);

		int i;
		for (i=0; i < LZ77; i++)
			fprintf(afile, "%d\n", LZ77array[i]);

		fclose(afile);
		printf("\tEncoded file: %s\n",LZ77filename);
	}




	free_PGM_Image(&pgmImage);							// un-malloc
}

void decode(){
		
		printf("\n");
		
		FILE * afile = fileOpener(READ, filename);
		if (afile == NULL)
		{	printf("\tCannot open LZ77 commpressed file: %s\n", filename);
		exit(3);
		}
		else
		{
				width = geti(afile); 			// this is line 2
				height = geti(afile);			// this is line 3
				
				printf("\tLZ77 file shows image %dW x %dH\n",width, height);
				// now read into buffer until EOF marker...
				LZ77 = 0;						
				decodeLZ77array[LZ77] = 0;
				while (true || (LZ77 > 999999))
				{	decodeLZ77array[LZ77] = geti(afile);
				if (decodeLZ77array[LZ77] == 16383) break;
				LZ77++;
				}
				fclose(afile);
				printf("\tLZ77 codes read in: %d \n", LZ77);
		}
		
		
		
		
		// - - - - allocate PGM buffer for size read in - - - -
		
		if (0 != create_PGM_Image(&pgmImage, width, height, 255))	// problem with malloc
		{
				printf("\tError creating PGM Image buffer.\n");
				exit(2);
		}
		printf("\tCreating image buffer size for %dW x %dH\n",width, height);
		
		
		
		
		
		// - - - - now, decode what was read in - - - -
		
		printf("\tLZ77 Decoding...\n");
		clock_t clock1 = clock();
		
		
		int offset = 0;								// current offset into PGM image (WHERE TO SAVE next)
		int p = 0;									// pointer to LZ77 array		
		
		while (p < LZ77)
		{
				if (decodeLZ77array[p] < 256)					// it is a literal color..save it
				{	putcolor(&pgmImage, offset++, (unsigned char)(decodeLZ77array[p] & 255));
				p++;
				}
				else
				{										// here, must be a backwards reference
				int pos = decodeLZ77array[p++] & 8191;	// starting reference
				int len = decodeLZ77array[p++];			// how many
				int i;
				for (i = 0; i < len; i++)			// copy this many from offset-pos forwards
				{	putcolor(&pgmImage, offset, getcolor(&pgmImage, offset - pos));
				offset++;
				}
				}
		}
		
		printf("\tElapsed Time (sec): %f\n", ((float)(clock() - (float)clock1) / CLOCKS_PER_SEC) );
		
		
		
		
		
		// - - - - Load the original and compare pixel by pixel - - - -
		
		if (0 != load_PGM_Image(&origpgmImage, originalFilename))				// problem with loading original PGM file
				printf("\tError loading original PGM Image file.  There will be no comparison made\n");
		else
		{
				printf("\tOriginal PGM file read successfully: %s\n", filename);
				
				printf("\tOriginal Image is %d x %d\n", origpgmImage.width, origpgmImage.height);
				printf("\tThe LZ77 Image is %d x %d\n",     pgmImage.width,     pgmImage.height);
				
				printf("\tWidth  match test: "); if (pgmImage.width  == origpgmImage.width)  printf("PASS\n"); else printf("FAIL\n");
				printf("\tHeight match test: "); if (pgmImage.height == origpgmImage.height) printf("PASS\n"); else printf("FAIL\n");
				
				printf("\tPixel color match test: ");
				
				int x, y, count=0;
				for (y=0; y < pgmImage.height; y++)
						for (x=0; x < pgmImage.width;  x++)
								if (pgmImage.image[y][x] != origpgmImage.image[y][x])
										printf("\n\tMismatch %d at x=%d, y=%d, orig color=%d, LZ77 color=%d", ++count, x, y, origpgmImage.image[y][x], pgmImage.image[y][x]);
								
								if (count == 0) printf(" PASS\n"); else printf("\n FAIL\n");
								
								free_PGM_Image(&origpgmImage);				// un-malloc	
		}
		
		
		char decodedname[256];
		strcpy(decodedname, "");
		strcat(decodedname, "decoded_");
		strcat(decodedname, originalFilename);
		
		if (0 != save_PGM_Image(&pgmImage, decodedname, true))	// problem with saving
				printf("        ...Error saving conversion PGM Image to file %s.\n", filename);
		
		printf("\n");
		free_PGM_Image(&pgmImage);						// un-malloc
}


int main(int argc, char** argv){
		
		int commandFormat = 0;
		int i;
		for (i = 1; i < argc; i++) 
		{
				
				
				if (strcmp(argv[i], "-e") == 0){
						if(argc!=4){
								printf("\tInvalid Arguments.\n");
								printf("\t\tFirst argument: -d or -e to either decode or encode.\n");
								printf("\t\tSecond argument: Search Buffer Size. A number between 1 and %d.\n", max_search_buffer_size);
								printf("\t\tthird argument: The PGM file to read in and encode.\n");
								printf("\t\tThe output encoded file has the same name with a (dot).LZ77 suffix added to the filename.\n");
								exit(1);
						}
						
						search_buffer_size = atoi(argv[2]);
						
						if ((search_buffer_size < 1) || (search_buffer_size > max_search_buffer_size))
						{
								printf("Error specifying search buffer size. It can only be between 1 and %d\n", max_search_buffer_size);
								exit(2);
						}
						
						printf("\n\tSearch buffer size is %d.\n", search_buffer_size);
						
						strcpy(filename, argv[3]);
						
						encode();
						commandFormat++;
				}
				else if(strcmp(argv[i], "-d") == 0){
						
						if (argc != 4)
						{
								printf("\tThis program requires two arguments.\n");
								printf("\t\tFirst argument: -d or -e to either decode or encode.\n"); 
								printf("\t\tSecond  argument: The LZ77 encoded PGM file to read in and decode.\n");
								printf("\t\tThird argument: The original PGM file to read in and perform a binary compare.\n");
								exit(1);
						}
						
						strcpy(filename, argv[2]);
						strcpy(originalFilename, argv[3]);
						
						decode();
						commandFormat++;
				}
				
				
						
		}
		
		if(commandFormat == 0){
				printf("\tInvalid Arguments.\n");
				printf("\t\tFirst argument: -d or -e to either decode or encode.\n");
				printf("\t\tIf Encoding (-e)\n");
				printf("\t\t\tSecond argument: Search Buffer Size. A number between 1 and %d.\n", max_search_buffer_size);
				printf("\t\t\tThird argument: The PGM file to read in and encode.\n");
				printf("\t\t\tThe output encoded file has the same name with a (dot).LZ77 suffix added to the filename.\n");
				printf("\t\tIf Decoding (-d)\n");
				printf("\t\t\tSecond argument: The LZ77 encoded PGM file to read in and decode.\n");
				printf("\t\t\tThird argument: The original PGM file to read in and perform a binary compare.\n");
				
		}
		

	printf("\n");

	return 0;
}
