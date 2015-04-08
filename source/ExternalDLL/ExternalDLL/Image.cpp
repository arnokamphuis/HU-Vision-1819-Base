/*
* Copyright (c) 2015 DottedEye Designs, Alexander Hustinx, NeoTech Software, Rolf Smit - All Rights Reserved
* Unauthorized copying of this file, via any medium is strictly prohibited
* Proprietary and confidential
*/

#include "Image.h"

Image::Image():
	width(0), height(0) {
}

Image::Image(const int width, const int height):
	width(width), height(height){
}

Image::~Image(){
}

void Image::set(const int width, const int height) {
	this->width = width;
	this->height = height;
}

const int Image::getWidth() const {
	return width;
}

const int Image::getHeight() const {
	return height;
}