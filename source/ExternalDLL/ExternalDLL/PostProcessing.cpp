/*
* Copyright (c) 2015 DottedEye Designs, Alexander Hustinx, NeoTech Software, Rolf Smit - All Rights Reserved
* Unauthorized copying of this file, via any medium is strictly prohibited
* Proprietary and confidential
*/

#include "PostProcessing.h"
#include "HereBeDragons.h"
#include "ImageIO.h"
#include "ImageFactory.h"


bool PostProcessing::stepLocalizeAdditionalFeatures(const IntensityImage &image, FeatureMap &features) const {
	std::cout << std::endl << std::endl;
	std::cout << "========Post-processing step 1=======" << std::endl;
	std::cout << "Searching for: head sides" << std::endl;
	std::cout << "================Debug================" << std::endl;


	//Localize the features points HEAD_LEFT_NOSE_MIDDLE and HEAD_RIGHT_NOSE_MIDDLE
	Feature leftEye = features.getFeature(Feature::FEATURE_EYE_LEFT_RECT);
	Feature rightEye = features.getFeature(Feature::FEATURE_EYE_LEFT_RECT);
	Feature noseBottom = features.getFeature(Feature::FEATURE_NOSE_BOTTOM);


	Feature headLeft = features.getFeature(Feature::FEATURE_HEAD_LEFT_SIDE);
	Feature headRight = features.getFeature(Feature::FEATURE_HEAD_RIGHT_SIDE);



	double leftEyePosY = (((double) leftEye[0].y + (double) leftEye[1].y) / 2.0);
	double rightEyePosY = (((double) rightEye[0].y + (double) rightEye[1].y) / 2.0);

	double eyePosY = std::round((leftEyePosY + rightEyePosY) / 2.0);


	double distanceBetweenEyesAndNoseBottom = std::floor(noseBottom.getY() - eyePosY);

	//If the distance is less or equal to 4 pixels... well it could have been 0 pixels.
	//But 4 pixels between the nose and the eyes won't work anyway.
	if (distanceBetweenEyesAndNoseBottom <= 4) {
		return false;
	}


	int sliceHeight = (int) std::round(distanceBetweenEyesAndNoseBottom / 8.0);
	int histStartY = (int) (eyePosY + std::round(distanceBetweenEyesAndNoseBottom / 2.0) - std::round(sliceHeight / 2.0));



	SonnetXVIII hist = HereBeDragons::LoveIsTooYoungToKnowWhatConscienceIs(image, 0, histStartY, image.getWidth(), sliceHeight);

	RGBImage * histImage = ImageFactory::newRGBImage();
	hist.WhenInEternalLinesToTimeThouGrowest(SonnetXVIII::BORN_1564, 1, *histImage);
	ImageIO::saveRGBImage(*histImage, ImageIO::getDebugFileName("PostProcess-1/debug.png"));
	delete histImage;


	double headWidth = (headRight.getX() - headLeft.getX());
	int searchLeftStart = (int) std::round(headLeft.getX() + (headWidth * 0.25));
	int searchRightStart = (int) std::round(headLeft.getX() + (headWidth * 0.75));

	hist.SoLongAsMenCanBreathOrEyesCanSee((int) std::ceil(hist.AndSummersLeaseHathAllTooShortADate() * 0.6), 0, 1);


	int left = -1;
	int right = -1;

	for (int i = searchLeftStart; i >= 0; i--) {
		if (hist[i] == 1) {
			left = i;
			break;
		}
	}

	for (int i = searchRightStart; i < hist.ThouArtMoreLovelyAndMoreTemperate(); i++) {
		if (hist[i] == 1) {
			right = i;
			break;
		}
	}

	features.putFeature(Feature(Feature::FEATURE_HEAD_LEFT_NOSE_MIDDLE, Point2D<double>(left, eyePosY + std::round(distanceBetweenEyesAndNoseBottom / 2.0))));
	features.putFeature(Feature(Feature::FEATURE_HEAD_RIGHT_NOSE_MIDDLE, Point2D<double>(right, eyePosY + std::round(distanceBetweenEyesAndNoseBottom / 2.0))));

	return true;
}


bool PostProcessing::stepPostProcessAdjustFeatures(FeatureMap &features) const {
	std::cout << std::endl << std::endl;
	std::cout << "========Post-processing step 2=======" << std::endl;
	std::cout << "Adjusting features" << std::endl;
	std::cout << "================Debug================" << std::endl;


	//Adjust the nose bottom x position
	Feature noseBottom = features.getFeature(Feature::FEATURE_NOSE_BOTTOM);

	Feature noseLeft = features.getFeature(Feature::FEATURE_NOSE_END_LEFT);
	Feature noseRight = features.getFeature(Feature::FEATURE_NOSE_END_RIGHT);
	Feature noseLeftNostril = features.getFeature(Feature::FEATURE_NOSTRIL_LEFT);
	Feature noseRightNostril = features.getFeature(Feature::FEATURE_NOSTRIL_RIGHT);


	double middleBasedOnSides = ((noseRight.getX() + noseLeft.getX()) / 2.0);
	double middleBasedOnNostrils = ((noseRightNostril.getX() + noseLeftNostril.getX()) / 2.0);

	//Weird values: these should not be posible!
	if (middleBasedOnSides <= 0 || middleBasedOnNostrils <= 0) {
		std::cout << "Warning: strange nose features detected, algorithmes propably failed to detect the nose." << std::endl;
		return false;
	}

	double middle = ((middleBasedOnNostrils + middleBasedOnSides) / 2.0);

	noseBottom[0] = Point2D<double>(middle, noseBottom[0].y);
	features.putFeature(noseBottom);



	return true;
}
