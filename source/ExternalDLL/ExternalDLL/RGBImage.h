/*
* Copyright (c) 2015 DottedEye Designs, Alexander Hustinx, NeoTech Software, Rolf Smit - All Rights Reserved
* Unauthorized copying of this file, via any medium is strictly prohibited
* Proprietary and confidential
*/

#pragma once
#include "Image.h"
#include "PixelType.h"

class RGBImage: public Image {
public:
	RGBImage();
	RGBImage(const int width, const int height);
	virtual ~RGBImage();

	virtual void set(const int width, const int height) = 0;

	virtual void setPixel(int x, int y, RGB pixel) = 0;
	virtual void setPixel(int i, RGB pixel) = 0;

	virtual RGB getPixel(int x, int y) const = 0;
	virtual RGB getPixel(int i) const = 0;
};