#include "funcs.h"
#include "imageio.h"
#include <iostream>

int main() 
{
  int image[MAX_H][MAX_W];
  std::cout << "All images read the image found in inImage.pgm" << "\n";

  //Task A
  invert_color("inImage.pgm", image);

  //Task B
  invert_half("inImage.pgm", image);

  //Task C
  white_box("inImage.pgm", image);

  //Task D
  image_frame("inImage.pgm", image);

  //Task E
  image_scale("inImage.pgm", image);

  //Task F
  image_pixelate("inImage.pgm", image);

  return 0;
}