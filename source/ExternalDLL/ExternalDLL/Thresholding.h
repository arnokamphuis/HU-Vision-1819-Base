#pragma once
#include "IntensityImage.h"
#include "ImageFactory.h"

namespace tr {

	template <class T>
	void basic_threshold(ed::matrix<T> &src, const int &threshold) {
		for (int i = 0; i < src.height; i++) {
			for (int j = 0; j < src.width; j++) {
				if (src(i, j) <= threshold || src(i, j) > 2500) {
					src(i, j) = 255;
				}
				else {
					src(i, j) = 0;
				}
			}
		}
	}

	//template <class T>
	//void auto_threshold(ed::matrix<T> &src, int init_threshold, int maxVal) {
	//	int back = 0;
	//	int back_pix = 0;
	//	int fore = 0;
	//	int fore_pix = 0;
	//	for (int i = 0; i < src.height; i++) {
	//		for (int j = 0; j < src.width; j++) {
	//			if (src(i, j) <= init_threshold) {
	//				back += src(i, j);
	//				back_pix += 1;
	//			}else {
	//				fore += src(i, j);
	//				fore_pix += 1;
	//			}
	//		}
	//	}

	//	int avg_threshold = ((back / back_pix) + (fore / fore_pix)) / 2;
	//	if (std::abs(avg_threshold - init_threshold) > 2) {
	//		auto_threshold(src, avg_threshold, maxVal);
	//	}else{
	//		basic_threshold(src, avg_threshold, maxVal);
	//	}
	//}

	//template <class T>
	//void histogram_threshold(ed::matrix<T> &src, int maxVal) {
	//	std::array<int, 256> histogram{};

	//	for (int i = 0; i < src.height; i++) {
	//		for (int j = 0; j < src.width; j++) {
	//			histogram[src(i, j)] += 1;
	//		}
	//	}

	//	int t = 0;
	//	for (auto h : histogram){
	//		t++;
	//	}

	//	//Need peak location not value
	//	auto mid = histogram.begin();
	//	std::advance(mid, 127);
	//	auto w_peak = std::max_element(histogram.begin(), mid);
	//	auto b_peak = std::max_element(mid, histogram.end());
	//	int threshold = (std::distance(histogram.begin(), w_peak) + std::distance(histogram.begin(), b_peak)) / 2;
	//	basic_threshold(src, threshold, maxVal);
	//}


}