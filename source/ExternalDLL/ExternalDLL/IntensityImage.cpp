/*
* Copyright (c) 2015 DottedEye Designs, Alexander Hustinx, NeoTech Software, Rolf Smit - All Rights Reserved
* Unauthorized copying of this file, via any medium is strictly prohibited
* Proprietary and confidential
*/

#include "IntensityImage.h"

IntensityImage::IntensityImage() : Image() {
}

IntensityImage::IntensityImage(int width, int height) : Image(width, height) {
}

IntensityImage::~IntensityImage() {
}

void IntensityImage::set(const int width, const int height) {
	Image::set(width, height);
}