#include "RGBImageStudent.h"

RGBImageStudent::RGBImageStudent() : RGBImage() {}

RGBImageStudent::RGBImageStudent(const RGBImageStudent &other) : RGBImage(other.getWidth(), other.getHeight()) {
	pixels = other.getPixels();
}


RGBImageStudent::RGBImageStudent(const int width, const int height) : RGBImage(width, height) {
	pixels.reserve(width * height);
}

RGBImageStudent::~RGBImageStudent() {
	pixels.clear();
}

void RGBImageStudent::set(const int width, const int height) {
	RGBImage::set(width, height);
	pixels.reserve(width * height);
}

void RGBImageStudent::set(const RGBImageStudent &other) {
	RGBImage::set(other.getWidth(), other.getHeight());
	pixels = other.getPixels();
}

void RGBImageStudent::setPixel(int x, int y, RGB pixel)
{
	pixels[x + (y * getWidth())] = pixel;
}

void RGBImageStudent::setPixel(int i, RGB pixel) {
	pixels[i] = pixel;
}

RGB RGBImageStudent::getPixel(int x, int y) const {
	return pixels[x + (y * getWidth())];
}

RGB RGBImageStudent::getPixel(int i) const {
	return pixels[i];
}

std::vector<RGB> RGBImageStudent::getPixels() const
{
	return pixels;
}
