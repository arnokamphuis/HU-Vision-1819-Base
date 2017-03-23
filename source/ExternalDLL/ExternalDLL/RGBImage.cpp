/*
* Copyright (c) 2015 DottedEye Designs, Alexander Hustinx, NeoTech Software, Rolf Smit - All Rights Reserved
* Unauthorized copying of this file, via any medium is strictly prohibited
* Proprietary and confidential
*/

#include "RGBImage.h"
#include "IntensityImageStudent.h"

RGBImage::RGBImage() : Image() {
}

RGBImage::RGBImage(const int width, const int height) : Image(width, height) {
}

RGBImage::~RGBImage() {
}

void RGBImage::set(const int width, const int height) {
	Image::set(width, height);
}

IntensityImage& RGBImage::toGrayScale() {
	// these values are from a paper about grayscale algorithms for face detecting:
	// https://www.researchgate.net/publication/232627417_On_conversion_from_color_to_gray-scale_images_for_face_detection
	static const double alpha = 0.4331;
	static const double beta = 0.3147;
	static const double gamma = 0.2523;

	IntensityImage* image = new IntensityImageStudent(this->getWidth(), this->getHeight());

	int numPixels = this->getWidth() * this->getHeight();

	for (int i = 0; i < numPixels; i++) {
		RGB rgbValue = this->getPixel(i);

		image->setPixel(i, (Intensity)((rgbValue.r * alpha) + (rgbValue.g * beta) + (rgbValue.b * gamma)));
	}

	return *image;
}