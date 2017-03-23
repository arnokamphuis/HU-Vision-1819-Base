#include "IntensityImageStudent.h"
#include <algorithm>

IntensityImageStudent::IntensityImageStudent() : IntensityImage() {
}

IntensityImageStudent::IntensityImageStudent(const IntensityImageStudent &other) : IntensityImage(other.getWidth(), other.getHeight()) {
	pixels = other.getPixels();
}

IntensityImageStudent::IntensityImageStudent(const int width, const int height) : IntensityImage(width, height) {
	pixels.reserve(width * height);
}

IntensityImageStudent::~IntensityImageStudent() {
	pixels.clear();
}

IntensityImageStudent::IntensityImageStudent(const RGBImageStudent &other) : IntensityImageStudent(other.getWidth(), other.getHeight()) {
	convertRGBImageStudentToIntensityImageStudent(other);
}

void IntensityImageStudent::set(const int width, const int height) {
	int size = getWidth() * getHeight();
	IntensityImage::set(width, height);
	if (size > width * height)
	{
		// previous vector size is larger than required
		int offset = size - width * height;
		pixels.erase(pixels.end() - offset, pixels.end());
	}
	else
	{
		// required vector size is larger than current vector
		pixels.reserve(width * height);
	}
}

void IntensityImageStudent::set(const IntensityImageStudent &other) {
	IntensityImage::set(other.getWidth(), other.getHeight());
	pixels = other.getPixels();
}

void IntensityImageStudent::set(const RGBImageStudent &other) {
	int size = getWidth() * getHeight();
	IntensityImage::set(other.getWidth(), other.getHeight());
	if (size > other.getWidth() * other.getHeight())
	{
		// previous vector size is larger than required
		int offset = size - other.getWidth() * other.getHeight();
		pixels.erase(pixels.end() - offset, pixels.end());
	}
	else
	{
		// required vector size is larger than current vector
		pixels.reserve(other.getWidth() * other.getHeight());
	}
	convertRGBImageStudentToIntensityImageStudent(other);
}

void IntensityImageStudent::setPixel(int x, int y, Intensity pixel) {
	pixels[x + (y * getWidth())] = pixel;
}

void IntensityImageStudent::setPixel(int i, Intensity pixel) {
	pixels[i] = pixel;
}

Intensity IntensityImageStudent::getPixel(int x, int y) const {
	return pixels[x + (y * getWidth())];
}

Intensity IntensityImageStudent::getPixel(int i) const {
	return pixels[i];
}

std::vector<Intensity> IntensityImageStudent::getPixels() const {
	return pixels;
}

void IntensityImageStudent::convertRGBImageStudentToIntensityImageStudent(const RGBImageStudent &input) {
	// Values for calculating Intensity as defined in BT.709 by ITU-R
	// See https://www.itu.int/rec/R-REC-BT.709/en for more info
	static const double rVal = 0.2126;
	static const double gVal = 0.7152;
	static const double bVal = 0.0722;

	int amountOfPixels = input.getWidth() * input.getHeight();
	for (int i = 0; i < amountOfPixels; i++) {
		RGB rgb = input.getPixel(i);
		setPixel(i, Intensity( (rVal * rgb.r) + (gVal * rgb.g) + (bVal * rgb.b) ));
	}
}