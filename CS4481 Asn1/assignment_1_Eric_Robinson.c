#include <stdlib.h>
#include <string.h>
#include "libpnm.h"

/********************************
 Constants something
 ********************************/

struct PBM_Image pbmImage;	
struct PGM_Image pgmImage;
struct PPM_Image ppmImage;


int w, h;					// dimensions of image
bool ar;					// FALSE=Ascii or TRUE=Raw when saving PBM
char filename[1024];
int x, y;
int color;

//enum Color {RED = 0, GREEN, BLUE};
char *colorLetter[] = {"R","G", "B"};

float c=255.0;				// color per loop. It's a float to spread out evenly.	
float m;					// calculated slope
float s;					// Color change steping

int max;					// max across for bottom corner triangles



/********************************
 This function contains the logic
 for drawing the ppm color image
 ********************************/

int CreatePPMImage(){
	
	
	
	for   (x = 0; x < w; x++)			// fill whole image white first. Default is unknown
		for  (y = 0; y < h; y++)
			for (color = RED; color <= BLUE; color++)
				ppmImage.image[y][x][color] = 255;	// set all colors to max (white)
	
	
	
	
	
	// Red Top half fading to white
	s = 255.0 / (h/2) ;					// G and B color steping per y loop, 2 times faster.
	c = 0.0;							// G and B at 0%, Red at 100%
	for (y = 0; y < h/2; y++)			// top to half way down
	{
		for (x = 0; x < w/3; x++)			// do one line of color
		{
			ppmImage.image[y][x][GREEN] = (unsigned char)c;
			ppmImage.image[y][x][BLUE] = (unsigned char)c;
		}
		
		for (x = w/3; x < w/3 * 2; x++)			// do one line of color
		{
			ppmImage.image[y][x][RED] = (unsigned char)(255 - c);
			ppmImage.image[y][x][BLUE] = (unsigned char)(255 - c);
		}
		
		for (x = w/3 * 2; x < w; x++)			// do one line of color
		{
			ppmImage.image[y][x][RED] = (unsigned char)c;
			ppmImage.image[y][x][GREEN] = (unsigned char)c;
		}
		
		c += s;							// step color towards 100%
		if (c > 255.0) c=255.0;			// insurance
	}
	
	
	
	
	c = 0.0;
	// G and B at 0%, Red at 100%
	for (y = h/2; y < h; y++)			// top to half way down
	{
		
		for (x = 0; x < w/2; x++)			// do one line of color
		{
			ppmImage.image[y][x][GREEN] = (unsigned char)c;
			ppmImage.image[y][x][BLUE] = (unsigned char)c;
			ppmImage.image[y][x][RED] = (unsigned char)c;
		}
		
		for (x = w/2; x < w; x++)			// do one line of color
		{
			ppmImage.image[y][x][RED] = (unsigned char)(255 - c);
			ppmImage.image[y][x][BLUE] = (unsigned char)(255 - c);
			ppmImage.image[y][x][GREEN] = (unsigned char)(255 - c);
		}
		
		
		
		c += s;							// step color towards 100%
		if (c > 255.0) c=255.0;			// insurance
	}
	
	
	
	
	
	return 0;
}

int CreatePGMImage(){
	
	// now...create a white rectangle in the inner half of the height and width
	// It will be drawn as concentric rectangles from the outside in changing
	// color slowly to full black in the inner-most square.
 	int i;						// temp loop
	
	for  (x = 0; x < w; x++)			// set image black first.  Default is unknown
		for (y = 0; y < h; y++)
			pgmImage.image[y][x] = 0;		// set all black.
	// Note: Pixels are [y][x]  The Y is first.
	
	
	
	// white square... in the middle...
	for  (x = w/4; x < (w*3/4); x++)	// horizontally from 1/4 to 3/4 across
		for (y = h/4; y < (h*3/4); y++)	// vertically   from 1/4 to 3/4 across
			pgmImage.image[y][x] = 255;		// white pixel
	
	
	
	
	m = (float)((h*3/4) - (h/4)) / (float)((w*3/4) - (w/4));	// calc slope Y-Y1 over X-X1
	
	if (m <= 1.0)								// loop over x if m <= 1
	{
		s = 255.0 / w * 4.0;					// color steping per x loop, 4 times faster.
		
		for (x = w/4; x <= (w/2); x++)			// loop from corner to center along x
		{
			y = m * x;
			
			for (i = x; i <= w-x; i++)			
			{
				pgmImage.image[  y][i] = (unsigned char)c;	// top h line
				pgmImage.image[h-y][i] = (unsigned char)c;	// bottom h line
			}  
			
			for (i = y; i <= h-y; i++)
			{
				pgmImage.image[i][  x] = (unsigned char)c;	// left v line
				pgmImage.image[i][w-x] = (unsigned char)c;	// right v line
			}  
			
			c -= s;								// step color towards zero (black)
			if (c < 0.0) c=0.0;					// insurance (should not happen)
		}
	}
	else										// loop over y if m > 1
	{
		s = 255.0 / h * 4.0;					// color steping per x loop, 4 times faster.
		
		for (y = h/4; y <= (h/2); y++)			// loop over y if m > 1
		{
			x =  y/m;
			
			for (i = x; i <= w-x; i++)			
			{
				pgmImage.image[  y][i] = (unsigned char)c;	// top h line
				pgmImage.image[h-y][i] = (unsigned char)c;	// bottom h line
			}  
			
			for (i = y; i <= h-y; i++)
			{
				pgmImage.image[i][  x] = (unsigned char)c;	// left v line
				pgmImage.image[i][w-x] = (unsigned char)c;	// right v line
			}  
			
			c -= s;								// step color towards zero (black)
			if (c < 0.0) c=0.0;					// insurance (should not happen)
			
		}
	}
	
	return 0;
}

int CreatePBMImage(){
	
	
	
	
	
	// now...create a white rectangle in the inner half of the height and width
	
	for  (x = 0; x < w; x++)			// set image black first.  Default is white.
		for (y = 0; y < h; y++)
			pbmImage.image[y][x] = 1;		// set all black.
	// Note: Pixels are [y][x]  The Y is first.
	
	
	
	// white square... in the middle...
	for  (x = w/4; x < (w*3/4); x++)	// horizontally from 1/4 to 3/4 across
		for (y = h/4; y < (h*3/4); y++)	// vertically   from 1/4 to 3/4 across
			pbmImage.image[y][x] = 0;		// white pixel
	
	
	
	m = (float)((h*3/4) - (h/4)) / (float)((w*3/4) - (w/4));	// calc slope Y-Y1 over X-X1
	
	if (m <= 1.0)								// loop over x if m <= 1
		for (x = w/4; x <= (w/2); x++)
		{
			y = m * x;
			
			pbmImage.image[  y][  x] = 1;			// 4 black pixels, repeat for symmetry
			pbmImage.image[  y][w-x] = 1;
			pbmImage.image[h-y][  x] = 1;
			pbmImage.image[h-y][w-x] = 1;
		}
	else
		for (y = h/4; y <= (h/2); y++)				// loop over y if m > 1
		{
			x =  y/m;
			
			pbmImage.image[  y][  x] = 1;			// black pixels, repeat for symmetry
			pbmImage.image[  y][w-x] = 1;
			pbmImage.image[h-y][  x] = 1;
			pbmImage.image[h-y][w-x] = 1;
		}
	
	
	return 0;
	
}

int main(int argc, char** argv)
{
	
    
	char imageType[3];
	
	
	if (argc != 6)
	{
		printf("\tThis program requires five arguments...\n");
		printf("\tFirst argument: Image type (i.e., pbm, pgm, ppm)\n");
		printf("\tFirst  argument: Width  of PBM image.  A number multiple of 4\n");
		printf("\tSecond argument: Height of PBM image.  A number multiple of 4\n");
		printf("\tThird  argument: Filename of image to save as\n");
		printf("\tFourth argument: The character 'A' or 'R': Image saved as PBM-'A'SCII or PBM-'R'aw\n");
		return 1;
	}
	
	strcpy(filename, argv[4]);	
	
	switch (argv[5][0])
	{
	 	case 'A':
		case 'a':		ar = false;	break;
			
		case 'R':
		case 'r':		ar = true;	break;
			
		default:		printf("Error: The character 'A' or 'R' is only allowed for saving the image: A=PBM-ASCII, R=PBM-RAW.\n");
			return 1;
	}
	
	
	strcpy(imageType, argv[1]);
	
	if(!strcmp(imageType, "ppm")){
		printf("\tppm image\n");
		w = atoi(argv[2]);								// test Width from user
		if ((w < 6) || (w % 6 != 0)){
			printf("\tError: Width must be a multiple of 6\n");
			return 1;
		}
		
		h = atoi(argv[3]);								// test Height from user
		if ((h < 6) || (h % 6 != 0))
		{
			printf("\tError: Height must be a multiple of 6\n");
			return 1;
		}
		
		if (0 != create_PPM_Image(&ppmImage, w, h, 255))		// problem with malloc
		{
			printf("Error creating PPM Image buffer.\n");
			return 1;
		}
		printf("Creating PPM image buffer size %dW x %dH\n",w, h);
		
		if (0 != create_PGM_Image(&pgmImage, w, h, 255))		// problem with malloc
		{
			printf("Error creating PGM Image buffer.\n");
			free_PPM_Image(&ppmImage);							// un-malloc the PPM malloc
			return 1;
		}
		printf("Creating PGM image buffer size %dW x %dH\n",w, h);
		
		CreatePPMImage();
		
		// ===== PART 3B: Convert to one grey image using 'convert_PPM_to_PGM'
		
		printf("\nPart 3A...Convert PPM to PGM...\n");
		
		char name[1024];
		strcpy(name, argv[4]);
		strcat(name, ".ppm");
		
		if (0 != save_PPM_Image(&ppmImage, name, ar))	// problem with saving
			printf("        ...Error saving PPM Image to file %s.\n", name);
		
		
		if (ar) printf("PPM RAW "); else printf("PPM ASCII ");
		printf("If no problem, Image saved as filename: %s\n", name);
		
		
		
		
		
		
		
		
		
		// ===== PART 3C: Convert to three grey image using 'copy_PPM_to_PGM'
		//                (One for each of R, G, B)
		
		printf("\nPart 3C...Copy PPM to PGM...\n");
		
		
		for(color = RED; color <= BLUE; color++)
		{
			printf("Converting %s...",colorLetter[color]);
			
			if (0 != copy_PPM_to_PGM(&ppmImage, &pgmImage, color))
				printf("        ...Error in conversion.\n");
			else
			{
				
				strcpy(filename, argv[4]);							// append the argv[4] filename with...
				//strcat(filename, ".");								// a dot
				strcat(filename, colorLetter[color]);				// and  the Letter R, G, B
				strcat(filename, "copy2PGM");
				strcat(filename, ".pgm");						// ...and this text to make a complete suffix
				
				if (0 != save_PGM_Image(&pgmImage, filename, ar))	// problem with saving
					printf("        ...Error saving conversion PGM Image to file %s.\n", filename);
				
				if (ar) printf("to PGM RAW "); else printf("to PGM ASCII ");
				printf("\n        If no problem, Part 3C Converted Image saved as filename: %s\n", filename);
			}
		}// all 3 colors
		
		
		
		
		
		
		
		
		
		
		
		
		
		free_PPM_Image(&ppmImage);							// un-malloc
		free_PGM_Image(&pgmImage);							// un-malloc
		
		
    } 
	
	if(!strcmp(imageType, "pgm")){
		printf("\tpgm image\n");
		w = atoi(argv[2]);								// test Width from user
		if ((w < 4) || (w % 4 != 0)){
			printf("\tError: Width must be a multiple of 4\n");
			return 1;
		}
		
		h = atoi(argv[3]);								// test Height from user
		if ((h < 4) || (h % 4 != 0))
		{
			printf("\tError: Height must be a multiple of 4\n");
			return 1;
		}
		
		if (0 != create_PGM_Image(&pgmImage, w, h, 255))		// problem with malloc
		{
			printf("Error creating PGM Image buffer.\n");
			return 1;
		}
		printf("Creating image buffer size %dW x %dH\n",w, h);
		
		CreatePGMImage();
		
		strcpy(filename, argv[4]);	
		strcat(filename, ".pgm");
		
		if (0 != save_PGM_Image(&pgmImage, filename, ar))	// problem with saving
			printf("Error saving PGM Image to file.\n");
		
		if (ar) printf("PGM RAW "); else printf("PGM ASCII ");
		printf("If no problems, Image saved as filename: %s\n", filename);
		
		free_PGM_Image(&pgmImage);							// un-malloc
		
    } 
	
	if(!strcmp(imageType, "pbm")){
		printf("\tpbm image\n");
		
		w = atoi(argv[2]);								// test Width from user
		if ((w < 4) || (w % 4 != 0)){
			printf("\tError: Width must be a multiple of 4\n");
			return 1;
		}
		
		h = atoi(argv[3]);								// test Height from user
		if ((h < 4) || (h % 4 != 0))
		{
			printf("\tError: Height must be a multiple of 4\n");
			return 1;
		}
		
		
		if (0 != create_PBM_Image(&pbmImage, w, h))		// problem with malloc
		{
			printf("\tError creating PBM Image buffer.\n");
			return 1;
		}
		printf("\tCreating image buffer size %dW x %dH\n",w, h);
		
		CreatePBMImage();
		
		strcpy(filename, argv[4]);	
		strcat(filename, ".pbm");
		
		if (0 != save_PBM_Image(&pbmImage, filename, ar))	// problem with saving
	 		printf("\tError saving PBM Image to file.\n");
		
		if (ar) printf("\tPBM RAW "); else printf("\tPBM ASCII ");
		printf("\tIf no problems, Image saved as filename: %s\n", filename);
		
		free_PBM_Image(&pbmImage);							// un-malloc
    } 
	
	return 0;
}
