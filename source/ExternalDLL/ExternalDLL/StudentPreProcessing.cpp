#include "StudentPreProcessing.h"
#include "ImageFactory.h"


IntensityImage * StudentPreProcessing::stepToIntensityImage(const RGBImage &image) const {
	return nullptr;
}

IntensityImage * StudentPreProcessing::stepScaleImage(const IntensityImage &image) const {
	return nullptr;
}

IntensityImage * StudentPreProcessing::stepEdgeDetection(const IntensityImage &image) const {
	IntensityImage * edgeDetectionImage = ImageFactory::newIntensityImage(image.getWidth(), image.getHeight());

	for (int i = 0; i < image.getWidth() ; ++i){
		for (int j = 0; j < image.getHeight(); ++j){
			edgeDetectionImage->setPixel(i, j, image.getPixel(i, j));
		}
	}

	//Kernel filter over image, wegschrijven in foto edgeDetectionImage / optioneel, testen met verschillende opties 

	//Kernel parsen (edge detection kernel, sobel, canny) over image, wegschrijven in foto edgeDetectionImage

	return edgeDetectionImage;
	//code voor edge detection hierzo
	
}

IntensityImage * StudentPreProcessing::stepThresholding(const IntensityImage &image) const {
	return nullptr;
}