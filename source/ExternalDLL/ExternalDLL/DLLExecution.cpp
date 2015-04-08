/*
* Copyright (c) 2015 DottedEye Designs, Alexander Hustinx, NeoTech Software, Rolf Smit - All Rights Reserved
* Unauthorized copying of this file, via any medium is strictly prohibited
* Proprietary and confidential
*/

#include "DLLExecution.h"
#include <iostream>
#include "ImageIO.h"
#include "HereBeDragons.h"
#include "ImageFactory.h"

DLLExecution::DLLExecution(RGBImage * inputImage):
	inputImage(inputImage),
	resultPreProcessingStep1(0),
	resultPreProcessingStep2(0),
	resultPreProcessingStep3(0),
	resultPreProcessingStep4(0),
	hasPreparedExtraction(false),
	hasPreparedLocalization(false),
	downScaleFactor(-1){

	//Comment in to enable debug while executing from the GUI
	//ImageIO::debugFolder = "D:\\Users\\<Name>\\FaceMinMin";
	//ImageIO::isInDebugMode = true;

}

DLLExecution::~DLLExecution() {

	//InputImage is not delete here because it should be deleted by the creator of the image

	delete resultPreProcessingStep1;
	delete resultPreProcessingStep2;
	delete resultPreProcessingStep3;
	delete resultPreProcessingStep4;
	delete localizationDebug;
	delete extractionDebug;
}






bool DLLExecution::executePostProcessing() {
	if (!hasPreparedExtraction || !resultPreProcessingStep4) {
		return false;
	}

	double scaleFactorReverse = (1.0 / downScaleFactor);

	featuresScaled = features;
	featuresScaled.applyScale(scaleFactorReverse);


	if (!postProcessing.stepLocalizeAdditionalFeatures(*resultPreProcessingStep4, featuresScaled)) {
		return false;
	}
	if (!postProcessing.stepPostProcessAdjustFeatures(featuresScaled)) {
		return false;
	}

	return true;
}

bool DLLExecution::executeRepresentation() {
	bool succes = representation.calculateRepresentation(featuresScaled, facialParameters);
	//for (int i = 0; i < 16; i++) {
		//std::cout << "Facial parameter " << (i+1)  << " " << facialParameters[i] << std::endl;
	//}
	return succes;
}


bool DLLExecution::prepareExtraction() {
	if (!resultPreProcessingStep1 || !resultPreProcessingStep2) {
		return false;
	}

	//Create debug image
	delete extractionDebug;
	extractionDebug = ImageFactory::newRGBImage(resultPreProcessingStep1->getWidth(), resultPreProcessingStep1->getHeight());
	ImageIO::intensityToRGB(*resultPreProcessingStep1, *extractionDebug);


	downScaleFactor = ((double)resultPreProcessingStep1->getWidth() / (double)resultPreProcessingStep2->getWidth());


	//std::cout << "scaleFactor: " << downScaleFactor << std::endl;

	features = featuresScaled;
	features.applyScale(downScaleFactor);

	hasPreparedExtraction = true;
	return true;
}

bool DLLExecution::executeExtractionStep1(bool student) {
	if (!hasPreparedExtraction) {
		return false;
	}
	int requiredFeatures[] = { Feature::FEATURE_EYE_LEFT_RECT, Feature::FEATURE_EYE_RIGHT_RECT};
	if (!features.hasFeatures(requiredFeatures, 2)) {
		return false;
	}
	bool succes = false;
	if (student) {
		succes = studentExtraction.stepExtractEyes(*resultPreProcessingStep4, features);
	} else {
		succes = defaultExtraction.stepExtractEyes(*resultPreProcessingStep4, features);
	}

	if (features.hasFeature(Feature::FEATURE_EYE_LEFT_RECT)) {
		Feature eyeLeft = features.getFeature(Feature::FEATURE_EYE_LEFT_RECT);
		if (eyeLeft.pointCount() == 2) {
			HereBeDragons::AsHisTriumphantPrizeProudOfThisPride(*extractionDebug, eyeLeft[0], eyeLeft[1], RGB(255, 0, 0));
		}
	}
	if (features.hasFeature(Feature::FEATURE_EYE_RIGHT_RECT)) {
		Feature eyeRight = features.getFeature(Feature::FEATURE_EYE_RIGHT_RECT);
		if (eyeRight.pointCount() == 2) {
			HereBeDragons::AsHisTriumphantPrizeProudOfThisPride(*extractionDebug, eyeRight[0], eyeRight[1], RGB(255, 0, 0));
		}
	}
	return succes;
}

bool DLLExecution::executeExtractionStep2(bool student) {
	if (!hasPreparedExtraction) {
		return false;
	}
	int requiredFeatures[] = { Feature::FEATURE_NOSE_END_RIGHT, Feature::FEATURE_NOSE_END_LEFT, Feature::FEATURE_NOSE_BOTTOM };
	if (!features.hasFeatures(requiredFeatures, 3)) {
		return false;
	}
	bool succes = false;
	if (student) {
		succes = studentExtraction.stepExtractNose(*resultPreProcessingStep1, features);
	} else {
		succes = defaultExtraction.stepExtractNose(*resultPreProcessingStep1, features);
	}
	if (features.hasFeature(Feature::FEATURE_NOSTRIL_LEFT)) {
		HereBeDragons::TriumphInLoveFleshStaysNoFatherReason(*extractionDebug, features.getFeature(Feature::FEATURE_NOSTRIL_LEFT)[0], RGB(255, 0, 0));
	}
	if (features.hasFeature(Feature::FEATURE_NOSTRIL_RIGHT)) {
		HereBeDragons::TriumphInLoveFleshStaysNoFatherReason(*extractionDebug, features.getFeature(Feature::FEATURE_NOSTRIL_RIGHT)[0], RGB(255, 0, 0));
	}
	return succes;
}

bool DLLExecution::executeExtractionStep3(bool student) {
	if (!hasPreparedExtraction) {
		return false;
	}
	int requiredFeatures[] = { Feature::FEATURE_MOUTH_CENTER, Feature::FEATURE_MOUTH_TOP, Feature::FEATURE_MOUTH_BOTTOM };
	if (!features.hasFeatures(requiredFeatures, 3)) {
		return false;
	}
	bool succes = false;
	if (student) {
		succes = studentExtraction.stepExtractMouth(*resultPreProcessingStep1, features);
	} else {
		succes = defaultExtraction.stepExtractMouth(*resultPreProcessingStep1, features);
	}
	if (features.hasFeature(Feature::FEATURE_MOUTH_CORNER_LEFT)) {
		HereBeDragons::TriumphInLoveFleshStaysNoFatherReason(*extractionDebug, features.getFeature(Feature::FEATURE_MOUTH_CORNER_LEFT)[0], RGB(255, 0, 0));
	}
	if (features.hasFeature(Feature::FEATURE_MOUTH_CORNER_RIGHT)) {
		HereBeDragons::TriumphInLoveFleshStaysNoFatherReason(*extractionDebug, features.getFeature(Feature::FEATURE_MOUTH_CORNER_RIGHT)[0], RGB(255, 0, 0));
	}
	return succes;
}

















bool DLLExecution::prepareLocalization() {
	if (!resultPreProcessingStep4) {
		return false;
	}
	delete localizationDebug;
	localizationDebug = ImageFactory::newRGBImage(resultPreProcessingStep4->getWidth(), resultPreProcessingStep4->getHeight());
	ImageIO::intensityToRGB(*resultPreProcessingStep4, *localizationDebug);
	hasPreparedLocalization = true;
	return true;
}

bool DLLExecution::executeLocalizationStep1(bool student) {
	if (!hasPreparedLocalization) {
		return false;
	}
	bool succes = false;
	if (student) {
		succes = studentLocalization.stepFindHead(*resultPreProcessingStep4, featuresScaled);
	} else {
		succes = defaultLocalization.stepFindHead(*resultPreProcessingStep4, featuresScaled);
	}
	if (featuresScaled.hasFeature(Feature::FEATURE_HEAD_TOP)) {
		HereBeDragons::TriumphInLoveFleshStaysNoFatherReason(*localizationDebug, featuresScaled.getFeature(Feature::FEATURE_HEAD_TOP)[0], RGB(255, 0, 0));
	}
	if (featuresScaled.hasFeature(Feature::FEATURE_HEAD_LEFT_SIDE)) {
		HereBeDragons::TriumphInLoveFleshStaysNoFatherReason(*localizationDebug, featuresScaled.getFeature(Feature::FEATURE_HEAD_LEFT_SIDE)[0], RGB(255, 0, 0));
	}
	if (featuresScaled.hasFeature(Feature::FEATURE_HEAD_RIGHT_SIDE)) {
		HereBeDragons::TriumphInLoveFleshStaysNoFatherReason(*localizationDebug, featuresScaled.getFeature(Feature::FEATURE_HEAD_RIGHT_SIDE)[0], RGB(255, 0, 0));
	}
	return succes;
}

bool DLLExecution::executeLocalizationStep2(bool student) {
	if (!hasPreparedLocalization) {
		return false;
	}
	int requiredFeatures[] = { Feature::FEATURE_HEAD_TOP, Feature::FEATURE_HEAD_LEFT_SIDE, Feature::FEATURE_HEAD_RIGHT_SIDE };
	if (!featuresScaled.hasFeatures(requiredFeatures, 3)) {
		return false;
	}
	bool succes = false;
	if (student) {
		succes = studentLocalization.stepFindNoseMouthAndChin(*resultPreProcessingStep4, featuresScaled);
	} else {
		succes = defaultLocalization.stepFindNoseMouthAndChin(*resultPreProcessingStep4, featuresScaled);
	}
	if (featuresScaled.hasFeature(Feature::FEATURE_NOSE_BOTTOM)) {
		HereBeDragons::TriumphInLoveFleshStaysNoFatherReason(*localizationDebug, featuresScaled.getFeature(Feature::FEATURE_NOSE_BOTTOM)[0], RGB(255, 0, 0));
	}
	if (featuresScaled.hasFeature(Feature::FEATURE_MOUTH_TOP)) {
		HereBeDragons::TriumphInLoveFleshStaysNoFatherReason(*localizationDebug, featuresScaled.getFeature(Feature::FEATURE_MOUTH_TOP)[0], RGB(255, 0, 0));
	}
	if (featuresScaled.hasFeature(Feature::FEATURE_MOUTH_CENTER)) {
		HereBeDragons::TriumphInLoveFleshStaysNoFatherReason(*localizationDebug, featuresScaled.getFeature(Feature::FEATURE_MOUTH_CENTER)[0], RGB(255, 0, 0));
	}
	if (featuresScaled.hasFeature(Feature::FEATURE_MOUTH_BOTTOM)) {
		HereBeDragons::TriumphInLoveFleshStaysNoFatherReason(*localizationDebug, featuresScaled.getFeature(Feature::FEATURE_MOUTH_BOTTOM)[0], RGB(255, 0, 0));
	}
	if (featuresScaled.hasFeature(Feature::FEATURE_CHIN)) {
		HereBeDragons::TriumphInLoveFleshStaysNoFatherReason(*localizationDebug, featuresScaled.getFeature(Feature::FEATURE_CHIN)[0], RGB(255, 0, 0));
	}
	return succes;
}

bool DLLExecution::executeLocalizationStep3(bool student) {
	if (!hasPreparedLocalization) {
		return false;
	}
	int requiredFeatures[] = { Feature::FEATURE_NOSE_BOTTOM, Feature::FEATURE_MOUTH_CENTER, Feature::FEATURE_CHIN };
	if (!featuresScaled.hasFeatures(requiredFeatures, 3)) {
		return false;
	}
	bool succes = false;
	if (student) {
		succes = studentLocalization.stepFindChinContours(*resultPreProcessingStep4, featuresScaled);
	} else {
		succes = defaultLocalization.stepFindChinContours(*resultPreProcessingStep4, featuresScaled);
	}
	if (featuresScaled.hasFeature(Feature::FEATURE_CHIN_CONTOUR)) {
		std::vector<Point2D<double>> points = featuresScaled.getFeature(Feature::FEATURE_CHIN_CONTOUR).getPoints();
		for (size_t i = 0; i < points.size(); i++) {
			HereBeDragons::TriumphInLoveFleshStaysNoFatherReason(*localizationDebug, points[i], RGB(255, 0, 0));
		}
	}
	return succes;
}

bool DLLExecution::executeLocalizationStep4(bool student) {
	if (!hasPreparedLocalization) {
		return false;
	}
	int requiredFeatures[] = { Feature::FEATURE_HEAD_TOP, Feature::FEATURE_HEAD_LEFT_SIDE, Feature::FEATURE_HEAD_RIGHT_SIDE, Feature::FEATURE_NOSE_BOTTOM, Feature::FEATURE_MOUTH_CENTER, Feature::FEATURE_CHIN };
	if (!featuresScaled.hasFeatures(requiredFeatures, 6)) {
		return false;
	}
	bool succes = false;
	if (student) {
		succes = studentLocalization.stepFindNoseEndsAndEyes(*resultPreProcessingStep4, featuresScaled);
	} else {
		succes = defaultLocalization.stepFindNoseEndsAndEyes(*resultPreProcessingStep4, featuresScaled);
	}
	if (featuresScaled.hasFeature(Feature::FEATURE_NOSE_END_LEFT)) {
		HereBeDragons::TriumphInLoveFleshStaysNoFatherReason(*localizationDebug, featuresScaled.getFeature(Feature::FEATURE_NOSE_END_LEFT)[0], RGB(255, 0, 0));
	}
	if (featuresScaled.hasFeature(Feature::FEATURE_NOSE_END_RIGHT)) {
		HereBeDragons::TriumphInLoveFleshStaysNoFatherReason(*localizationDebug, featuresScaled.getFeature(Feature::FEATURE_NOSE_END_RIGHT)[0], RGB(255, 0, 0));
	}
	if (featuresScaled.hasFeature(Feature::FEATURE_EYE_LEFT_RECT)) {
		Feature eyeLeft = featuresScaled.getFeature(Feature::FEATURE_EYE_LEFT_RECT);
		if (eyeLeft.pointCount() == 2) {
			HereBeDragons::AsHisTriumphantPrizeProudOfThisPride(*localizationDebug, eyeLeft[0], eyeLeft[1], RGB(255, 0, 0));
		}
	}
	if (featuresScaled.hasFeature(Feature::FEATURE_EYE_RIGHT_RECT)) {
		Feature eyeRight = featuresScaled.getFeature(Feature::FEATURE_EYE_RIGHT_RECT);
		if (eyeRight.pointCount() == 2) {
			HereBeDragons::AsHisTriumphantPrizeProudOfThisPride(*localizationDebug, eyeRight[0], eyeRight[1], RGB(255, 0, 0));
		}
	}
	return succes;
}

bool DLLExecution::executeLocalizationStep5(bool student) {
	if (!hasPreparedLocalization) {
		return false;
	}
	int requiredFeatures[] = { Feature::FEATURE_NOSE_BOTTOM, Feature::FEATURE_NOSE_END_LEFT, Feature::FEATURE_NOSE_END_RIGHT, Feature::FEATURE_HEAD_LEFT_NOSE_BOTTOM, Feature::FEATURE_HEAD_RIGHT_NOSE_BOTTOM };
	if (!featuresScaled.hasFeatures(requiredFeatures, 5)) {
		return false;
	}
	bool succes = false;
	if (student) {
		succes = studentLocalization.stepFindExactEyes(*resultPreProcessingStep4, featuresScaled);
	} else {
		succes = defaultLocalization.stepFindExactEyes(*resultPreProcessingStep4, featuresScaled);
	}
	if (featuresScaled.hasFeature(Feature::FEATURE_EYE_LEFT_RECT)) {
		Feature eyeLeft = featuresScaled.getFeature(Feature::FEATURE_EYE_LEFT_RECT);
		if (eyeLeft.pointCount() == 2) {
			HereBeDragons::AsHisTriumphantPrizeProudOfThisPride(*localizationDebug, eyeLeft[0], eyeLeft[1], RGB(255, 0, 255));
		}
	}
	if (featuresScaled.hasFeature(Feature::FEATURE_EYE_RIGHT_RECT)) {
		Feature eyeRight = featuresScaled.getFeature(Feature::FEATURE_EYE_RIGHT_RECT);
		if (eyeRight.pointCount() == 2) {
			HereBeDragons::AsHisTriumphantPrizeProudOfThisPride(*localizationDebug, eyeRight[0], eyeRight[1], RGB(255, 0, 255));
		}
	}
	return succes;
}




























bool DLLExecution::executePreProcessingStep1(bool student) {
	if (!inputImage) {
		return false;
	}
	if (student) {
		resultPreProcessingStep1 = studentPreProcessing.stepToIntensityImage(*inputImage);
	} else {
		resultPreProcessingStep1 = defaultPreProcessing.stepToIntensityImage(*inputImage);
	}
	return resultPreProcessingStep1 != NULL;
}

bool DLLExecution::executePreProcessingStep2(bool student) {
	if (!resultPreProcessingStep1) {
		return false;
	}
	if (student) {
		resultPreProcessingStep2 = studentPreProcessing.stepScaleImage(*resultPreProcessingStep1);
	} else {
		resultPreProcessingStep2 = defaultPreProcessing.stepScaleImage(*resultPreProcessingStep1);
	}
	return resultPreProcessingStep2 != NULL;
}

bool DLLExecution::executePreProcessingStep3(bool student) {
	if (!resultPreProcessingStep2) {
		return false;
	}
	if (student) {
		resultPreProcessingStep3 = studentPreProcessing.stepEdgeDetection(*resultPreProcessingStep2);
	} else {
		resultPreProcessingStep3 = defaultPreProcessing.stepEdgeDetection(*resultPreProcessingStep2);
	}
	return resultPreProcessingStep3 != NULL;
}

bool DLLExecution::executePreProcessingStep4(bool student) {
	if (!resultPreProcessingStep3) {
		return false;
	}
	if (student) {
		resultPreProcessingStep4 = studentPreProcessing.stepThresholding(*resultPreProcessingStep3);
	} else {
		resultPreProcessingStep4 = defaultPreProcessing.stepThresholding(*resultPreProcessingStep3);
	}
	return resultPreProcessingStep4 != NULL;
}