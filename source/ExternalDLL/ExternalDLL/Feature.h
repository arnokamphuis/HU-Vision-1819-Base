/*
* Copyright (c) 2015 DottedEye Designs, Alexander Hustinx, NeoTech Software, Rolf Smit - All Rights Reserved
* Unauthorized copying of this file, via any medium is strictly prohibited
* Proprietary and confidential
*/

#pragma once

#include <math.h>
#include "Point2D.h"
#include <vector>

class Feature
{
private:
	int id;
	std::vector<Point2D<double>> points;

public:

	const static char FEATURE_HEAD_TOP = 0;

	const static char FEATURE_HEAD_LEFT_SIDE = 1;
	const static char FEATURE_HEAD_RIGHT_SIDE = 2;


	const static char FEATURE_NOSE_BOTTOM = 3;
	const static char FEATURE_MOUTH_TOP = 4;
	const static char FEATURE_MOUTH_CENTER = 5;
	const static char FEATURE_MOUTH_BOTTOM = 6;
	const static char FEATURE_CHIN = 7;


	const static char FEATURE_CHIN_CONTOUR = 8;





	//const static char FEATURE_HEAD_LEFTS = 9;
	//const static char FEATURE_HEAD_RIGHTS = 10;
	//const static char FEATURE_NOSE_LEFTS = 11;
	//const static char FEATURE_NOSE_RIGHTS = 12;

	const static char FEATURE_EYE_LEFT_RECT = 13;
	const static char FEATURE_EYE_RIGHT_RECT = 14;
	const static char FEATURE_NOSE_END_LEFT = 15;
	const static char FEATURE_NOSE_END_RIGHT = 16;

	const static char FEATURE_NOSTRIL_LEFT = 17;
	const static char FEATURE_NOSTRIL_RIGHT = 18;

	const static char FEATURE_MOUTH_CORNER_LEFT = 19;
	const static char FEATURE_MOUTH_CORNER_RIGHT = 20;



	const static char FEATURE_HEAD_LEFT_NOSE_BOTTOM = 21;
	const static char FEATURE_HEAD_RIGHT_NOSE_BOTTOM = 22;

	const static char FEATURE_HEAD_LEFT_NOSE_MIDDLE = 23;
	const static char FEATURE_HEAD_RIGHT_NOSE_MIDDLE = 24;


	Feature(const Feature &other);
	Feature(int id, Point2D<double> point);
	Feature(int id);
	Feature();
	~Feature();


	int pointCount() const;

	const Point2D<double> & operator[](int index) const;
	Point2D<double> & operator[](int index);


	void addPoint(Point2D<double> point);
	std::vector<Point2D<double>>& getPoints();


	double getX() const;
	double getY() const;

	int getId() const;

	static Feature& getFeature(std::vector<Feature> &features, const int id);

	static bool containsFeature(const Feature(features)[], const int length, const int feature);
	static bool containsFeatures(const Feature(features)[], const int length, const int searchFeatures[], const int searchLenght);

};

