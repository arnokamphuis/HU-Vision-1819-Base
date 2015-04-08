/*
* Copyright (c) 2015 DottedEye Designs, Alexander Hustinx, NeoTech Software, Rolf Smit - All Rights Reserved
* Unauthorized copying of this file, via any medium is strictly prohibited
* Proprietary and confidential
*/

#pragma once
#include "IntensityImage.h"
#include "FeatureMap.h"
class PostProcessing {
public:
	bool stepLocalizeAdditionalFeatures(const IntensityImage &image, FeatureMap &features) const;
	bool stepPostProcessAdjustFeatures(FeatureMap &features) const;
};