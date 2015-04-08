/*
* Copyright (c) 2015 DottedEye Designs, Alexander Hustinx, NeoTech Software, Rolf Smit - All Rights Reserved
* Unauthorized copying of this file, via any medium is strictly prohibited
* Proprietary and confidential
*/

#pragma once


#include "RGBImage.h"
#include "IntensityImage.h"
#include <opencv2/imgproc/imgproc.hpp>
#include <string>


class ImageIO {
public:

	//Debug
	static std::string debugFolder;
	static bool isInDebugMode;

	static std::string getDebugFileName(std::string file);

	//Load
	static bool loadImage(const std::string file, RGBImage &dst);

	//Save
	static bool saveRGBImage(const RGBImage &image, std::string file);
	static bool saveIntensityImage(const IntensityImage &image, std::string file);

	//Show
	static void showImage(const IntensityImage &image);
	static void showImage(const RGBImage &image);

	//Convert
	static void intensityToRGB(const IntensityImage &in, RGBImage &out);
};

