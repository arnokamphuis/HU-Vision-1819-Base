#include <stdint.h>
#include <stdio.h>
#include <iostream>
#pragma once


class Kernel{
public:
	Kernel(const int8_t width, const  int8_t height);
	~Kernel();

	void setKernelPoint(const int8_t x, const int8_t y, const int8_t value);

	int8_t getKernelPoint(const int8_t x, const int8_t y);

	int8_t getKernelWidth();

	int8_t getKernelHeight();

template<typename T, int8_t arrWidth, int8_t arrHeight>
void setKernel(T(&Myarray)[arrWidth][arrHeight]){
	for (size_t i = 0; i < arrHeight; ++i){
		for (size_t j = 0; j < arrWidth; ++j){
			int arrPos = j + (i * arrWidth);
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

	return os;
}

private:
	int8_t width;
	int8_t height;
	int * kernel;
	//int kern_test[9];
};