#include "StudentPreProcessing.h"
#include "EdgeDetection.h"
#include <iostream>
#include "ImageIO.h"
#include "GrayscaleAlgorithm.h"
#include "ImageFactory.h"
#include "HereBeDragons.h"

IntensityImage * StudentPreProcessing::stepToIntensityImage(const RGBImage &image) const {
	return nullptr;
}

IntensityImage * StudentPreProcessing::stepScaleImage(const IntensityImage &image) const {
	return nullptr;
}

IntensityImage * StudentPreProcessing::stepEdgeDetection(const IntensityImage &image) const { // aanpassen
	ed::matrix<250,250> m(image);
	ed::matrix<9, 9> kernel({ {
	{0,0,0,1,1,1,0,0,0},
	{0,0,0,1,1,1,0,0,0},
	{0,0,0,1,1,1,0,0,0},
	{1,1,1,-5,-5,-5,1,1,1},
	{1,1,1,-5,-5,-5,1,1,1},
	{1,1,1,-5,-5,-5,1,1,1},
	{0,0,0,1,1,1,0,0,0},
	{0,0,0,1,1,1,0,0,0},
	{0,0,0,1,1,1,0,0,0}
} });

	auto convulutioned = ed::convolution(m, kernel);

	for (unsigned int i = 0; i < image.getHeight(); i++) {
		for (unsigned int j = 0; j < image.getWidth(); j++) {

			auto x = m[i][j];
			uint8_t num = 0;
			for (unsigned int i = 0; i < 8; i++) {
				((x >> i) & 0b1) ? num += pow(2, i) : num += 0;
			}
			std::cout << ((int)num < 220) ? 1 : 0;
		}
		std::cout << std::endl;
	}

	for (unsigned int i = 0; i < image.getHeight(); i++) {
		for (unsigned int j = 0; j < image.getWidth(); j++) {

			auto x = convulutioned[i][j];
			uint8_t num = 0;
			for (unsigned int i = 0; i < 8; i++) {
				((x >> i) & 0b1) ? num += pow(2, i) : num += 0;
			}
			std::cout << ((int)num < 220)?1:0 ;
		}
		std::cout << '\n';
	}
	return convulutioned.get_intensity_image_ptr();
}

IntensityImage * StudentPreProcessing::stepThresholding(const IntensityImage &image) const { // aanpassen
	// TODO: apply 5x5 gaussian kernel, afer that apply Otsu thresholding.

	// TODO: Image container
	cv::Mat temp_image;

	// TODO: Image container copy function
	HereBeDragons::HerLoveForWhoseDearLoveIRiseAndFall(image, temp_image);

	// TODO: Basic Threshold filter, after use a otsu threshold for better result
	cv::threshold(temp_image, temp_image, 220, 255, cv::THRESH_BINARY);

	IntensityImage * ThoroughBushThoroughBrier = ImageFactory::newIntensityImage();
	HereBeDragons::NoWantOfConscienceHoldItThatICall(temp_image, *ThoroughBushThoroughBrier);
	return ThoroughBushThoroughBrier;
}