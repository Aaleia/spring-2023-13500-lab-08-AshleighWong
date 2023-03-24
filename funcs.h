#include <iostream>
#include <string>
#include "imageio.h"
#pragma once

void invert_color(std::string filename, int imgage[MAX_H][MAX_W]);

void invert_half(std::string filename, int image[MAX_H][MAX_W]);

void white_box(std::string filename, int image[MAX_H][MAX_W]);

void image_frame(std::string filename, int image[MAX_H][MAX_W]);

void image_scale(std::string filename, int image[MAX_H][MAX_W]);

void image_pixelate(std::string filename, int image[MAX_H][MAX_W]);