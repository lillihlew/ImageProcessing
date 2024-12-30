
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


/* flip is a procedure that takes a picture and pixel by pixel flips said picture using a nested for loop to flip the pixels in every row of every column
inputs: Any poiter of a picture 
outputs: nothing */
void
flip (Picture * pic)
{  
  // this is our decloration of all the variables we use to make pixels a and b later on
  unsigned char Red_a, Green_a, Blue_a, Red_b, Green_b, Blue_b;

  // this is a nested for loop to flip the pixels
  for(int col = 0; col < pic->width; col++){
    for(int row = 0; row < ((pic->height) / 2); row++)
    {
      // these are all the declarations required to create pixels a and b
      Red_a = pic->pix_array[row][col].R;
      Green_a = pic->pix_array[row][col].G;
      Blue_a = pic->pix_array[row][col].B;

      Pixel a = {Red_a, Green_a, Blue_a};
  
      Red_b = pic->pix_array[(pic->height) - row][col].R;
      Green_b = pic->pix_array[(pic->height) - row][col].G;
      Blue_b = pic->pix_array[(pic->height) - row][col].B;

      Pixel b = {Red_b, Green_b, Blue_b};

      // The actual flipping of the pixels   
      Pixel temp = a;
      a = b;
      b = temp;

      // assigning our flipped pixels to there new locations
      pic->pix_array[row][col]= a;
      pic->pix_array[(pic->height) - row][col] = b;
      
    }}
}



/* main is a procedure that connects to a scribler robot, takes and displayes a photo then calls our flip function,
   and displays the photo again, after the flip has been made, then disconects from the scribler robot
   inputs: none
   outputs: none */   
int
main()
{
  rConnect("/dev/rfcomm0");//connecting to robot
  Picture our_pic = rTakePicture();//taking photo
  rDisplayPicture(&our_pic, 5.0, "Our Picture");//displaying photo
  flip(&our_pic);//flipping photo
  rDisplayPicture(&our_pic, 5.0, "Our Picture flipped");//displaying newly flipped photo
  rDisconnect();//disconnecting from robot


  // This was us first testing to just make sure we could flip a simple array, then we applied the same logic to flipping our picture
  /*int arr[5][7]= {{1, 2, 3, 4, 5, 6, 7}, {8, 9, 10, 11, 12, 13, 14}, {15, 16, 17, 18, 19, 20, 21}, {22, 23, 24, 25, 26, 27, 28}, {29, 30, 31, 32, 33, 34, 35}};

  int a, b, temp;
  for(int i = 0; i<2; i++){
    for(int j = 0; j<7; j++){
      a = arr[i][j];
      b = arr[5-i][j];
      temp = a;
      a = b;
      b = temp;
      arr[i][j] = a;
      arr[5-i][j] = b;
      
    }
  }

  for(int i = 0; i<5; i++){
    for(int j = 0; j<7; j++){
      printf("%5d", arr[i][j]);
    }
    printf("\n");
  }
  */
  return 0;
}
