/*
* Copyright (c) 2015 DottedEye Designs, Alexander Hustinx, NeoTech Software, Rolf Smit - All Rights Reserved
* Unauthorized copying of this file, via any medium is strictly prohibited
* Proprietary and confidential
*/

#include "export.h"

#include <iostream>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "ImageIO.h"
#include "ImageFactory.h"

using namespace cv;





DLLExecution * getDLLExecutionTask(RGBImage * image) {
	DLLExecution * task = new DLLExecution(image);
	return task;
}

void freeDLLExecutionTask(DLLExecution * dllExecution) {
	delete dllExecution;
}

void setImageImplementation(bool student) {
	if (student) {
		//std::cout << "Implementation student!" << std::endl;
		ImageFactory::setImplementation(ImageFactory::STUDENT);
	} else {
		//std::cout << "Implementation private!" << std::endl;
		ImageFactory::setImplementation(ImageFactory::DEFAULT);
	}
}



bool executePreProcessingStep1(DLLExecution * dllExecution, bool student) {
	return dllExecution->executePreProcessingStep1(student);
}
bool executePreProcessingStep2(DLLExecution * dllExecution, bool student) {
	return dllExecution->executePreProcessingStep2(student);
}
bool executePreProcessingStep3(DLLExecution * dllExecution, bool student) {
	return dllExecution->executePreProcessingStep3(student);
}
bool executePreProcessingStep4(DLLExecution * dllExecution, bool student) {
	return dllExecution->executePreProcessingStep4(student);
}

RGBImage * getResultPreProcessingStep1(DLLExecution * dllExecution) {
	RGBImage * imageRGB = ImageFactory::newRGBImage(dllExecution->resultPreProcessingStep1->getWidth(), dllExecution->resultPreProcessingStep1->getHeight());

	//std::cout << "getResultPreProcessingStep1: " << imageRGB->getWidth() << " " << imageRGB->getHeight() << std::endl;


	ImageIO::intensityToRGB(*dllExecution->resultPreProcessingStep1, *imageRGB);

	//std::cout << "getResultPreProcessingStep1: " << imageRGB->getWidth() << " " << imageRGB->getHeight() << std::endl;

	//printf("Address of x is %p\n", (void*) imageRGB);

	return imageRGB;
}

RGBImage * getResultPreProcessingStep2(DLLExecution * dllExecution) {
	RGBImage * imageRGB = ImageFactory::newRGBImage(dllExecution->resultPreProcessingStep2->getWidth(), dllExecution->resultPreProcessingStep2->getHeight());
	ImageIO::intensityToRGB(*dllExecution->resultPreProcessingStep2, *imageRGB);
	return imageRGB;
}

RGBImage * getResultPreProcessingStep3(DLLExecution * dllExecution) {
	RGBImage * imageRGB = ImageFactory::newRGBImage(dllExecution->resultPreProcessingStep3->getWidth(), dllExecution->resultPreProcessingStep3->getHeight());
	ImageIO::intensityToRGB(*dllExecution->resultPreProcessingStep3, *imageRGB);
	return imageRGB;
}

RGBImage * getResultPreProcessingStep4(DLLExecution * dllExecution) {
	RGBImage * imageRGB = ImageFactory::newRGBImage(dllExecution->resultPreProcessingStep4->getWidth(), dllExecution->resultPreProcessingStep4->getHeight());
	ImageIO::intensityToRGB(*dllExecution->resultPreProcessingStep4, *imageRGB);
	return imageRGB;
}




bool prepareLocalization(DLLExecution * dllExecution) {
	return dllExecution->prepareLocalization();
}
bool executeLocalizationStep1(DLLExecution * dllExecution, bool student) {
	return dllExecution->executeLocalizationStep1(student);
}
bool executeLocalizationStep2(DLLExecution * dllExecution, bool student) {
	return dllExecution->executeLocalizationStep2(student);
}
bool executeLocalizationStep3(DLLExecution * dllExecution, bool student) {
	return dllExecution->executeLocalizationStep3(student);
}
bool executeLocalizationStep4(DLLExecution * dllExecution, bool student) {
	return dllExecution->executeLocalizationStep4(student);
}
bool executeLocalizationStep5(DLLExecution * dllExecution, bool student) {
	return dllExecution->executeLocalizationStep5(student);
}


RGBImage * getLocalizationDebugImage(DLLExecution * dllExecution) {
	return dllExecution->localizationDebug;
}




bool prepareExtraction(DLLExecution * dllExecution) {
	return dllExecution->prepareExtraction();
}
bool executeExtractionStep1(DLLExecution * dllExecution, bool student) {
	return dllExecution->executeExtractionStep1(student);
}
bool executeExtractionStep2(DLLExecution * dllExecution, bool student) {
	return dllExecution->executeExtractionStep2(student);
}
bool executeExtractionStep3(DLLExecution * dllExecution, bool student) {
	return dllExecution->executeExtractionStep3(student);
}
RGBImage * getExtractionDebugImage(DLLExecution * dllExecution) {
	return dllExecution->extractionDebug;
}








bool executePostProcessing(DLLExecution * dllExecution) {
	return dllExecution->executePostProcessing();
}
bool executeRepresentation(DLLExecution * dllExecution) {
	return dllExecution->executeRepresentation();
}

void getFacialParameters(DLLExecution * dllExecution, double facialParameters[]) {
	for (int i = 0; i < 16; i++) {
		facialParameters[i] = dllExecution->facialParameters[i];
	}
}

















int getVersion(){
	return 1;
}



RGBImage * imageNewRGB(int width, int height){
	RGBImage * image = ImageFactory::newRGBImage(width, height);

	//std::cout << "native created image: " << image->getWidth() << " " << image->getHeight() << std::endl;


	return image;
}

void imageFreeRGB(RGBImage * image) {
	delete image;
}

int imageWidth(Image * image) {
	//ImageIO::showImage(*image);
	//std::cout << "c++: imageWidth: " << image->getWidth() << std::endl;
	return image->getWidth();
}

int imageHeight(Image * image) {
	//ImageIO::showImage(*image);
	//std::cout << "c++: imageHeight: " << image->getHeight() << std::endl;
	return image->getHeight();
}





RGBImage * getRGBImageFromData(int width, int height, unsigned char * pixels, int stride) {
	//std::cout << "c++: getRGBImageFromData: " << width << "x" << height << " stride: " << stride << std::endl;
	RGBImage * image = ImageFactory::newRGBImage(width, height);


	//std::cout << "size: " << image->getWidth() << "x" << image->getHeight() << " stride: " << stride << std::endl;

	int size = image->getHeight() * image->getWidth();

	int count = 0;
	for (int y = 0; y < height; y++) {
		count = y * stride;
		for (int x = 0; x < width; x++) {
			RGB rgb;
			rgb.b = pixels[count];
			rgb.g = pixels[count + 1];
			rgb.r = pixels[count + 2];
			image->setPixel(y * width + x, rgb);
			count += 3;
		}
	}
	//std::cout << "c++: getRGBImageFromData: return" << std::endl;
	return image;
}



void getImageBytes(RGBImage * image, unsigned char * pixels, int stride){

	int size = image->getHeight() * image->getWidth();

	int width = image->getWidth();
	int height = image->getHeight();


	//std::cout << "width: " << width << std::endl;
	//std::cout << "Height: " << height << std::endl;

	int count = 0;

	for (int y = 0; y < height; y++){
		count = y * stride;
		for (int x = 0; x < width; x++){
			RGB rgb = image->getPixel(y * width + x);
			pixels[count] = rgb.b;
			pixels[count + 1] = rgb.g;
			pixels[count + 2] = rgb.r;
			count += 3;
		}
	}
}

void openImageWithOpenCV(char * file){
	Mat image = imread(file, CV_LOAD_IMAGE_COLOR); //load image
	if (!image.data){
		std::cout << "Could not open or find the image" << std::endl;
	} else {
		namedWindow("Display window", WINDOW_AUTOSIZE); //Create a window for display.
		imshow("Display window", image); //Show the image inside the window.
		waitKey(0);
	}
}