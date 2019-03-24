#include "StudentPreProcessing.h"
#include <iostream>
IntensityImage * StudentPreProcessing::stepToIntensityImage(const RGBImage &image) const {
	IntensityImage * iImage = ImageFactory::newIntensityImage(image.getWidth(), image.getHeight());
	int imageSize = image.getWidth() * image.getHeight();
	for (int i = 0; i < imageSize; i++) {
		auto RGBPixel = image.getPixel(i);
		int intensity = static_cast<int>(RGBPixel.r * 0.3 + RGBPixel.g * 0.59 + RGBPixel.b * 0.11);
		iImage->setPixel(i, intensity);
	}
	return iImage;
}

IntensityImage * StudentPreProcessing::stepScaleImage(const IntensityImage &image) const {
	return nullptr;
}

IntensityImage * StudentPreProcessing::stepEdgeDetection(const IntensityImage &image) const {
	return nullptr;
}

IntensityImage * StudentPreProcessing::stepThresholding(const IntensityImage &image) const {
	return nullptr;
}