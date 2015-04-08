/*
* Copyright (c) 2015 DottedEye Designs, Alexander Hustinx, NeoTech Software, Rolf Smit - All Rights Reserved
* Unauthorized copying of this file, via any medium is strictly prohibited
* Proprietary and confidential
*/

#pragma once
#include "FeatureMap.h"
class Representation {

private:
	static const int FEATURES_REQUIRED[];
	static const int FEATURES_REQUIRED_COUNT;

public:
	static bool calculateRepresentation(FeatureMap &features, double(&facialParameters)[16]);

	static double getChinCountourArea(FeatureMap &features);

	//Vectors
	static double getVectorAngle(Point2D<double> one, Point2D<double> two);
	static double getVectorLenght(Point2D<double> vector);
	static Point2D<double> getNormalizeVector(Point2D<double> vector);

	//Points
	static double getAreaOfTriangle(Point2D<double> A, Point2D<double> B, Point2D<double> C);
	static double getAngle(Point2D<double> one, Point2D<double> two, Point2D<double> orgin);
	static Point2D<double> getCenter(Point2D<double> start, Point2D<double> end);
	static double getLength(Point2D<double> start, Point2D<double> end);
};