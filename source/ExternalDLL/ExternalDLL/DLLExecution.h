/*
* Copyright (c) 2015 DottedEye Designs, Alexander Hustinx, NeoTech Software, Rolf Smit - All Rights Reserved
* Unauthorized copying of this file, via any medium is strictly prohibited
* Proprietary and confidential
*/

#pragma once
#include "RGBImage.h"
#include "StudentPreProcessing.h"
#include "DefaultPreProcessing.h"
#include "DefaultLocalization.h"
#include "StudentLocalization.h"
#include "DefaultExtraction.h"
#include "StudentExtraction.h"
#include "PostProcessing.h"
#include "Representation.h"

class DLLExecution {
public:

	//Face recognition steps
	//Pre-processing
	StudentPreProcessing studentPreProcessing;
	DefaultPreProcessing defaultPreProcessing;
	//Localization
	StudentLocalization studentLocalization;
	DefaultLocalization defaultLocalization;
	//Extraction
	DefaultExtraction defaultExtraction;
	StudentExtraction studentExtraction;
	//Post-Processing
	PostProcessing postProcessing;
	//Representation
	Representation representation;




	//Down scaled features for the localization steps and normal features for the extraction
	FeatureMap featuresScaled;
	FeatureMap features;



	//Images
	RGBImage * inputImage;
	IntensityImage * resultPreProcessingStep1;
	IntensityImage * resultPreProcessingStep2;
	IntensityImage * resultPreProcessingStep3;
	IntensityImage * resultPreProcessingStep4;


	//Debug images
	RGBImage * localizationDebug;
	RGBImage * extractionDebug;


	bool hasPreparedLocalization;
	bool hasPreparedExtraction;
	double downScaleFactor;


	double facialParameters[16];


	DLLExecution(RGBImage * inputImage);
	~DLLExecution();



	bool executePreProcessingStep1(bool student);
	bool executePreProcessingStep2(bool student);
	bool executePreProcessingStep3(bool student);
	bool executePreProcessingStep4(bool student);


	bool prepareLocalization();
	bool executeLocalizationStep1(bool student);
	bool executeLocalizationStep2(bool student);
	bool executeLocalizationStep3(bool student);
	bool executeLocalizationStep4(bool student);
	bool executeLocalizationStep5(bool student);


	bool prepareExtraction();
	bool executeExtractionStep1(bool student);
	bool executeExtractionStep2(bool student);
	bool executeExtractionStep3(bool student);


	bool executePostProcessing();
	bool executeRepresentation();


};

