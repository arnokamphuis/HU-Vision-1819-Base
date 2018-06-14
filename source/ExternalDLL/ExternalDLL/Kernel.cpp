#include "Kernel.h"
#include <iostream> //std::cout

Kernel::Kernel(const int width, const int height) :
width{ width },
height{ height }
{
	int * p = new int[(width*height)]; //Make one large block of memory to treat like multidimensional array
	kernel = p;

	//Calculate kernel offset
	//x offset
	xOffset = ((width - 1) / 2);

	//y offset
	yOffset = ((height - 1) / 2);
}

Kernel::~Kernel(){
	delete[] kernel;
}

void Kernel::setKernelPoint(const int x, const int y, const int value){
	if (x < width && y<height){
		kernel[x + (y * width)] = value; //Calculate the offset to convert 2d array to 1d
	}
	//todo:
	//Add error handeling for out of bounds
}

void Kernel::parseImageWithKernel(const IntensityImage &inputImage, IntensityImage *outputImage){

	outputImage->set(inputImage.getWidth() - (xOffset * 2), inputImage.getHeight() - (yOffset * 2));

	int max = INT_MIN;
	int min = INT_MAX;

	for (int y = 0; y < outputImage->getHeight(); y++){
		for (int x = 0; x < outputImage->getWidth(); x++){

			float Accumulator = 0;
			//offset bij inputImage optellen
			
			//convolve kernel met inputimage -> output naar outputImage

			//achteruit tellen om kernel te flippen
			int xn = -1;
			int yn = -1;

			for (int i = height - 1; i >= 0; i--){
				for (int j = width - 1; j >= 0; j--){
					Accumulator += (getKernelPoint(i, j) * inputImage.getPixel(x + xOffset + xn, y + yOffset + yn)) / normalize;
					xn += 1;
				}
				yn += 1;
				xn = -1;
			}
			//set outputimage pixel value to accumulator
			//std::cout << "Org image pixel value = " << inputImage.getPixel(x + xOffset, y + yOffset) << "\n"
			//	<< "New = " << Accumulator << "\n";
			
			if (Accumulator >= 255)
			{
				Accumulator = 255;
				std::cout << "+";
			}
			else if (Accumulator < 0){
				Accumulator = 0;
				std::cout << "-";
			}
			if (Accumulator > max){
				max = Accumulator;
			}

			if (Accumulator < min){
				min = Accumulator;
			}

			outputImage->setPixel(x, y, Accumulator);
		}
	}
}

void Kernel::parseImageWithKernel(const IntensityImage *inputImage, IntensityImage *outputImage){

	outputImage->set(inputImage->getWidth() - (xOffset * 2), inputImage->getHeight() - (yOffset * 2));

	int max = INT_MIN;
	int min = INT_MAX;

	int thres = 0;

	for (int y = 0; y < outputImage->getHeight(); y++){
		for (int x = 0; x < outputImage->getWidth(); x++){

			float Accumulator = 0;
			//offset bij inputImage optellen

			//convolve kernel met inputimage -> output naar outputImage

			//achteruit tellen om kernel te flippen
			int xn = -1;
			int yn = -1;

			for (int i = height - 1; i >= 0; i--){
				for (int j = width - 1; j >= 0; j--){
					Accumulator += (getKernelPoint(i, j) * inputImage->getPixel(x + xOffset + xn, y + yOffset + yn)) / normalize;
					xn += 1;
				}
				yn += 1;
				xn = -1;
			}
			//set outputimage pixel value to accumulator
			//std::cout << "Org image pixel value = " << inputImage.getPixel(x + xOffset, y + yOffset) << "\n"
			//	<< "New = " << Accumulator << "\n";

			if (Accumulator > max){
				max = Accumulator;
			}

			if (Accumulator < min){
				min = Accumulator;
			}

			if (Accumulator > 255 | Accumulator < 0){
				thres++;
			}

			if (Accumulator >= 255)
			{
				Accumulator = 255;
				std::cout << "+";
			}
			else if (Accumulator < 0){
				Accumulator = 0;
				std::cout << "-";
			}

			outputImage->setPixel(x, y, Accumulator);	
		}	
	}
	return;
	std::cout << "Max: " << max << "\tMin" << min << "Count:" << thres <<"\n";
	for (int y = 0; y < outputImage->getHeight(); y++){
		for (int x = 0; x < outputImage->getWidth(); x++){
			float Accumulator = 0;
			//offset bij inputImage optellen

			//convolve kernel met inputimage -> output naar outputImage

			//achteruit tellen om kernel te flippen
			int xn = -1;
			int yn = -1;

			for (int i = height - 1; i >= 0; i--){
				for (int j = width - 1; j >= 0; j--){
					Accumulator += (getKernelPoint(i, j) * inputImage->getPixel(x + xOffset + xn, y + yOffset + yn)) / normalize;
					xn += 1;
				}
				yn += 1;
				xn = -1;
			}
			//set outputimage pixel value to accumulator
			//std::cout << "Org image pixel value = " << inputImage.getPixel(x + xOffset, y + yOffset) << "\n"
			//	<< "New = " << Accumulator << "\n";
			/*
			if (Accumulator >= 255)
			{
			Accumulator = 255;
			std::cout << "+";
			}
			else if (Accumulator < 0){
			Accumulator = 0;
			std::cout << "-";
			}*/

			//outputImage->setPixel(x, y, Accumulator);
			if (thres > 1000){
				Accumulator = ((Accumulator - 0) * 255) / (255 - 0);
			}
			else{
				if (Accumulator >= 255)
				{
					Accumulator = UINT8_MAX;
					std::cout << "+";
				}
				else if (Accumulator < 0){
					Accumulator = 0;
					std::cout << "-";
				}
			}
			outputImage->setPixel(x, y, Accumulator);
		}
	}
}


int Kernel::getKernelPoint(const int x, const int y){
	return kernel[x + (y * width)]; //Calculate the offset to convert 2d array to 1d
}

int Kernel::getKernelHeight(){
	return height;
}

int Kernel::getKernelWidth(){
	return width;
}

int Kernel::getKernelxOffset(){
	return xOffset;
}

int Kernel::getKernelyOffset(){
	return yOffset;
}

void Kernel::setKernelNormalize(int x){
	normalize = x;
}

int Kernel::getKernelNormalize(){
	return normalize;
}