/*
* Copyright (c) 2015 DottedEye Designs, Alexander Hustinx, NeoTech Software, Rolf Smit - All Rights Reserved
* Unauthorized copying of this file, via any medium is strictly prohibited
* Proprietary and confidential
*/

#include "FeatureMap.h"



FeatureMap::FeatureMap(const FeatureMap &other) {
	features = other.features;
}

FeatureMap::FeatureMap() {

}

FeatureMap::~FeatureMap() {

}



void FeatureMap::applyScale(double scaleFactor) {
	for (std::map<int, Feature>::const_iterator it = features.begin(); it != features.end(); it++) {
		Feature f = it->second;
		std::vector<Point2D<double>> &points = f.getPoints();
		for (size_t ip = 0; ip < points.size(); ip++) {
			points[ip] = Point2D<double>(((double)points[ip].x * scaleFactor), ((double)points[ip].y * scaleFactor));
		}
		features[f.getId()] = f;
	}
}



bool FeatureMap::hasFeatures(const int featureIds[], const int length) const {
	for (int i = 0; i < length; i++) {
		if (!hasFeature(featureIds[i])) {
			return false;
		}
	}
	return true;
}

bool FeatureMap::hasFeature(const int featureId) const {
	std::map<int, Feature>::const_iterator i = features.find(featureId);
	if (i != features.end()) {
		return (i->second.pointCount() >= 1);
	}
	return false;
	/*

	if (features.find(featureId) != features.end()){
		int featureIdCopy = featureId;
		features.
		//Feature f = features[featureIdCopy];
		return (f.pointCount() >= 1);
	}
	return false;
	*/
}

void FeatureMap::putFeature(Feature &feature) {
	features[feature.getId()] = feature;
}


Feature & FeatureMap::getFeature(const int featureId) {
	return features[featureId];
}


std::map<int, Feature> & FeatureMap::getFeatures() {
	return features;
}