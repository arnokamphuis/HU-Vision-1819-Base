#include "StudentPreProcessing.h"
#include "ImageFactory.h"
#include "PixelType.h"


void apply_kernel_horizontal(IntensityImage & returnImage, Intensity matrix[3][3], int x, int y) {

	int kernel[3][3] = {
		{ { -1 },{ 0 },{ 1 } },
		{ { -2 },{ 0 },{ 2 } },
		{ { -1 },{ 0 },{ 1 } }
	};
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			matrix[i][j] = kernel[i][j] * matrix[i][j];
		}
	}
	returnImage.setPixel(x, y, matrix[1][1]);
}

void apply_kernel_vertical(IntensityImage & returnImage, Intensity matrix[3][3], int x, int y) {

	int kernel[3][3] = {
		{ { -1 },{ -2 },{ -1 } },
		{ { 0 },{ 0 },{ 0 } },
		{ { 1 },{ 2 },{ 1 } }
	};
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			matrix[i][j] = kernel[i][j] * matrix[i][j];
		}
	}
	returnImage.setPixel(x, y, matrix[1][1]);
}

void merge(IntensityImage & image1, IntensityImage & image2, IntensityImage & result) {
	for (int x = 0; x < 0; x++) {
		for (int y = 0; y < 0; y++) {
			Intensity a = image1.getPixel(x, y);
			Intensity b = image2.getPixel(x, y);
			if ((a + b) > 255) {
				result.setPixel(x, y, 255);
			}
			else {
				result.setPixel(x, y, (a + b));
			}
		}
	}
}


IntensityImage * StudentPreProcessing::stepToIntensityImage(const RGBImage &image) const {
	return nullptr;
}

IntensityImage * StudentPreProcessing::stepScaleImage(const IntensityImage &image) const {
	return nullptr;
}

IntensityImage * StudentPreProcessing::stepEdgeDetection(const IntensityImage &image) const {
	int hght = image.getHeight();
	int wdth = image.getWidth();

	IntensityImage * returnImage1 = ImageFactory::newIntensityImage(hght, wdth);
	IntensityImage * returnImage2 = ImageFactory::newIntensityImage(hght, wdth);
	IntensityImage * result = ImageFactory::newIntensityImage(hght, wdth);

	Intensity matrix[3][3];
	for (int y = 0; y < hght; y++) {
		for (int x = 0; x < wdth; x++) {
			matrix[0][0] = image.getPixel(x - 1, y - 1);
			matrix[0][1] = image.getPixel(x, y - 1);
			matrix[0][2] = image.getPixel(x + 1, y - 1);
			matrix[1][0] = image.getPixel(x - 1, y);
			matrix[1][1] = image.getPixel(x, y);
			matrix[1][2] = image.getPixel(x + 1, y);
			matrix[2][0] = image.getPixel(x - 1, y + 1);
			matrix[2][1] = image.getPixel(x, y + 1);
			matrix[2][2] = image.getPixel(x + 1, y + 1);
			apply_kernel_horizontal(*returnImage1, matrix, x, y);
		};
	}
	for (int x = 0; x < hght; x++) {
		for (int y = 0; y < wdth; y++) {
			matrix[0][0] = image.getPixel(x - 1, y - 1);
			matrix[0][1] = image.getPixel(x, y - 1);
			matrix[0][2] = image.getPixel(x + 1, y - 1);
			matrix[1][0] = image.getPixel(x - 1, y);
			matrix[1][1] = image.getPixel(x, y);
			matrix[1][2] = image.getPixel(x + 1, y);
			matrix[2][0] = image.getPixel(x - 1, y + 1);
			matrix[2][1] = image.getPixel(x, y + 1);
			matrix[2][2] = image.getPixel(x + 1, y + 1);
			apply_kernel_vertical(*returnImage2, matrix, x, y);
		};
	}
	merge(*returnImage1, *returnImage2, *result);
	return result;
}

IntensityImage * StudentPreProcessing::stepThresholding(const IntensityImage &image) const {
	IntensityImage * returnImage = ImageFactory::newIntensityImage(image.getHeight(), image.getWidth());
	/*for (int y = 0; y < image.getHeight(); y++)
	{
		for (int x = 0; x < image.getWidth(); x++)
		{
			if (edges[x][y][1] == 0)
			{
				if (image.getPixel(x, y) < image.getPixel(x - 1, y) || image.getPixel(x, y) < image.getPixel(x + 1, y))
				{
					returnImage->setPixel(x, y, 0);
				}
			}
			if (edges[x][y][1] == 45)
			{
				if (image.getPixel(x, y) < image.getPixel(x + 1, y-1) || image.getPixel(x, y) < image.getPixel(x - 1, y +1))
				{
					returnImage->setPixel(x,y, 0);
				}
			}
			if (edges[x][y][1] == 90)
			{
				if (image.getPixel(x, y) < image.getPixel(x, y + 1) || image.getPixel(x, y) < image.getPixel(x, y - 1))
				{
					returnImage->setPixel(x, y, 0);
				}
			}
			if (edges[x][y][1] == 135)
			{
				if (image.getPixel(x, y) < image.getPixel(x - 1, y - 1) || image.getPixel(x, y) < image.getPixel(x + 1, y + 1))
				{
					returnImage->setPixel(x, y, 0);
				}
			}
		}
	}*/

	

	Intensity T1 = 40;
	Intensity T2 = 50;
	Intensity edge = 0;
	Intensity black = 255;
	for (int y = 0; y < image.getHeight(); y++)
	{
		for (int x = 0; x < image.getWidth(); x++)
		{
			if (returnImage->getPixel(x, y) < T1)
			{
				returnImage->setPixel(x, y, edge);
			}
			else if (returnImage->getPixel(x, y) < T2)
			{
				if (
					returnImage->getPixel(x - 1, y - 1) < T1 ||
					returnImage->getPixel(x, y - 1) < T1 ||
					returnImage->getPixel(x + 1, y - 1) < T1 ||
					returnImage->getPixel(x - 1, y) < T1 ||
					returnImage->getPixel(x + 1, y) < T1 ||
					returnImage->getPixel(x - 1, y + 1) < T1 ||
					returnImage->getPixel(x, y + 1) < T1 ||
					returnImage->getPixel(x + 1, y + 1) < T1
					)
				{
					returnImage->setPixel(x, y, edge);
				}
			}
			else
			{
				returnImage->setPixel(x, y, black);
			}
		}
	}
	return returnImage;
}
