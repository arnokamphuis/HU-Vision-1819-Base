#include <algorithm>

#include "IntensityImageStudent.h"

IntensityImageStudent::IntensityImageStudent() : IntensityImage() {
	IntensityImage::set(0, 0);
	this->pixels = new Intensity[0];
}

IntensityImageStudent::IntensityImageStudent(const IntensityImageStudent &other) : IntensityImage(other.getWidth(), other.getHeight()) {
	this->set(other);
}

IntensityImageStudent::IntensityImageStudent(const int width, const int height) : IntensityImage(width, height) {
	IntensityImage::set(width, height);
	this->pixels = new Intensity[width * height];
}

IntensityImageStudent::~IntensityImageStudent() {
	delete[] this->pixels;
}

void IntensityImageStudent::set(const int width, const int height) {
	int newNumPixels = width * height;
	Intensity* newPixels = new Intensity[newNumPixels];

	int minWidth = std::min(width, this->getWidth());
	int minHeight = std::min(height, this->getHeight());

	for (int x = 0; x < minWidth; x++){
		for (int y = 0; y < minHeight; y++){
			newPixels[y * width + x] = this->pixels[y * this->getWidth() + x];
		}
	}

	delete[] this->pixels;
	this->pixels = newPixels;
	IntensityImage::set(width, height);
}

void IntensityImageStudent::set(const IntensityImageStudent &other) {
	IntensityImage::set(other.getWidth(), other.getHeight());

	delete[] this->pixels;

	int numPixels = other.getWidth() * other.getHeight();
	this->pixels = new Intensity[numPixels];

	for (int i = 0; i < numPixels; i++){
		this->pixels[i] = other.getPixel(i);
	}
}

void IntensityImageStudent::setPixel(int x, int y, Intensity pixel) {
	this->pixels[y * this->getWidth() + x] = pixel;
}

void IntensityImageStudent::setPixel(int i, Intensity pixel) {
	this->pixels[i] = pixel;
}

Intensity IntensityImageStudent::getPixel(int x, int y) const {
	return this->pixels[y * this->getWidth() + x];
}

Intensity IntensityImageStudent::getPixel(int i) const {
	return this->pixels[i];
}