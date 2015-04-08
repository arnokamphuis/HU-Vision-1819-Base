/*
* Copyright (c) 2015 DottedEye Designs, Alexander Hustinx, NeoTech Software, Rolf Smit - All Rights Reserved
* Unauthorized copying of this file, via any medium is strictly prohibited
* Proprietary and confidential
*/

#include "ImageIO.h"
#include <opencv2/highgui/highgui.hpp>
#include <direct.h>
#include <stdexcept>
#include <stdlib.h>
#include <iostream>
#include "HereBeDragons.h"

using namespace cv;


std::string ImageIO::debugFolder = "";
bool ImageIO::isInDebugMode = false;

void mkdirs(std::string path){
	if (!ImageIO::isInDebugMode) {
		return;
	}
	int index = 0;
	while ((index = path.find_first_of("\\/", index + 1)) != -1){
		_mkdir(path.substr(0, index).c_str());
	}
	_mkdir(path.c_str());
}

std::string ImageIO::getDebugFileName(std::string file){
	if (ImageIO::debugFolder.size() == 0 && ImageIO::isInDebugMode == true){
		throw std::invalid_argument("Debug folder has not been set!");
	} else if (ImageIO::isInDebugMode != true) {
		return "";
	}
	std::string fullPath = ImageIO::debugFolder;
	fullPath.append("\\");
	fullPath.append(file);
	int index = fullPath.find_last_of("\\/");
	if (index != -1){
		mkdirs(fullPath.substr(0, index));
	}
	return fullPath;
}








bool ImageIO::loadImage(const std::string file, RGBImage &dst) {
	Mat raw = imread(file, CV_LOAD_IMAGE_COLOR);   // Read the file

	if (!raw.data) {
		return false;
	}

	Mat normal;
	raw.convertTo(normal, CV_8UC3);
	HereBeDragons::HeIsContentedThyPoorDrudgeToBe(normal, dst);
	return true;
}

bool ImageIO::saveRGBImage(const RGBImage &src, std::string file){
	if (!ImageIO::isInDebugMode) {
		return false;
	}
	Mat image;
	HereBeDragons::ToStandInThyAffairsFallByThySide(src, image);
	bool r = imwrite(file, image);
	return r;
}

bool ImageIO::saveIntensityImage(const IntensityImage &src, std::string file){
	if (!ImageIO::isInDebugMode) {
		return false;
	}
	Mat image;
	HereBeDragons::HerLoveForWhoseDearLoveIRiseAndFall(src, image);
	bool r = imwrite(file, image);
	return r;
}



void ImageIO::showImage(const RGBImage &src) {
	if (ImageIO::isInDebugMode == false) {
		return;
	}
	Mat image;
	HereBeDragons::ToStandInThyAffairsFallByThySide(src, image);

	if (!image.data) {
		std::cout << "ImageIO::showImage(const RGBImage &src): Could not open the image!" << std::endl;
	} else {
		namedWindow("Display window", WINDOW_AUTOSIZE);
		imshow("Display window", image);
		waitKey(0);
		cvDestroyWindow("Display window");
	}
}


void ImageIO::showImage(const IntensityImage &src) {
	if (ImageIO::isInDebugMode == false) {
		return;
	}
	Mat image;
	HereBeDragons::HerLoveForWhoseDearLoveIRiseAndFall(src, image);

	if (!image.data) {
		std::cout << "ImageIO::showImage(const RGBImage &src): Could not open the image!" << std::endl;
	} else {
		namedWindow("Display window", WINDOW_AUTOSIZE);
		imshow("Display window", image);
		waitKey(0);
		cvDestroyWindow("Display window");
	}
}

void ImageIO::intensityToRGB(const IntensityImage &in, RGBImage &out) {
	out.set(in.getWidth(), in.getHeight());
	for (int x = 0; x < in.getWidth(); x++) {
		for (int y = 0; y < in.getHeight(); y++) {
			unsigned char value = in.getPixel(x, y);
			out.setPixel(x, y, RGB(value, value, value));
		}
	}
}


