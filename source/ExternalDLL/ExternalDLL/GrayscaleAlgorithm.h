/*
* Copyright (c) 2015 DottedEye Designs, Alexander Hustinx, NeoTech Software, Rolf Smit - All Rights Reserved
* Unauthorized copying of this file, via any medium is strictly prohibited
* Proprietary and confidential
*/

#pragma once
#include "Algorithm.h"
#include "IntensityImage.h"
#include "RGBImage.h"

class GrayscaleAlgorithm :
	public Algorithm<RGBImage, IntensityImage>
{
public:
	GrayscaleAlgorithm();
	~GrayscaleAlgorithm();

	void doAlgorithm(const RGBImage &input, IntensityImage &dst);
};

