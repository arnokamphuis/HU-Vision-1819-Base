#include "RGBImageStudent.h"

RGBImageStudent::RGBImageStudent() : RGBImage() {}

RGBImageStudent::RGBImageStudent(const RGBImageStudent &other) : RGBImage(other.getWidth(), other.getHeight()) {
	set(other);
}

RGBImageStudent::RGBImageStudent(const int width, const int height) : RGBImage(width, height) {
	set(width, height);
}

RGBImageStudent::~RGBImageStudent() {}

void RGBImageStudent::set(const int width, const int height) {
	RGBImage::set(width, height);
	pixels.clear();
}

void RGBImageStudent::set(const RGBImageStudent &other) {
	RGBImage::set(other.getWidth(), other.getHeight());
	pixels.clear();
	pixels = getPixels();
}

int RGBImageStudent::getPosition(int x, int y) const{
	// TODO : bitshift SHOULD be faster
	return (x * 1000) + y;
}

std::unordered_map<int, RGB> RGBImageStudent::getPixels() {
	return pixels;
}
void RGBImageStudent::setPixel(int x, int y, RGB pixel) {
	setPixel(getPosition(x, y), pixel);
}

void RGBImageStudent::setPixel(int i, RGB pixel) {
	pixels[i] = pixel;
}

RGB RGBImageStudent::getPixel(int x, int y) const {
	return getPixel(getPosition(x, y));
}

RGB RGBImageStudent::getPixel(int i) const {
	return pixels.at(i);
}