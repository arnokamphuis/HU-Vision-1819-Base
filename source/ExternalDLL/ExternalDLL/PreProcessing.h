/*
* Copyright (c) 2015 DottedEye Designs, Alexander Hustinx, NeoTech Software, Rolf Smit - All Rights Reserved
* Unauthorized copying of this file, via any medium is strictly prohibited
* Proprietary and confidential
*/

#pragma once

#include "RGBImage.h"
#include "IntensityImage.h"

class PreProcessing
{
public:

	virtual IntensityImage * stepToIntensityImage(const RGBImage &image) const = 0;
	virtual IntensityImage * stepScaleImage(const IntensityImage &image) const = 0;
	virtual IntensityImage * stepEdgeDetection(const IntensityImage &image) const = 0;
	virtual IntensityImage * stepThresholding(const IntensityImage &image) const = 0;
};

