
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

/* color to grey is a function that takes an image and turns it to greyscale by manipulating the RGB value of each pixel
Inputs: a pointer to a picture
outputs: none */
void
colorToGrey(Picture * pic)
{
  //variable declaration
   unsigned char Red;
   unsigned char Green;
   unsigned char Blue;

//nested for loop will get us each individual pixel in the image
  for(int i = 0; i < pic->height; i++){
    for(int j = 0; j < pic->width; j++){
// this gets the RGB values of pixel [i][j] and sets the variables Red Green and Blue equal to their respective values
      Red = pic->pix_array[i][j].R;
      Green = pic->pix_array[i][j].G;
      Blue = pic->pix_array[i][j].B;
// this is the conversion of the pixel to the value that is "grey"   
  unsigned char grey = (Red *.30) + (Green * .59) + ( Blue * .11);
//this sets the pixels RGB values to be their adjusted grey value.
      pic->pix_array[i][j].R = grey;
      pic->pix_array[i][j].G = grey;
      pic->pix_array[i][j].B = grey;
    }
  }
}

/* set Picture Max is a function that takes an image and amplifies (to the max) the main color of each pixel while setting the other two rgb values for said pixel to zero.
Inputs: a pointer to a picture
outputs: none */
void
setPictureMax (Picture * pic)
{
  //variable declaration
   unsigned char Red;
   unsigned char Green;
   unsigned char Blue;
  
  //nested for loop to manipulate each pixel in the image
  for(int i = 0; i < pic->height; i++){
    for(int j = 0; j < pic->width; j++){
 
  //getting the RGB value of the pixels    
      Red = pic->pix_array[i][j].R;
      Green = pic->pix_array[i][j].G;
      Blue = pic->pix_array[i][j].B;
  
  //this is what sets the new RGB value based on which value is highest
      if (Red > Green && Red > Blue)
        { Red = 135;
          Green = 0;
          Blue = 0;}
      else if (Green > Red && Green > Blue)
        { Green = 135;
          Red = 0;
          Blue = 0;}
       else
         {Blue = 135;
          Red = 0;
          Green = 0;}
  
  //sets the pixel to its new RGB values.  
      pic->pix_array[i][j].R = Red;
      pic->pix_array[i][j].G = Green;
      pic->pix_array[i][j].B = Blue;
    }}}



/* main is a procedure that connects to a Scribbler robot, takes and displays a photo, 
   then spins the robot to take another photo, displays that photo, converts that photo to greyscale, displays the new grey image, 
   then spins and takes a third photo, displays this photo, converts it to the maximum RGB values, and again displays this manipulated photo.
inputs: none
outputs: none */
int
main()
{
  // connecting to robot
  rConnect("/dev/rfcomm0");

  //taking and displaying first photo
  Picture our_pic = rTakePicture();
  rDisplayPicture(&our_pic, 5.0, "Our Picture");
  
  //spinning then taking and displaying second photo
  rTurnLeft(1.0, 1.0);
  Picture gray_pic = rTakePicture();
  rDisplayPicture(&gray_pic, 5.0, "Our Picture Before Gray");

  //converting second photo to greyscale and displaying it
  colorToGrey (&gray_pic);
  rDisplayPicture(&gray_pic, 5.0, "Our Picture in Gray");

  //spinning then taking and displaying third photo
  rTurnLeft(1.0, 1.0);
  Picture max_pic = rTakePicture();
  rDisplayPicture(&max_pic, 5.0, "Our Picture Before Max");

  //converting third photo to max RGB values and displaying it
  setPictureMax(&max_pic);
  rDisplayPicture(&max_pic, 5.0, "Our Picture With Max Values"); 

  //disconnecting from robot
  rDisconnect();
  return 0;
}
