#include <cassert>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iostream>

#include "funcs.h"
#include "imageio.h"

// TASK A -- invert the colors (works)

void invert_color(std::string filename, int imgage[MAX_H][MAX_W]) 
{
  int h, w;
  int imageFin[MAX_H][MAX_W];
  readImage(filename, imgage, h, w);

  for (int row = 0; row < h; row++) 
  {
    for (int col = 0; col < w; col++) 
    {
      imageFin[row][col] = (255 - imgage[row][col]);
    }
  }
  writeImage("taskA.pgm", imageFin, h, w);
}

// TASK B -- invert second half of the image (works)

void invert_half(std::string filename, int image[MAX_H][MAX_W]) 
{
  int h, w;
  int imageFin[MAX_H][MAX_W];
  readImage(filename, image, h, w);

  for (int row = 0; row < h; row++) 
  {
    for (int col = 0; col < w; col++) 
    {
      if (col >= w / 2) 
      {
        imageFin[row][col] = (255 - image[row][col]);
      } 
      else 
      {
        imageFin[row][col] = image[row][col];
      }
    }
  }
  writeImage("taskB.pgm", imageFin, h, w);
}

//TASK C -- draw a 50% by 50% white box in the center (works)

void white_box(std::string filename, int image[MAX_H][MAX_W]) 
{
  int h, w;
  int imageFin[MAX_H][MAX_W];
  readImage(filename, image, h, w);
  
  for (int row = 0; row < h; row++) 
  {
    for (int col = 0; col < w; col++) 
    {
      if (col > (w / 4) && col < (3 * w / 4) && row > (h / 4) &&
          row < (3 * h / 4))
      {
        imageFin[row][col] = 255; 
      }
      else
      {
        imageFin[row][col] = image[row][col];
      }
    }
  }
  writeImage("taskC.pgm", imageFin, h, w);
}

//TASK D -- print a one pixel thick white frame (works)

void image_frame(std::string filename, int image[MAX_H][MAX_W]) 
{
  int h, w;
  int imageFin[MAX_H][MAX_W];
  readImage(filename, image, h, w);
  
  for (int row = 0; row < h; row++) 
  {
    for (int col = 0; col < w; col++) 
    {
      if (col>=(w/4) && col<=(3*w/4) && row>=(h/4) && row<=(3*h/4) && (col == w/4 || col == 3*w/4 || row == h/4 || row == 3*h/4)) 
      {
        imageFin[row][col] = 255; 
      }
      else
      {
        imageFin[row][col] = image[row][col];
      }
    }
  }
  writeImage("taskD.pgm", imageFin, h, w);
}

//TASK E -- scale the image by 200% by putting array colors in a 2x2 (works)

void image_scale(std::string filename, int image[MAX_H][MAX_W])
{
  int h, w;
  int imageFin[MAX_H][MAX_W];
  readImage(filename, image, h, w);
  
  for(int row = 0; row < h; row++)
  {
    for(int col = 0; col < w; col++)
      {
        imageFin[row*2][col*2] = image[row][col];
        imageFin[row*2][col*2+1] = image[row][col];
        imageFin[row*2+1][col*2] = image[row][col];
        imageFin[row*2+1][col*2+1] = image[row][col];
      }
  }
  writeImage("taskE.pgm", imageFin, 2*h, 2*w);
}

//Task F -- pixelate the image (works)

void image_pixelate(std::string filename, int image[MAX_H][MAX_W])
{
  int h, w;
  int imageFin[MAX_H][MAX_W];
  int average;
  readImage(filename, image, h, w);

  //skips by 2
  for(int row = 0; row < h; row+=2)
  {
    for(int col = 0; col < w; col+=2)
      {
        average = (image[row][col]+image[row][col+1] + image[row+1][col] + image[row+1][col+1]) / 4; // taking the average of 2x2
        imageFin[row][col] = average;
        imageFin[row][col+1] = average;
        imageFin[row+1][col] = average;
        imageFin[row+1][col+1] = average;
      }
  }
  writeImage("taskF.pgm", imageFin, h, w);
}
