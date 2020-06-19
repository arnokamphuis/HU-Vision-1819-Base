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

	ed::matrix<double, 5, 5> gaussian_kernel({ {
		{0.015026,0.015026,0.035391,0.028569,0.015026},
		{ 0.028569,0.054318,0.067288,0.054318,0.028569},
		{0.035391,0.067288,0.083355,0.067288,0.035391},
		{0.028569,0.054318,0.067288,0.054318,0.028569},
		{0.015026,0.015026,0.035391,0.028569,0.015026}}
		});

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


	ed::matrix<unsigned char, 3, 3> dilation({ {
		{0,1,0},
		{1,1,1},
		{0,1,0}
		} });

	ed::matrix<unsigned char, 9, 9> dilation_great({ {
		{0,0,0,1,1,1,0,0,0},
		{0,0,0,1,1,1,0,0,0},
		{0,0,0,1,1,1,0,0,0},
		{1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1},
		{0,0,0,1,1,1,0,0,0},
		{0,0,0,1,1,1,0,0,0},
		{0,0,0,1,1,1,0,0,0},
		} });


	ed::matrix<unsigned char, 3, 3> sobel_edge({ {
		{1,2,2},
		{1,1,0},
		{2,4,1}
	} });

	ed::matrix<int, 5, 5> lap_from_gaus({ {
		{0,0,-1,0,0},
		{0,-1,-2,-1,0},
		{-1,-2,16, -2, -1},
		{0,-1,-2,-1,0},
		{0,0,-1,0,0}
} });

	ed::matrix<int> m(image);
	m = ed::convolution<int, 9, 9>(m, edge_kernel);
	m.equalization(255);

	for (int i = 0; i < m.height; i++) {
		for (int ii = 0; ii < m.width; ii++) {
			if (m(i, ii) <= 155 || m(i, ii) > 2500) {
				m(i, ii) = 0;
			}
			else {
				m(i, ii) = 255;
			}
		}
	}
	return m.get_intensity_image_ptr();
}

IntensityImage * StudentPreProcessing::stepThresholding(const IntensityImage &image) const { // aanpassen
	//Image Container
	//ed::matrix<unsigned char> m(image);
	ed::matrix<int> m(image);

	//5x5 Gaussian Filter (Remove Noise)

	//Basic Threshold filter
	//tr::auto_treshold(m, 120, 255);
	tr::histogram_threshold(m, 255);

	//return image pointer
	return m.get_intensity_image_ptr();
}