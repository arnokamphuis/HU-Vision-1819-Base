#pragma once

#include "IntensityImage.h"
#include "ImageFactory.h"
#include <array>
#include <cstdlib>
#include "EdgeDetection.h"

namespace tr {

	template <class T>
	void basic_threshold(ed::matrix<T> &src, int threshold, int maxVal) {
		for (int i = 0; i < src.height; i++) {
			for (int j = 0; j < src.width; j++) {
				if (src(i,j) <= threshold || src(i,j) > 2500) {
					src(i,j) = maxVal;
				}
				else {
					src(i,j) = 0;
				}
			}
		}
	}

	template<class T>
	void auto_treshold(ed::matrix<T> &src, int initial_thresh, int maxVal) {
		int back = 0;
		int	back_pix = 0; 
		int	fore = 0;
		int	fore_pix = 0;

		for (int i = 0; i < src.height; i++) {
			for (int j = 0; j < src.width; j++) {
				if (src(i, j) <= initial_thresh) {
					back += src(i, j);
					back_pix += 1;
				}
				else {
					fore += src(i, j);
					fore_pix += 1;
				}
			}
		}

		int avg_tresh = ((back / back_pix) + (fore / fore_pix)) / 2;
		if (std::abs(avg_tresh - initial_thresh) > 2) {
			basic_threshold(src, avg_tresh, maxVal);
			auto_treshold(src, avg_tresh, maxVal);
		}
	}


}