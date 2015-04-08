/*
* Copyright (c) 2015 DottedEye Designs, Alexander Hustinx, NeoTech Software, Rolf Smit - All Rights Reserved
* Unauthorized copying of this file, via any medium is strictly prohibited
* Proprietary and confidential
*/

#pragma once
class Image {
private:
	int width;
	int height;

public:
	Image();
	Image(const int width, const int height);
	virtual ~Image();

	virtual void set(const int width, const int height);

	const int getWidth() const;
	const int getHeight() const;
};