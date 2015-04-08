/*
* Copyright (c) 2015 DottedEye Designs, Alexander Hustinx, NeoTech Software, Rolf Smit - All Rights Reserved
* Unauthorized copying of this file, via any medium is strictly prohibited
* Proprietary and confidential
*/

#pragma once



struct RGB {

	RGB(unsigned char r = 0, unsigned char g = 0, unsigned char b = 0)
		:r(r), g(g), b(b){
	}

	unsigned char b;
	unsigned char g;
	unsigned char r;
};

typedef unsigned char Intensity;