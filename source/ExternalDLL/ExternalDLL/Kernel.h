#include <stdint.h>
#include <stdio.h>
#include <iostream>
#include "StudentPreProcessing.h"
#pragma once


class Kernel{
public:
	Kernel(const int width, const  int height);
	Kernel(const int width, const  int height, int & arr);
	~Kernel();

	void setKernelPoint(const int x, const int y, const int value);

	int getKernelPoint(const int x, const int y);

	int getKernelWidth();

	int getKernelHeight();

	int getKernelxOffset();

	int getKernelyOffset();

	void setKernelNormalize(int x);

	int getKernelNormalize();

	void parseImageWithKernel(const IntensityImage &originalImage, IntensityImage *resultImage);
	void parseImageWithKernel(const IntensityImage *originalImage, IntensityImage *resultImage);

template<typename T, int arrWidth, int arrHeight>
void setKernel(T(&Myarray)[arrWidth][arrHeight]){
	for (size_t i = 0; i < arrHeight; ++i){
		for (size_t j = 0; j < arrWidth; ++j){
			int arrPos = i + (j * arrWidth);
			kernel[arrPos] = Myarray[i][j];
			//kern_test[arrPos] = Myarray[i][j];
		}
	}
}

friend std::ostream& operator<<(std::ostream& os, Kernel& obj){
	os << "\t\tKernel values\n-------------------------\n";
	for (size_t i = 0; i < obj.getKernelWidth(); i++)
	{
		for (size_t j = 0; j < obj.getKernelHeight(); j++)
		{
			os << "Line: " << i << " Row: " << j << " Value: " << int(obj.getKernelPoint(i, j)) << "\n";
		}
	}
	os << "\n------------------------\n";

	for (size_t i = 0; i < obj.getKernelWidth(); i++)
	{
		for (size_t j = 0; j < obj.getKernelHeight(); j++)
		{
			os << int(obj.getKernelPoint(i, j)) << " ";
		}
		os << "\n";
	}

	os << "xoffset = " << obj.xOffset << "\tyOffset = " << obj.yOffset;

	return os;
}

private:
	int width;
	int height;

	int xOffset;
	int yOffset;

	int * kernel;
	//int kern_test[9];

	int normalize = 1;
};