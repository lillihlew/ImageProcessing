    /***********************************************************************
     * Names: Lilli Lewis and John Clewett                                 *
     * Assignment name (Project  Image Processing)                         *
     *                                                                     *
     * Assignment for 4/10/23                                              *
     ***********************************************************************/

    /* *********************************************************************
     * Academic honesty certification:                                     *
     *   Written/online sources used:                                      *
     *     reused some code from Henry Walker's white-picture-with-black-  *   
     *     dot lab and from our pic-experiments lab.                       *
     *   Help obtained                                                     *
     *     none                                                            *
     *   My/our signature(s) below confirms that the above list of sources *
     *   is complete AND that I/we have not talked to anyone else          *
     *   (e.g., CSC 161 students) about the solution to this problem       *
     *                                                                     *
     *   Signature: Lilli Lewis John Clewett                               *
     ***********************************************************************/


#include <stdio.h>
#include <MyroC.h>

void negative_V (Picture * pic)
{  
   unsigned char Red;
   unsigned char Green;
   unsigned char Blue;

   //looping through each pixel
  for(int i = 0; i < pic->height; i++){
    for(int j = 0; j < pic->width; j++){

      /*storing each pixel component as an unsigned 
        char we can call in the next line */
      Red = pic->pix_array[i][j].R;
      Green = pic->pix_array[i][j].G;
      Blue = pic->pix_array[i][j].B;

      /*declaring and storing v as an array of the 
        three color values*/
      int v[3] = {Red, Green, Blue}; 

      /*storing the color values as their inverse: 
        255(max brightness) - their original value, 
        stored in v.*/
      pic->pix_array[i][j].R = 255-v[0];
      pic->pix_array[i][j].G = 255-v[1];
      pic->pix_array[i][j].B = 255-v[2];
    }
  }
}
/*Input: pointers to images
  Output: void, but changes the image to its inverse 
          colors */



int main()
{
  rConnect("/dev/rfcomm0");
  Picture our_pic = rTakePicture();
  rDisplayPicture(&our_pic, 5.0, "Our Picture");
  negative_V(&our_pic);
  rDisplayPicture(&our_pic, 5.0, "Our Picture in negative");
  rDisconnect();
  
  return 0;
}
