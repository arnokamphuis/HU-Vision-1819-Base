/*
* Copyright (c) 2015 DottedEye Designs, Alexander Hustinx, NeoTech Software, Rolf Smit - All Rights Reserved
* Unauthorized copying of this file, via any medium is strictly prohibited
* Proprietary and confidential
*/

#pragma once
#include "IntensityImage.h"
#include "RGBImageStudent.h"
#include <vector>

class IntensityImageStudent : public IntensityImage {
public:
	//! @brief default constructor
	IntensityImageStudent();

	//! @brief default destructor
	~IntensityImageStudent();

	//! @brief construct IntensityImageStudent with a copy
	//!
	//! @param other the IntensityImageStudent to copy
	IntensityImageStudent(const IntensityImageStudent &other);

	//! @brief constructor with width and height
	//!
	//! @param width the width of the container in pixels
	//! @param height the height of the container in pixels
	IntensityImageStudent(const int width, const int height);

	//! @brief construct IntensityImageStudent from a RGBImageStudent by converting RGB to Grayscale
	//!
	//! @param other the RGBImageStudent to copy 
	IntensityImageStudent(const RGBImageStudent &other);

	//! @brief set the size of the container
	//!
	//! @param width the width of the container in pixels
	//! @param height the height of the container in pixels
	void set(const int width, const int height);

	//! @brief copy another container
	//!
	//! @param other the IntensityImageStudent to copy
	void set(const IntensityImageStudent &other);

	//! @brief copy RGBImageStudent by converting RGB to Grayscale
	//!
	//! @param other the RGBImageStudent to copy 
	void set(const RGBImageStudent &other);

	//! @brief set a pixel using X and Y coordinates
	//!
	//! @param x the X coordinate of the pixel
	//! @param y the Y coordinate of the pixel
	void setPixel(int x, int y, Intensity pixel);

	//! @brief set a pixel using Row-Major order
	//!
	//! @param i the number of the pixel you want to get in Row-Major order
	//! @param pixel The pixel to set
	void setPixel(int i, Intensity pixel);

	//! @brief gets a pixel using X and Y coordinates
	//!
	//! @param x the X coordinate of the pixel
	//! @param y the Y coordinate of the pixel
	//! @return RGB the pixel
	Intensity getPixel(int x, int y) const;

	//! @brief gets a pixel using Row-Major order
	//!
	//! @param i the number of the pixel you want to get in Row-Major order.
	//! @return RGB the pixel
	Intensity getPixel(int i) const;

	//! @brief returns the pixels vector
	//!
	//! @return the vector that contains the pixels
	std::vector<Intensity> getPixels() const;
private:
	std::vector<Intensity> pixels;

	void convertRGBImageStudentToIntensityImageStudent(const RGBImageStudent &input);
};