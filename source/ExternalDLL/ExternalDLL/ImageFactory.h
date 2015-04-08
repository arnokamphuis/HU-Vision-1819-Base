/*
* Copyright (c) 2015 DottedEye Designs, Alexander Hustinx, NeoTech Software, Rolf Smit - All Rights Reserved
* Unauthorized copying of this file, via any medium is strictly prohibited
* Proprietary and confidential
*/

#pragma once
#include "RGBImage.h"
#include "IntensityImage.h"
class ImageFactory {
public:

	static class Implementation {
		public:
			virtual RGBImage * newRGBImage(const int width, const int height) const = 0;
			virtual IntensityImage * newIntensityImage(const int width, const int height) const = 0;
			virtual RGBImage * newRGBImage() const = 0;
			virtual IntensityImage * newIntensityImage() const = 0;
			//virtual ~Implementation();
	};


	static class ImplementationStudent : public Implementation {
		public:
			RGBImage * newRGBImage(const int width, const int height) const;
			IntensityImage * newIntensityImage(const int width, const int height) const;
			RGBImage * newRGBImage() const;
			IntensityImage * newIntensityImage() const;
	};

	static class ImplementationPrivate : public Implementation {
		public:
			RGBImage * newRGBImage(const int width, const int height) const;
			IntensityImage * newIntensityImage(const int width, const int height) const;
			RGBImage * newRGBImage() const;
			IntensityImage * newIntensityImage() const;
	};

	static void setImplementation(ImageFactory::Implementation &implementation);

	static RGBImage * newRGBImage(const int width, const int height);
	static IntensityImage * newIntensityImage(const int width, const int height);
	static RGBImage * newRGBImage();
	static RGBImage * newRGBImage(const RGBImage &other);
	static IntensityImage * newIntensityImage();
	static IntensityImage * newIntensityImage(const IntensityImage &other);
	//rtual ~ImageFactory();


	static ImageFactory::Implementation &DEFAULT;
	static ImageFactory::Implementation &STUDENT;

private:
	static ImageFactory::Implementation * implementation;
	static ImageFactory::Implementation * getImplementation();
};

