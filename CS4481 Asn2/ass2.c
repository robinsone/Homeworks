#include <stdlib.h>
#include "libpnm.h"
#include <string.h>

//variables
long int	pixel_freq[256];		// Subscript 0..255 is for pixel color 0..255 
int		non_zero_freq;			// count of how many non-zero pixels there are
int non_zero_freq;	
int frequencyArray[256][2];
int nodes[256][2];
int codes[256][2];
char filename[1024];

struct PGM_Image pgmImage;




void print2dArray(int arr[256][2], int n){
	int i;
	printf("\n");
	for(i = 0; i < 256; i++){
		if(arr[i][1] > -1){
		printf("\t[%d]:%d   \t[%d]:%d\n", i, arr[i][0], i, arr[i][1]);
		}
	}
	printf("\n");
}

char* itoa(int val, int base){
	
	static char buf[32] = {0};
	
	int i = 30;
	
	for(; val && i ; --i, val /= base)
		
		buf[i] = "0123456789abcdef"[val % base];
	
	return &buf[i+1];
	
}


//Part 1
long int *generate_pixel_frequency(struct PGM_Image * pgmImage, int * number_of_non_zero_pixel_frequencies){
	// INPUT:	This function accepts two parameters:	(1)	input_pgm_image (a pointer to a PGM_Image structure--see pnm_library.tar)
	//													(2) number_of_non_zero_pixel_frequencies (a pointer to an integer) 
	// WORK:	The function reads ALL pixels in the provided PGM image
	//
	// OUTPUT:	(1) Return Value: a pointer to a long integer array of max_gray_value elements which contains the frequency of occurrence of each pixel values.
	//			(2) It will also store the number of non-zero pixel frequencies in *number_of_non_zero_pixel_frequencies.

	int i;
	int row,col;

	for (i = 0; i <= 255; i++)						// reset pixel frequency counts
		pixel_freq[i] = 0;
	
	*number_of_non_zero_pixel_frequencies = 0;		// reset non-zero count

	
	for  (row = 0; row < pgmImage->height; row++)	// scan through image looking at grey values
	for (col = 0; col < pgmImage->width;  col++)	// Note: Pixels are [y][x]  The Y is first.
	{
		i = pgmImage->image[row][col];
		pixel_freq[i]++;							// increment count of this grey-scale color instance
	}


	for (i = 0; i <= 255; i++)							// This is here to run once for each possible pixel, and not (O^2) above IF testing
	if (pixel_freq[i] > 0)
		(*number_of_non_zero_pixel_frequencies)++;	// count non-zero freq counts
													// Note: there may be zero freq counts embedded!

	//	pgmImage->width = geti(imageFilePointer); 
	//  pgmImage->height = geti(imageFilePointer);
	//  pgmImage->maxGrayVal
	//
	//    for(row = 0; row < pgmImage->height; row++)
	//      for(col = 0; col < pgmImage->width; col++)
	//        fprintf(imageFilePointer, "%d ", pgmImage->image[row][col]);


	//printf("Non-zero pixel freq = %d\n",*number_of_non_zero_pixel_frequencies);		//ok: points to global properly
	//printf("%d\n",non_zero_freq);														//ok: correct to above

	return & pixel_freq[0];
}

//part2
void generate_Huffman_nodes(long int *pixel_frequency, int max_gray_value, int number_of_non_zero_pixel_frequencies){
	
	
	int i;
	
	//initiate nodes array
	for(i = 0; i < 256; i++){
		codes[i][0] = 0;
		codes[i][1] = 0;
	}
	
	
	//initiate nodes array
	for(i = 0; i < 256; i++){
		nodes[i][0] = i;
		nodes[i][1] = -1;
	}
	
	//initiate frequency array
	for(i = 0; i < 256; i++){
		frequencyArray[i][0] = i;
		frequencyArray[i][1] = -1;
	}
	
	//find frequencies
	for(i = 0; i < 256; i++){
		if(pixel_freq[i] > 0){
			frequencyArray[i][0] = i;
			frequencyArray[i][1] = pixel_freq[i];
		}
		
	}
	printf("\nfrequencies: ");
	print2dArray(frequencyArray, non_zero_freq);
	
	int tempArray[256][2];
	//fill tempArray
	for(i = 0; i < 256; i++){
		tempArray[i][0] = frequencyArray[i][0];
		tempArray[i][1] = frequencyArray[i][1];
	}
	
	//find Pairs/Nodes
	for(i = 0; i < non_zero_freq - 1; i++){
		int x;
		int first[1][2];
		int second[1][2];
		first[0][1] = pgmImage.width * pgmImage.height;
		second[0][1] = pgmImage.width * pgmImage.height;
		first[0][0] = pgmImage.width * pgmImage.height;
		second[0][0] = pgmImage.width * pgmImage.height;
		
		for(x = 0; x < 256 ; x++){
			if(tempArray[x][1] > -1){
				/*If current element is smaller than first then update both
				first and second */
				if(tempArray[x][1] < first[0][1])
				{
					second[0][1] = first[0][1];
					second[0][0] = first[0][0];
					first[0][1] = tempArray[x][1];
					first[0][0] = tempArray[x][0];
				}
				
				/* If arr[i] is in between first and second then update second  */
				else if (tempArray[x][1] < second[0][1])
				{
					second[0][1] = tempArray[x][1];
					second[0][0] = tempArray[x][0];
				}
			}
		}
		//printf("\t[%d]%d, [%d]%d\n",first[0][0], first[0][1],second[0][0], second[0][1]);
		
		//new node;
		
		tempArray[first[0][0]][1] = first[0][1] + second[0][1];
		tempArray[second[0][0]][1] = -1;
		
		if(first[0][0] < second[0][0]){
			nodes[i][0] = first[0][0];
			nodes[i][1] = second[0][0];
		}else{
			nodes[i][0] = second[0][0];
			nodes[i][1] = first[0][0];
		}
		//counter++;
				
		//printf("\nTempArray: ");
		//print2dArray(tempArray, non_zero_freq);
	}
	
	printf("Nodes/Pairs:");
	print2dArray(nodes, non_zero_freq-1);
	
	//int temp[1][2];
	//int temp2[1][2];
	for(i = non_zero_freq -2; i >= 0 ; i--){
		if(codes[nodes[i][0]][1] > 0){
			codes[nodes[i][1]][0] = codes[nodes[i][1]][0] + codes[nodes[i][0]][0];
			codes[nodes[i][1]][1] = codes[nodes[i][1]][1] + codes[nodes[i][0]][1];
			
		}
		else if(codes[nodes[i][1]][1] > 0){
			codes[nodes[i][0]][0] = codes[nodes[i][0]][0] + codes[nodes[i][1]][0];
			codes[nodes[i][0]][1] = codes[nodes[i][0]][1] + codes[nodes[i][1]][1];
		}
		
		codes[nodes[i][1]][0] = codes[nodes[i][1]][0] << 1;
		
		codes[nodes[i][1]][1] = codes[nodes[i][1]][1] + 1;
		
		codes[nodes[i][0]][0] = codes[nodes[i][0]][0] << 1;
		codes[nodes[i][0]][0] = codes[nodes[i][0]][0] + 1;
		codes[nodes[i][0]][1] = codes[nodes[i][0]][1] + 1;
	}
	
	
	printf("Codes");
	printf("\n");
	for(i = 0; i < 256; i++){
		if(codes[i][1] > 0){
			//itoa (codes[i][0],2);
			printf("\t[%d]:%s   \t[length]:%d\n",i, itoa(codes[i][0],2), codes[i][1]);
		}
	}
	printf("\n");
	
	//encode file. 
	FILE *fp;
	fp=fopen("encodedPGMImage", "wb");
	if (fp == NULL)												// .. problem
	{	printf("Cannot open output file to save DPCM encoded file. Error opening file.\n");
										// un-malloc PGM..no memory leaks
	exit(4);
	}
	//char x[10]="ABCDEFGHIJ";
	//fwrite(x, sizeof(x[0]), sizeof(x)/sizeof(x[0]), fp);
	//char x[pgmImage.width * pgmImage.height];
	unsigned int b = 0;
	unsigned int buffer = 0;
	unsigned char encoding;
	int row, col, color;
	for  (row = 0; row < pgmImage.height; row++){	// scan through image looking at grey values
		for (col = 0; col < pgmImage.width;  col++){
			color = pgmImage.image[row][col];
			//printf("%d, %d\n", row, col);
				b = ((b << codes[color][1]) | codes[color][0]);
				buffer = buffer + codes[color][1];
			if(buffer >= 8){
				encoding = b >> (buffer - 8);
				fwrite(&encoding, sizeof(encoding), 1, fp);
			}
			
		}
	
	}
	
	//printf ("OMG\n");
}



void intro(){
	printf("\t*******************************\n");
	printf("\t*** Eric Robinson - Assign2 ***\n");
	printf("\t*** Student #:    250598791 ***\n");
	printf("\t*** Account:       erobin25 ***\n");
	printf("\t*******************************\n");
}


int main(int argc, char** argv){

	intro();    
	//check cmd line arguments
	if (argc != 2){
		printf("\tThis program requires an arguments...\n");
		printf("\tArgument:\tPGM image you wish to compress\n"); 
		return 1;
	}
	
	char filename[1024];
	strcpy(filename, argv[1]);
	
	//load pgmImage. 
	if(0 != load_PGM_Image(&pgmImage, filename)){
		printf("\tFailed to load PGM Image\n");
		return 1;
	}
	//ok:
	
	//generate frequencies
	(void) generate_pixel_frequency(&pgmImage, &non_zero_freq);
	printf("\tNumber of Colors: %d\n", non_zero_freq);
	
	//generate Nodes
	(void) generate_Huffman_nodes(&pixel_freq[0], 0, non_zero_freq);

return 0;
}
