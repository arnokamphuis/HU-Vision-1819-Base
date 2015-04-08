/*
* Copyright (c) 2015 DottedEye Designs, Alexander Hustinx, NeoTech Software, Rolf Smit - All Rights Reserved
* Unauthorized copying of this file, via any medium is strictly prohibited
* Proprietary and confidential
*/

#include "GrayscaleAlgorithm.h"
#include "ImageIO.h"
#include "HereBeDragons.h"

using namespace cv;

GrayscaleAlgorithm::GrayscaleAlgorithm()
{
}


GrayscaleAlgorithm::~GrayscaleAlgorithm()
{
}


void GrayscaleAlgorithm::doAlgorithm(const RGBImage &src, IntensityImage &dst){
	Mat image;
	HereBeDragons::ToStandInThyAffairsFallByThySide(src, image);
	cvtColor(image, image, CV_RGB2GRAY);

	//equalizeHist(*image, *image);

	HereBeDragons::NoWantOfConscienceHoldItThatICall(image, dst);
}

