#include "IntensityImageStudent.h"

IntensityImageStudent::IntensityImageStudent() : IntensityImage() {
	//int throwError = 0, e = 1 / throwError; //Throws error without the need to include a header
	//TODO: Nothing
}

IntensityImageStudent::IntensityImageStudent(const IntensityImageStudent &other) : IntensityImage(other.getWidth(), other.getHeight()) {
	int throwError = 0, e = 1 / throwError;
	//TODO: Create a copy from the other object
}

IntensityImageStudent::IntensityImageStudent(const int width, const int height) : IntensityImage(width, height) {
	
	//TODO: Initialize pixel storage
}

IntensityImageStudent::~IntensityImageStudent() {
	int throwError = 0, e = 1 / throwError;
	//TODO: delete allocated objects
}

void IntensityImageStudent::set(const int width, const int height) {
	IntensityImage::set(width, height);
	int throwError = 0, e = 1 / throwError;
	//TODO: resize or create a new pixel storage (Don't forget to delete the old storage)
}

void IntensityImageStudent::set(const IntensityImageStudent &other) {
	IntensityImage::set(other.getWidth(), other.getHeight());

}

int IntensityImageStudent::getPosition(int x, int y) const
{
	// TODO: bitshifting SHOULD faster
	return x * 1000 + y;
}

Intensity RGBtoIntensity(RGB pixel) {
	Intensity intensity = (pixel.r * 0.3) + (pixel.g* 0.59) + (pixel.b * 0.11);
//	Intensity intensity = (pixel.r + pixel.g + pixel.b) / 3;
//	Intensity intensity = pixel.r;
//	Intensity intensity = pixel.g;
//	Intensity intensity = pixel.b;

	return intensity;
}

void IntensityImageStudent::setPixel(int x, int y, RGB pixel)
{
	setPixel(getPosition(x, y), RGBtoIntensity(pixel));
}

void IntensityImageStudent::setPixel(int x, int y, Intensity pixel) {
	setPixel(getPosition(x, y), pixel);
}

void IntensityImageStudent::setPixel(int i, Intensity pixel) {
	pixels[i] = pixel;
}

Intensity IntensityImageStudent::getPixel(int x, int y) const {
	return getPixel(getPosition(x, y));
}

Intensity IntensityImageStudent::getPixel(int i) const {
	return pixels.at(i);
}