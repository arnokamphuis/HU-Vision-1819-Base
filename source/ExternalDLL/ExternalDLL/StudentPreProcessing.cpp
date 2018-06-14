#include "StudentPreProcessing.h"
#include "ImageFactory.h"
#include "Kernel.h"
#include <iostream> //std::cout
#include "Convolve.h"

#include "DefaultPreProcessing.h"
#include "ImageIO.h"
#include "GrayscaleAlgorithm.h"
#include "ImageFactory.h"
#include "HereBeDragons.h"



IntensityImage * StudentPreProcessing::stepToIntensityImage(const RGBImage &image) const {
	return nullptr;
}

IntensityImage * StudentPreProcessing::stepScaleImage(const IntensityImage &image) const {
	return nullptr;
}

IntensityImage * StudentPreProcessing::stepEdgeDetection(const IntensityImage &image) const {
	IntensityImage * gausFilterImage = ImageFactory::newIntensityImage();

	IntensityImage * edgeEnhanceImage = ImageFactory::newIntensityImage();

	IntensityImage * sobelXDetectionImage = ImageFactory::newIntensityImage();

	IntensityImage * sobelYDetectionImage = ImageFactory::newIntensityImage();

	IntensityImage * XRdetection = ImageFactory::newIntensityImage();
	IntensityImage * YRdetection = ImageFactory::newIntensityImage();

	IntensityImage * sobelXimg = ImageFactory::newIntensityImage();
	IntensityImage * sobelYimg = ImageFactory::newIntensityImage();
	IntensityImage * sobelOutput = ImageFactory::newIntensityImage();
	IntensityImage * sobelOutput1 = ImageFactory::newIntensityImage();
	IntensityImage * sobelOutput2 = ImageFactory::newIntensityImage();
	IntensityImage * sobelOutput3 = ImageFactory::newIntensityImage();


	Kernel gausKernel = Kernel(3, 3);

	Kernel sobelLRXKernel = Kernel(3, 3);
	Kernel sobelLRYKernel = Kernel(3, 3);

	Kernel sobelUDXKernel = Kernel(3, 3);
	Kernel sobelUDYKernel = Kernel(3, 3);

	Kernel sobelX = Kernel(3, 3);
	Kernel sobelY = Kernel(3, 3);

	int sobelXDirectionKernel[3][3] = {	{ -1, 0, 1 }, 
										{ -2, 0, 2 }, 
										{ -1, 0,1 } };

	int sobelXRDirectionKernel[3][3] = {	{ 1, 0, -1 },
											{ 2, 0, -2 },
											{ 1, 0, -1 } };

	int sobelYDirectionKernel[3][3] = { { 1, 2, 1 },
										{ 0, 0, 0 },
										{ -1, -2, -1 } };

	int sobelYRDirectionKernel[3][3] = {	{ -1, -2, -1 },
											{ 0, 0, 0 },
											{ 1, 2, 1 } };

	int gausblurKernel[3][3] = {	{ 1, 2, 1 },
								{ 2, 4, 2 },
								{ 1, 2, 1 } };

	int normKernel[3][3] = {	{ 0, 0, 0 },
								{ 0, 1, 0},
								{ 0, 0, 0 } };

	int edgeEnhance[3][3] = { { -1, -1, -1 },
	{ -1, 1, -1 },
	{ -1, -1, -1 } };




	int sobelXkernel[3][3] = { { -3, 0, 3 },
	{ -10, 0, 10 },
	{ -3, 0, 3 } };

	int sobelYkernel[3][3] = { { 3, 10, 3 },
	{ 0, 0, 0 },
	{ -3, -10, -3 } };

	gausKernel.setKernel(normKernel);
	//gausKernel.setKernelNormalize(16);

	sobelX.setKernel(sobelXkernel);
	sobelY.setKernel(sobelYkernel);



	//sobelLRXKernel.setKernel(sobelXDirectionKernel);
	//sobelLRYKernel.setKernel(sobelXRDirectionKernel);

	//sobelUDXKernel.setKernel(sobelYDirectionKernel);
	//sobelUDYKernel.setKernel(sobelYRDirectionKernel);

	//gausKernel.parseImageWithKernel(image, gausFilterImage);

	imgFunc::convolve(image, gausFilterImage, gausKernel);

	//imgFunc::convolve(gausFilterImage, sobelXimg, sobelX);
	//imgFunc::convolve(gausFilterImage, sobelYimg, sobelY);

	imgFunc::edgeEnhance(gausFilterImage, edgeEnhanceImage);

	return edgeEnhanceImage;

	//abs combine
	//imgFunc::combineGradientMagnitude(sobelXimg, sobelYimg, sobelOutput);

	imgFunc::sobelFilter(edgeEnhanceImage, sobelOutput);

	return sobelOutput;

	//imgFunc::convolve(sobelOutput, gausFilterImage, gausKernel);

	imgFunc::sobelFilter(sobelOutput, sobelOutput1);
	imgFunc::sobelFilter(sobelOutput1, sobelOutput2);
	imgFunc::sobelFilter(sobelOutput2, sobelOutput3);

	return gausFilterImage;

	sobelLRXKernel.parseImageWithKernel(gausFilterImage, sobelXDetectionImage);
	sobelLRYKernel.parseImageWithKernel(gausFilterImage, sobelYDetectionImage);

	sobelUDXKernel.parseImageWithKernel(gausFilterImage, XRdetection);
	sobelUDYKernel.parseImageWithKernel(gausFilterImage, YRdetection);

	std::cout << sobelUDXKernel;

	std::cout << sobelLRXKernel;

	//combining

	for (int y = 0; y < sobelXDetectionImage->getHeight(); y++){
		for (int x = 0; x < sobelXDetectionImage->getWidth(); x++){
			int pixelValue1 = sobelXDetectionImage->getPixel(x, y);
			int pixelValue2 = sobelYDetectionImage->getPixel(x, y);

			sobelXDetectionImage->setPixel(x, y, sqrt(pow(pixelValue1, 2) + pow(pixelValue2, 2)));
		}
	}

	//return sobelXDetectionImage;

	for (int y = 0; y < XRdetection->getHeight(); y++){
		for (int x = 0; x < XRdetection->getWidth(); x++){
			int pixelValue1 = XRdetection->getPixel(x, y);
			int pixelValue2 = YRdetection->getPixel(x, y);

			XRdetection->setPixel(x, y, sqrt(pow(pixelValue1, 2) + pow(pixelValue2, 2)));
		}
	}

	return XRdetection;

	for (int y = 0; y < XRdetection->getHeight(); y++){
		for (int x = 0; x < XRdetection->getWidth(); x++){
			int pixelValue1 = XRdetection->getPixel(x, y);
			int pixelValue2 = sobelXDetectionImage->getPixel(x, y);

			int newPixel = sqrt(pow(pixelValue1, 2) + pow(pixelValue2, 2));

			if (newPixel > 255){
				newPixel = 255;
			}
			else if(newPixel < 0){
				newPixel = 0;
			}

			XRdetection->setPixel(x, y, newPixel);
		}
	}

	//Kernel filter over image, wegschrijven in foto edgeDetectionImage / optioneel, testen met verschillende opties 

	//Kernel parsen (edge detection kernel, sobel, canny) over image, wegschrijven in foto edgeDetectionImage

	return XRdetection;
	//code voor edge detection hierzo
	
}

IntensityImage * StudentPreProcessing::stepThresholding(const IntensityImage &src) const {
	cv::Mat OverHillOverDale;
	HereBeDragons::HerLoveForWhoseDearLoveIRiseAndFall(src, OverHillOverDale);
	//cv::threshold(OverHillOverDale, OverHillOverDale, 220, 255, cv::THRESH_BINARY_INV);

	//cv::adaptiveThreshold(OverHillOverDale, OverHillOverDale, 255, cv::ADAPTIVE_THRESH_MEAN_C, cv::THRESH_BINARY_INV, 11, 2);

	cv::threshold(OverHillOverDale, OverHillOverDale, 116, 255, cv::THRESH_BINARY_INV);

	//cv::threshold(OverHillOverDale, OverHillOverDale, 0, 255, CV_THRESH_BINARY_INV | CV_THRESH_OTSU);
	IntensityImage * ThoroughBushThoroughBrier = ImageFactory::newIntensityImage();
	HereBeDragons::NoWantOfConscienceHoldItThatICall(OverHillOverDale, *ThoroughBushThoroughBrier);
	return ThoroughBushThoroughBrier;
}