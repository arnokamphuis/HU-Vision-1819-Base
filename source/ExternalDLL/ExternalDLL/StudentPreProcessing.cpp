#include "StudentPreProcessing.h"

IntensityImage * StudentPreProcessing::stepToIntensityImage(const RGBImage &image) const {
	int w = image.getWidth();
	int h = image.getHeight();

	IntensityImageStudent* intensityImage = new IntensityImageStudent(w, h);

	for (int x = 0; x < w; x++) {
		for (int y = 0; y < h; y++) {
			intensityImage->setPixel(x, y, image.getPixel(x, y));
		}
	}

	return intensityImage;
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