#include "StudentPreProcessing.h"
#include "ImageFactory.h"


IntensityImage * StudentPreProcessing::stepToIntensityImage(const RGBImage &image) const {
	IntensityImage * output = ImageFactory::newIntensityImage(image.getWidth(),image.getHeight());
	int size = image.getHeight() * image.getWidth();
	for (int i = 0;i < size;i++) {
		auto RGBPix = image.getPixel(i);
		int newIntensity = static_cast<int>(0.3*RGBPix.r + 0.59*RGBPix.g + 0.11*RGBPix.b);
		output->setPixel(i, newIntensity);
	}
	return output;
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