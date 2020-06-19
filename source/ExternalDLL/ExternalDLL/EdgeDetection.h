#pragma once

#include "IntensityImage.h"
#include "ImageFactory.h"
#include <array>
#include <iostream>
#include <map>

namespace ed {

	template <class T, int H = 0, int W = 0>
	class matrix {
	public:
		int width = -1;
		int height = -1;

		T* m;

		matrix(const int h, const int w) :
			width(w),
			height(h)
		{
			m = new T[height * width];
		}

		matrix(const IntensityImage& image) :
			width(image.getWidth()),
			height(image.getHeight())
		{
			m = new T[height * width];
			for (int y = 0; y < height; y++) {
				for (int x = 0; x < width; x++) {
					m[(y * width) + x] = image.getPixel(x, y);
				}
			}
		}

		template <typename TT = T>
		matrix(const std::array<std::array<TT, W>, H> & matrix) :
			width(W),
			height(H)
		{
			m = new T[height*width];
			for (int y = 0; y < height; y++) {
				for (int x = 0; x < width; x++) {
					m[(y*width) + x] = matrix[y][x];
				}
			}
		}

		IntensityImage * get_intensity_image_ptr() {
			IntensityImage * img_ptr = ImageFactory::newIntensityImage();
			img_ptr->set(width, height);
			for (int y = 0; y < height; y++) {
				for (int x = 0; x < width; x++) {
					img_ptr->setPixel(x, y, this->operator()(y, x));
				}
			}
			return img_ptr;
		}

		template <typename NT = unsigned int>
		void equalization(int spread_size) {
			static std::map<int, unsigned int> cdf = cdf_map();
			//Contains all the values from the map as key, and the new value will be the value to that key.
			static std::map<unsigned int, NT> equalized_value_map;

			// Calculate the lowest non-neg cdf value to calibrate every value between 0 and spread_size.
			int lowest_non_neg_cdf_value = 0;
			int lowest_non_neg_cdf_key = 0;

			//Iterator for the map
			std::map<int, unsigned int>::iterator it;

			for (int i = 0;; i++) {
				if (cdf[i]){
					it = cdf.find(i);
					lowest_non_neg_cdf_value = cdf[i];
					lowest_non_neg_cdf_key = i;
					break;
					}
			}

			double MxN = width * height;
			double alpha = spread_size / (MxN - lowest_non_neg_cdf_value);

			//Calculate new eq val of the pixels.
			equalized_value_map[0] = static_cast<unsigned int>(alpha * (it->second - lowest_non_neg_cdf_value));
			for (int i = 1; i < spread_size; i++) {
				equalized_value_map[i] = static_cast<unsigned int>(equalized_value_map[i - 1] + (alpha * (it->second - lowest_non_neg_cdf_value)));
				it = std::next(it, 1);
			}

			//Give the picture the new values.
			for (int i = 0; i < MxN; i++)
			{
				//m[i] = equalized_value_map[m[i]];
				(m[i] < 0) ? (m[i] = 0) : (m[i] = equalized_value_map[m[i]]);
			}
		}

		template <unsigned MinValue = 0, unsigned MaxValue = 255>
		void static_thresholding() {
			for (int i = 0; i < height; i++) {
				for (int ii = 0; ii < width; ii++) {
					if (this->operator()(i, ii) <= 155 || this->operator()(i, ii) > 2500) {
						this->operator()(i, ii) = MaxValue;
					}
					else {
						this->operator()(i, ii) = MinValue;
					}
				}
			}
		}

		//Array -> 2D Array.
		T & operator()(const int y, const int x) {
			return m[(y*width) + x];
		}

		//Make Array usable with direct index.
		T & operator()(int n) {
			return m[n];
		}

	protected:

		std::map<int, unsigned int> cdf_map() {
			std::map<int, unsigned int> map;
			for (int i = 0; i < (width*height); i++) {
				if (m[i] < 0) {
					map[0] += 1;
				}
				else {
					map[m[i]] += 1;
				}
			}
			for (auto ptr = std::next(map.begin(), 1); ptr != map.end(); ptr++) {
				ptr->second += (std::next(ptr, -1))->second;
			}
			return map;
		}
	};


	template <typename T, T H, T W, typename TT = T>
	matrix<T> convolution(matrix<T> & image, matrix<TT, H, W> & kernel) {
		// find center position of kernel
		unsigned int kernel_width = kernel.width;
		unsigned int kernel_height = kernel.height;

		int kernel_center_X = kernel_width / 2 + 1;
		int kernel_center_Y = kernel_height / 2 + 1;

		matrix<T> new_image(image.height, image.width);

		for (int y = 0; y < image.height; ++y) {
			for (int x = 0; x < image.width; ++x) {
				for (int yy = kernel_height - 1; yy >= 0; --yy) {
					for (int xx = kernel_width - 1; xx >= 0; --xx) {

						// index of input signal
						int image_index_Y = y + (kernel_center_Y - yy);
						int image_index_X = x + (kernel_center_X - xx);

						// ignore out of bounds
						if (image_index_Y >= 0 && image_index_Y <= image.height && image_index_X >= 0 && image_index_X <= image.width) {
							new_image(y, x) += image(image_index_Y, image_index_X) * kernel(yy, xx);
						}
					}
				}
			}
		}
		return new_image;
	}
}
