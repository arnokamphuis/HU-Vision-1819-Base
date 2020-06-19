#include "StudentPreProcessing.h"
#include "EdgeDetection.h"
#include <iostream>
#include "Thresholding.h"

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

	//Canny
	ed::matrix<int, 9, 9> edge_kernel({ {
	{0,0,0,1,1,1,0,0,0},
	{0,0,0,1,1,1,0,0,0},
	{0,0,0,1,1,1,0,0,0},
	{1,1,1,-4,-4,-4,1,1,1},
	{1,1,1,-4,-4,-4,1,1,1},
	{1,1,1,-4,-4,-4,1,1,1},
	{0,0,0,1,1,1,0,0,0},
	{0,0,0,1,1,1,0,0,0},
	{0,0,0,1,1,1,0,0,0}
} });


	//This would be the image.
	ed::matrix<int> im(image);

	//use the canny kernel for the first step.
	im = ed::convolution<int>(im, edge_kernel);

	//Shrink / Expand values in the given range.
	//im.equalization(255);

	//Use canny thresholding to complete step 2.
	tr::basic_threshold<int>(im, 155);

	//Return
	return im.get_intensity_image_ptr();
}

IntensityImage * StudentPreProcessing::stepThresholding(const IntensityImage &image) const { // aanpassen
	//Will explain soon.
	IntensityImage * img_ptr = ImageFactory::newIntensityImage();
	img_ptr->set(image.getWidth(), image.getHeight());
	for (int y = 0; y < image.getHeight(); y++) {
		for (int x = 0; x < image.getWidth(); x++) {
			img_ptr->setPixel(x, y, image.getPixel(x, y));
		}
	}
	return img_ptr;
}