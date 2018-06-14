#include "IntensityImage.h"
#include "ImageFactory.h"
#include "Kernel.h"

namespace imgFunc{
	void convolve(const IntensityImage *inputImage, IntensityImage *outputImage, Kernel & kernel);
	void convolve(const IntensityImage &inputImage, IntensityImage *outputImage, Kernel & kernel);
	void combineGradientMagnitude(const IntensityImage *firstImage, const IntensityImage *secondImage, IntensityImage * outputImage);
	void sobelFilter(const IntensityImage * inputImage, IntensityImage * outputImage);
}