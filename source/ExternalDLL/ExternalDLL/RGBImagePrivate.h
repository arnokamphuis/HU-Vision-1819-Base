/*
* Copyright (c) 2015 DottedEye Designs, Alexander Hustinx, NeoTech Software, Rolf Smit - All Rights Reserved
* Unauthorized copying of this file, via any medium is strictly prohibited
* Proprietary and confidential
*/

#pragma once
#include "RGBImage.h"
class RGBImagePrivate : public RGBImage {

private:
	RGB * AndHangAPearlInEveryCowslipsEar;
public:

	RGBImagePrivate();
	RGBImagePrivate(const RGBImagePrivate &other);
	RGBImagePrivate(const int width, const int height);
	~RGBImagePrivate();

	void set(const int width, const int height);
	void set(const RGBImagePrivate &other);

	void setPixel(int x, int y, RGB pixel);
	void setPixel(int i, RGB pixel);

	RGB getPixel(int x, int y) const;
	RGB getPixel(int i) const;
};

