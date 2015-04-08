/*
* Copyright (c) 2015 DottedEye Designs, Alexander Hustinx, NeoTech Software, Rolf Smit - All Rights Reserved
* Unauthorized copying of this file, via any medium is strictly prohibited
* Proprietary and confidential
*/

#include "Feature.h"
#include <stdexcept>





Feature::Feature(const Feature &other) {
	points = other.points;
	id = other.id;
}

Feature::Feature(int id, Point2D<double> point) : id(id) {
	points.push_back(point);
}

Feature::Feature(int id): id(id){
}

Feature::Feature() : id(-1){
}


Feature::~Feature(){
}


void Feature::addPoint(Point2D<double> point) {
	points.push_back(point);
}

std::vector<Point2D<double>>& Feature::getPoints() {
	return points;
}




double Feature::getX() const {
	return points[0].x;
}

double Feature::getY() const {
	return points[0].y;
}

int Feature::getId() const {
	return id;
}


const Point2D<double> & Feature::operator[](int index) const {
	return points[index];
}
Point2D<double> & Feature::operator[](int index) {
	return points[index];
}

int Feature::pointCount() const {
	return points.size();
}



Feature& Feature::getFeature(std::vector<Feature> &features, const int id) {
	for (size_t i = 0; i < features.size(); i++) {
		if (features[i].id == id) {
			return features[i];
		}
	}
	throw std::invalid_argument("Feature not found!");
}


bool Feature::containsFeature(const Feature(features)[], const int length, const int feature){
	for (int i = 0; i < length; i++){
		if (features[i].id == feature){
			return true;
		}
	}
	return false;
}

bool Feature::containsFeatures(const Feature(features)[], const int length, const int searchFeatures[], int searchLenght){
	bool found = true;
	for (int i = 0; i < searchLenght; i++){
		if (!Feature::containsFeature(features, length, searchFeatures[i])){
			return false;
		}
	}
	return true;
}

