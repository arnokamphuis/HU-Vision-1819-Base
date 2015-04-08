/*
* Copyright (c) 2015 DottedEye Designs, Alexander Hustinx, NeoTech Software, Rolf Smit - All Rights Reserved
* Unauthorized copying of this file, via any medium is strictly prohibited
* Proprietary and confidential
*/

#pragma once

#include <map>
#include "Feature.h"

class FeatureMap {

private:
	std::map<int, Feature> features;

public:
	FeatureMap(const FeatureMap &other);
	FeatureMap();
	~FeatureMap();


	void applyScale(double scaleFactor);

	std::map<int, Feature> & getFeatures();

	bool hasFeatures(const int featureIds[], const int length) const;
	bool hasFeature(const int featureId) const;
	void putFeature(Feature &feature);
	Feature & getFeature(const int featureId);
};