/*
* Copyright (c) 2015 DottedEye Designs, Alexander Hustinx, NeoTech Software, Rolf Smit - All Rights Reserved
* Unauthorized copying of this file, via any medium is strictly prohibited
* Proprietary and confidential
*/

#include "Representation.h"
#include <math.h> //std::sqrt()

const int Representation::FEATURES_REQUIRED[] = {
	Feature::FEATURE_HEAD_LEFT_NOSE_MIDDLE,
	Feature::FEATURE_HEAD_RIGHT_NOSE_MIDDLE, 
	Feature::FEATURE_CHIN,
	Feature::FEATURE_HEAD_LEFT_NOSE_BOTTOM,
	Feature::FEATURE_HEAD_RIGHT_NOSE_BOTTOM,
	Feature::FEATURE_CHIN_CONTOUR,
	Feature::FEATURE_NOSE_BOTTOM,
	Feature::FEATURE_MOUTH_TOP,
	Feature::FEATURE_EYE_LEFT_RECT,
	Feature::FEATURE_EYE_RIGHT_RECT,
	Feature::FEATURE_NOSE_END_LEFT,
	Feature::FEATURE_NOSE_END_RIGHT,
	Feature::FEATURE_NOSTRIL_LEFT,
	Feature::FEATURE_NOSTRIL_RIGHT,
	Feature::FEATURE_MOUTH_CORNER_LEFT,
	Feature::FEATURE_MOUTH_CORNER_RIGHT
};

const int Representation::FEATURES_REQUIRED_COUNT = 16;


bool Representation::calculateRepresentation(FeatureMap &features, double(&facialParameters)[16]) {
	std::cout << std::endl << std::endl;
	std::cout << "============Representation===========" << std::endl;
	std::cout << "Calculating: facial parameters" << std::endl;
	std::cout << "================Debug================" << std::endl;


	if (!features.hasFeatures(FEATURES_REQUIRED, FEATURES_REQUIRED_COUNT)) {
		std::cout << "Representation failed: Not all required features are available!" << std::endl;
		return false;
	}


	std::vector<Point2D<double>> chinContours = features.getFeature(Feature::FEATURE_CHIN_CONTOUR).getPoints();
	//Check chinCountours
	//if (chinContours.size() != 18) {
		//std::cout << "Representation failed: Chin contour feature does not contain 18 points!" << std::endl;
		//return false;
	//}

	Feature eyeLeft = features.getFeature(Feature::FEATURE_EYE_LEFT_RECT);
	Feature eyeRight = features.getFeature(Feature::FEATURE_EYE_RIGHT_RECT);
	//Check eyes
	if (eyeLeft.getPoints().size() != 2) {
		std::cout << "Representation failed: Left eye feature does not contain 2 points!" << std::endl;
		return false;
	}
	if (eyeRight.getPoints().size() != 2) {
		std::cout << "Representation failed: Right eye feature does not contain 2 points!" << std::endl;
		return false;
	}

	Point2D<double> C = features.getFeature(Feature::FEATURE_CHIN)[0];
	Point2D<double> N = features.getFeature(Feature::FEATURE_NOSE_BOTTOM)[0];
	Point2D<double> M = features.getFeature(Feature::FEATURE_MOUTH_TOP)[0];
	Point2D<double> A = features.getFeature(Feature::FEATURE_HEAD_LEFT_NOSE_MIDDLE)[0];
	Point2D<double> B = features.getFeature(Feature::FEATURE_HEAD_RIGHT_NOSE_MIDDLE)[0];
	Point2D<double> O = Point2D<double>(N.x, (A.y + B.y) / 2.0);
	Point2D<double> E = features.getFeature(Feature::FEATURE_HEAD_LEFT_NOSE_BOTTOM)[0];
	Point2D<double> F = features.getFeature(Feature::FEATURE_HEAD_RIGHT_NOSE_BOTTOM)[0];
	Point2D<double> S = getCenter(eyeLeft[0], eyeLeft[1]);
	Point2D<double> T = getCenter(eyeRight[0], eyeRight[1]);
	Point2D<double> X = getCenter(S, T);


	double chinContourArea = getChinCountourArea(features);
	if (chinContourArea == -1) {
		std::cout << "Representation failed: Chin contour area could not be calculated!" << std::endl;
		return false;
	}
	
	double AB = getLength(A, B);
	double OC = getLength(O, C);
	double ST = getLength(S, T);
	double NC = getLength(N, C);


	double θl = getAngle(E, Point2D<double>(chinContours[0].x, E.y), chinContours[0]);
	double θy = getAngle(F, Point2D<double>(chinContours[chinContours.size() - 1].x, F.y), chinContours[chinContours.size() - 1]);

	double α = getAngle(features.getFeature(Feature::FEATURE_NOSE_END_LEFT)[0], features.getFeature(Feature::FEATURE_NOSE_END_RIGHT)[0], X);
	double β = getAngle(chinContours[0], chinContours[chinContours.size() - 1], C);

	double a = getLength(features.getFeature(Feature::FEATURE_NOSTRIL_LEFT)[0], features.getFeature(Feature::FEATURE_NOSTRIL_RIGHT)[0]);
	double b = getLength(features.getFeature(Feature::FEATURE_MOUTH_CORNER_LEFT)[0], features.getFeature(Feature::FEATURE_MOUTH_CORNER_RIGHT)[0]);

	double NM = getLength(N, M);
	double XN = getLength(X, N);
	double XC = getLength(X, C);

	double hl = std::abs(eyeLeft[0].x - eyeLeft[1].x);
	double hy = std::abs(eyeRight[0].x - eyeRight[1].x);
	double vl = std::abs(eyeLeft[0].y - eyeLeft[1].y);
	double vy = std::abs(eyeRight[0].y - eyeRight[1].y);


	facialParameters[0] = AB / OC; //Is relative, because divide
	facialParameters[1] = ST / AB; //Is relative, because divide
	facialParameters[2] = NC / OC; //Is relative, because divide
	facialParameters[3] = 0.0; //????????
	facialParameters[4] = chinContourArea;  //Is relative, because devide (see function)
	facialParameters[5] = α; //Is relative, because angle
	facialParameters[6] = (θl + θy) / 2.0; //Is relative, because angle
	facialParameters[7] = β; //Is relative, because angle
	facialParameters[8] = XN / XC; //Is relative, because divide
	facialParameters[9] = NM / XC; //Is relative, because divide
	facialParameters[10] = (hl + hy) / ST; //Is relative, because divide
	facialParameters[11] = (vl + vy) / ST; //Is relative, because divide
	facialParameters[12] = a / ST; //Is relative, because divide
	facialParameters[13] = b / ST; //Is relative, because divide
	facialParameters[14] = ST / XN; //Is relative, because divide
	facialParameters[15] = (hl + hy) / (vl + vy); //Is relative, because divide

	return true;
}

double Representation::getChinCountourArea(FeatureMap &features) {

	Point2D<double> C = features.getFeature(Feature::FEATURE_CHIN)[0];
	Point2D<double> E = features.getFeature(Feature::FEATURE_HEAD_LEFT_NOSE_BOTTOM)[0];
	Point2D<double> G = Point2D<double>(E.x, C.y);
	Point2D<double> F = features.getFeature(Feature::FEATURE_HEAD_RIGHT_NOSE_BOTTOM)[0];
	Point2D<double> H = Point2D<double>(F.x, C.y);

	double areaLeft = 0, areaRight = 0;
	int firstRightIndex = -1;
	std::vector<Point2D<double>> points = features.getFeature(Feature::FEATURE_CHIN_CONTOUR).getPoints();
	Point2D<double> lastPoint;

	lastPoint = E;
	for (size_t i = 0; i < points.size(); i++) {
		Point2D<double> point = points[i];
		if (point.x > C.x) {
			firstRightIndex = i;
			break;
		} else {
			areaLeft += getAreaOfTriangle(lastPoint, G, point);
		}
		lastPoint = point;
	}

	if (firstRightIndex == -1) {
		std::cout << "No right chin contours found!" << std::endl;
		return -1;
	} else if (areaLeft == 0) {
		std::cout << "No left chin contours found!" << std::endl;
		return -1;
	}

	lastPoint = F;
	for (int i = points.size() - 1; i >= firstRightIndex; i--) {
		Point2D<double> point = points[i];
		areaRight += getAreaOfTriangle(lastPoint, H, point);
		lastPoint = point;
	}

	return (getAreaOfTriangle(E, G, C) + getAreaOfTriangle(F, C, H)) / (areaLeft + areaRight);
}

double Representation::getVectorAngle(Point2D<double> one, Point2D<double> two) {
	return std::acos((one.x * two.x) + (one.y * two.y));
}

double Representation::getAngle(Point2D<double> one, Point2D<double> two, Point2D<double> orgin) {
	Point2D<double> vectorOne = getNormalizeVector(one - orgin);
	Point2D<double> vectorTwo = getNormalizeVector(two - orgin);
	return getVectorAngle(vectorOne, vectorTwo);
}

double Representation::getVectorLenght(Point2D<double> vector) {
	return std::sqrt(std::pow(vector.x, 2) + std::pow(vector.y, 2));
}

Point2D<double> Representation::getNormalizeVector(Point2D<double> vector) {
	double length = getVectorLenght(vector);
	return Point2D<double>(vector.x / length, vector.y / length);
}

double Representation::getAreaOfTriangle(Point2D<double> A, Point2D<double> B, Point2D<double> C) {
	//Heron's formula

	//Sides
	double a = getLength(A, C);
	double b = getLength(A, B);
	double c = getLength(B, C);

	//semiperimeter
	double s = (a + b + c) / 2.0;

	//Area
	return std::sqrt(s * (s - a) * (s - b) * (s - c));
}

Point2D<double> Representation::getCenter(Point2D<double> start, Point2D<double> end) {
	return Point2D<double>((start.x + end.x) / 2.0, (start.y + end.y) / 2.0);
}

double Representation::getLength(Point2D<double> start, Point2D<double> end) {
	return std::sqrt( std::pow((start.x - end.x), 2) + std::pow(start.y - end.y, 2) );
}