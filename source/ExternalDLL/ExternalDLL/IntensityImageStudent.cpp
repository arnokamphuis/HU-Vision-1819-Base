#include "IntensityImageStudent.h"
#include <functional>
#include <algorithm>  
#include <vector>

IntensityImageStudent::IntensityImageStudent() : IntensityImage() {}
IntensityImageStudent::IntensityImageStudent(const IntensityImageStudent &other) : IntensityImage(other.getWidth(), other.getHeight()) {}
IntensityImageStudent::IntensityImageStudent(const int width,  const int height) : IntensityImage(width, height) {}
IntensityImageStudent::IntensityImageStudent(const RGBImage & image)
{
	int h = image.getHeight();
	int w = image.getWidth();
	set(w, h);


	for (int x = 0; x < w; x++) {
		for (int y = 0; y < h; y++) {
			setPixel(x, y, image.getPixel(x, y));
		}
	}
}

IntensityImageStudent::~IntensityImageStudent() {}

void IntensityImageStudent::set(const int width, const int height) {
	IntensityImage::set(width, height);
}

void IntensityImageStudent::set(const IntensityImageStudent &other) {
	IntensityImage::set(other.getWidth(), other.getHeight());
}

int IntensityImageStudent::getPosition(int x, int y) const{
	// TODO: bitshifting SHOULD faster
	return (x << 8) + y;
}

Intensity RGBtoIntensity(RGB pixel) {


	//return Intensity((pixel.r * 0.2126 + pixel.g * 0.7152 + pixel.b * 0.0722)); // ITU-R BT-709
	//return Intensity((pixel.r * 0.299 + pixel.g * 0.587 + pixel.b * 0.114)); // ITU-R BT-601 
	//return Intensity((pixel.r * 0.3 + pixel.g * 0.59 + pixel.b * 0.11)); // GIMP, Photoshop

	//std::vector<int> colors = { pixel.r, pixel.g, pixel.b };


	//return Intensity(colors. + std::min(pixel.r, pixel.g, pixel.b)); // Desaturation


	//return Intensity(pixel.r);
	//return Intensity(pixel.g);
	//return Intensity(pixel.b);


	//return Intensity((pixel.r + pixel.g + pixel.b) / 3); // average

	return Intensity((pixel.r * 0.3) + (pixel.g * 0.59) + (pixel.b * 0.11));;
}

void IntensityImageStudent::setPixel(int x, int y, RGB pixel){
	setPixel(getPosition(x, y), RGBtoIntensity(pixel));
}

void IntensityImageStudent::setPixel(int x, int y, Intensity pixel) {
	pixels[getPosition(x, y)] = pixel;
}

void IntensityImageStudent::setPixel(int i, Intensity pixel) {
	int rows = i / getWidth();
	int colums = i % getWidth();

	setPixel(rows, colums);
}

Intensity IntensityImageStudent::getPixel(int x, int y) const {
	return getPixel(getPosition(x, y));
}

Intensity IntensityImageStudent::getPixel(int i) const {
	return pixels.at(i);
}