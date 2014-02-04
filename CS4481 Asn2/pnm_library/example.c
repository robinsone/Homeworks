#include "libpnm.h"

/*-------------------------------------------------*/
/* A SIMPLE TEST/EXAMPLE OF HOW TO USE THE LIBRARY */
/*-------------------------------------------------*/
int main() { 

	struct PGM_Image pic1, pic2, pic3, pic4;
	struct PPM_Image pic5;

	load_PPM_Image(&pic5, "peppers.ppm");

	copy_PPM_to_PGM(&pic5, &pic1, RED);
	copy_PPM_to_PGM(&pic5, &pic2, GREEN);
	copy_PPM_to_PGM(&pic5, &pic3, BLUE);
	convert_PPM_to_PGM(&pic5, &pic4);

	save_PGM_Image(&pic1, "peppers.red.raw.pgm", true);
	save_PGM_Image(&pic2, "peppers.green.raw.pgm", true);
	save_PGM_Image(&pic3, "peppers.blue.raw.pgm", true);
	save_PGM_Image(&pic4, "peppers.raw.pgm", true); 

	free_PGM_Image(&pic1);
	free_PGM_Image(&pic2);
	free_PGM_Image(&pic3);
	free_PGM_Image(&pic4);
	free_PPM_Image(&pic5);
      
        return 0;}
