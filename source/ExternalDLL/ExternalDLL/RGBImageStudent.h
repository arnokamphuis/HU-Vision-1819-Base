/*
* Copyright (c) 2015 DottedEye Designs, Alexander Hustinx, NeoTech Software, Rolf Smit - All Rights Reserved
* Unauthorized copying of this file, via any medium is strictly prohibited
* Proprietary and confidential
*/

#pragma once
#include "RGBImage.h"
#include <vector>

class RGBImageStudent : public RGBImage {
public:
	RGBImageStudent();
	~RGBImageStudent();

	//! @brief construct RGBImage with a copy
	//!
	//! @param other the RGBImage to copy
	RGBImageStudent(const RGBImageStudent &other);

	//! @brief constructor with width and height
	//!
	//! @param width the width of the container in pixels
	//! @param height the height of the container in pixels
	RGBImageStudent(const int width, const int height);

	//! @brief set the size of the container
	//!
	//! @param width the width of the container in pixels
	//! @param height the height of the container in pixels
	void set(const int width, const int height);

	//! @brief copy another container
	//!
	//! @param other the RGBImage to copy
	void set(const RGBImageStudent &other);

	//! @brief set a pixel using X and Y coordinates
	//!
	//! @param x the X coordinate of the pixel
	//! @param y the Y coordinate of the pixel
	void setPixel(int x, int y, RGB pixel);

	//! @brief set a pixel using Row-Major order
	//!
	//! @param i the number of the pixel you want to get in Row-Major order
	//! @param pixel The pixel to set
	void setPixel(int i, RGB pixel);

	//! @brief gets a pixel using X and Y coordinates
	//!
	//! @param x the X coordinate of the pixel
	//! @param y the Y coordinate of the pixel
	//! @return RGB the pixel
	RGB getPixel(int x, int y) const;

	//! @brief gets a pixel using Row-Major order
	//!
	//! @param i the number of the pixel you want to get in Row-Major order.
	//! @return RGB the pixel
	RGB getPixel(int i) const;

	//! @brief returns the pixels vector
	//!
	//! @return the vector that contains the pixels
	std::vector<RGB> getPixels() const;
private:
	std::vector<RGB> pixels;
};