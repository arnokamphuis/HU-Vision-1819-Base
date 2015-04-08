/*
* Copyright (c) 2015 DottedEye Designs, Alexander Hustinx, NeoTech Software, Rolf Smit - All Rights Reserved
* Unauthorized copying of this file, via any medium is strictly prohibited
* Proprietary and confidential
*/

#include "RGBImage.h"

RGBImage::RGBImage() : Image() {
}

RGBImage::RGBImage(const int width, const int height) : Image(width, height) {
}

RGBImage::~RGBImage() {
}

void RGBImage::set(const int width, const int height) {
	Image::set(width, height);
}