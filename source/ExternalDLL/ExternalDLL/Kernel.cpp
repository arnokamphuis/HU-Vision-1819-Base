#include "Kernel.h"

Kernel::Kernel(const int8_t width, const int8_t height) :
width{ width },
height{ height }
{
	int * p = new int[(width*height)]; //Make one large block of memory to treat like multidimensional array
	kernel = p;
}

Kernel::~Kernel(){
	delete[] kernel;
}

void Kernel::setKernelPoint(const int8_t x, const int8_t y, const int8_t value){
	if (x < width && y<height){
		kernel[x + (y * width)] = value; //Calculate the offset to convert 2d array to 1d
	}

	//todo:
	//Add error handeling for out of bounds
}

int8_t Kernel::getKernelPoint(const int8_t x, const int8_t y){
	return kernel[x + (y * width)]; //Calculate the offset to convert 2d array to 1d
}

int8_t Kernel::getKernelHeight(){
	return height;
}

int8_t Kernel::getKernelWidth(){
	return width;
}