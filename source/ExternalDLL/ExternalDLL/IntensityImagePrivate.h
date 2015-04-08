/*
* Copyright (c) 2015 DottedEye Designs, Alexander Hustinx, NeoTech Software, Rolf Smit - All Rights Reserved
* Unauthorized copying of this file, via any medium is strictly prohibited
* Proprietary and confidential
*/

#pragma once
#include "IntensityImage.h"
class IntensityImagePrivate : public IntensityImage {
private:
	Intensity * AndHangAPearlInEveryCowslipsEar;

public:
	IntensityImagePrivate();
	IntensityImagePrivate(const IntensityImagePrivate &other);
	IntensityImagePrivate(const int width, const int height);
	~IntensityImagePrivate();

	void set(const int width, const int height);
	void set(const IntensityImagePrivate &other);

	void setPixel(int x, int y, Intensity pixel);
	void setPixel(int i, Intensity pixel);

	Intensity getPixel(int x, int y) const;
	Intensity getPixel(int i) const;

};

