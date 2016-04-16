#include <algorithm>

#include "RGBImageStudent.h"

RGBImageStudent::RGBImageStudent() : RGBImage() {
	RGBImage::set(0, 0);
	this->pixels = new RGB[0];
}

RGBImageStudent::RGBImageStudent(const RGBImageStudent &other) : RGBImage(other.getWidth(), other.getHeight()) {
	this->set(other);
}

RGBImageStudent::RGBImageStudent(const int width, const int height) : RGBImage(width, height) {
	RGBImage::set(width, height);
	this->pixels = new RGB[width * height];
}

RGBImageStudent::~RGBImageStudent() {
	delete[] this->pixels;
}

void RGBImageStudent::set(const int width, const int height) {
	int newNumPixels = width * height;
	RGB* newPixels = new RGB[newNumPixels];

	int minWidth = std::min(width, this->getWidth());
	int minHeight = std::min(height, this->getHeight());

	for (int x = 0; x < minWidth; x++){
		for (int y = 0; y < minHeight; y++){
			newPixels[y * width + x] = this->pixels[y * this->getWidth() + x];
		}
	}

	delete[] this->pixels;
	this->pixels = newPixels;
	RGBImage::set(width, height);
}

void RGBImageStudent::set(const RGBImageStudent &other) {
	RGBImage::set(other.getWidth(), other.getHeight());

	delete[] this->pixels;

	int numPixels = other.getWidth() * other.getHeight();
	this->pixels = new RGB[numPixels];

	for (int i = 0; i < numPixels; i++){
		this->pixels[i] = other.getPixel(i);
	}
}

void RGBImageStudent::setPixel(int x, int y, RGB pixel) {
	this->pixels[y * this->getWidth() + x] = pixel;
}

void RGBImageStudent::setPixel(int i, RGB pixel) {
	this->pixels[i] = pixel;
}

RGB RGBImageStudent::getPixel(int x, int y) const {
	return this->pixels[y * this->getWidth() + x];
}

RGB RGBImageStudent::getPixel(int i) const {
	return this->pixels[i];
}