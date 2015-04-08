/*
* Copyright (c) 2015 DottedEye Designs, Alexander Hustinx, NeoTech Software, Rolf Smit - All Rights Reserved
* Unauthorized copying of this file, via any medium is strictly prohibited
* Proprietary and confidential
*/

#pragma once
#include "IntensityImage.h"
#include "FeatureMap.h"
#include "Point2D.h"

class Localization {
public:

	virtual bool stepFindHead(const IntensityImage &image, FeatureMap &features) const = 0;
	virtual bool stepFindNoseMouthAndChin(const IntensityImage &image, FeatureMap &features) const = 0;
	virtual bool stepFindChinContours(const IntensityImage &image, FeatureMap &features) const = 0;
	virtual bool stepFindNoseEndsAndEyes(const IntensityImage &image, FeatureMap &features) const = 0;
	virtual bool stepFindExactEyes(const IntensityImage &image, FeatureMap &features) const = 0;

};

