
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
     *     dot lab.                                                        *
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



void find_bright (Picture * pic)
{
   unsigned char Red;
   unsigned char Green;
   unsigned char Blue;
   unsigned char highest = 0;
   int row, col;

   //looping through every pixel in the array
   for(int i = 0; i < pic->height; i++){
     for(int j = 0; j < pic->width; j++){

       /*storing each pixel component as an 
         unsigned char we can access in the next
         piece of the function*/
       Red = pic->pix_array[i][j].R;
       Green = pic->pix_array[i][j].G;
       Blue = pic->pix_array[i][j].B;

       /*RGB, the sum of the three pixel 
         components, will be our measure of 
         brightness */
       unsigned char RGB = Red + Blue + Green;

       
       if (RGB > highest)
         {highest = RGB; //record RGB of brightest pixel
           row = i; //record row of brightest pixel
           col = j;} //record column of brightest pixel
     }
   }
  printf("The location of the brightest pixel is row %d, column %d.\n", row, col);
}
/*Input: pointer to a picture
  Output: void, but prints the location of the brightest 
          pixel in the image */



int main()
{
  rConnect("/dev/rfcomm0");
  Picture our_pic = rTakePicture();
  rDisplayPicture(&our_pic, 5.0, "Our Picture");
  find_bright(&our_pic);
  rDisconnect();
  
  return 0;
}

