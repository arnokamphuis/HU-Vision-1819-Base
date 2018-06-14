#include "Convolve.h"


namespace imgFunc{
	void convolve(const IntensityImage &inputImage, IntensityImage *outputImage, Kernel & kernel){
		IntensityImage * newInputImage = ImageFactory::newIntensityImage(inputImage.getWidth(), inputImage.getHeight());

		for (int y = 0; y < inputImage.getHeight(); ++y){
			for (int x = 0; x < inputImage.getWidth(); ++x){
				newInputImage->setPixel(x, y, inputImage.getPixel(x, y));
			}
		}

		convolve(newInputImage, outputImage, kernel);
		delete newInputImage;
	}

	void convolve(const IntensityImage *inputImage, IntensityImage *outputImage, Kernel & kernel){

		outputImage->set(inputImage->getWidth() - (kernel.getKernelxOffset() * 2), inputImage->getHeight() - (kernel.getKernelyOffset() * 2));

		int max = INT_MIN;
		int min = INT_MAX;

		int thres = 0;

		for (int y = 0; y < outputImage->getHeight(); y++){
			for (int x = 0; x < outputImage->getWidth(); x++){

				float Accumulator = 0;
				//offset bij inputImage optellen

				//convolve kernel met inputimage -> output naar outputImage

				//achteruit tellen om kernel te flippen
				int xn = -1;
				int yn = -1;

				for (int i = kernel.getKernelHeight() - 1; i >= 0; i--){
					for (int j = kernel.getKernelWidth() - 1; j >= 0; j--){
						Accumulator += (kernel.getKernelPoint(i, j) * inputImage->getPixel(x + kernel.getKernelxOffset() + xn, y + kernel.getKernelyOffset() + yn)) / kernel.getKernelNormalize();
						xn += 1;
					}
					yn += 1;
					xn = -1;
				}
				//set outputimage pixel value to accumulator
				//std::cout << "Org image pixel value = " << inputImage.getPixel(x + xOffset, y + yOffset) << "\n"
				//	<< "New = " << Accumulator << "\n";

				Accumulator = abs(Accumulator);

				if (Accumulator > max){
					max = Accumulator;
				}

				if (Accumulator < min){
					min = Accumulator;
				}

				if (Accumulator > 255 | Accumulator < 0){
					thres++;
				}

				/*if (Accumulator >= 255)
				{
					Accumulator = 255;
					std::cout << "+";
				}
				else if (Accumulator < 0){
					Accumulator = 0;
					std::cout << "-";
				}

				outputImage->setPixel(x, y, Accumulator);

				*/
			}
		}
		//return;
		std::cout << "Max: " << max << "\tMin" << min << "Count:" << thres << "\n";
		for (int y = 0; y < outputImage->getHeight(); y++){
			for (int x = 0; x < outputImage->getWidth(); x++){
				float Accumulator = 0;
				//offset bij inputImage optellen

				//convolve kernel met inputimage -> output naar outputImage

				//achteruit tellen om kernel te flippen
				int xn = -1;
				int yn = -1;

				for (int i = kernel.getKernelHeight() - 1; i >= 0; i--){
					for (int j = kernel.getKernelWidth() - 1; j >= 0; j--){
						Accumulator += (kernel.getKernelPoint(i, j) * inputImage->getPixel(x + kernel.getKernelxOffset() + xn, y + kernel.getKernelyOffset() + yn)) / kernel.getKernelNormalize();
						xn += 1;
					}
					yn += 1;
					xn = -1;
				}
				//set outputimage pixel value to accumulator
				//std::cout << "Org image pixel value = " << inputImage.getPixel(x + xOffset, y + yOffset) << "\n"
				//	<< "New = " << Accumulator << "\n";
				/*
				if (Accumulator >= 255)
				{
				Accumulator = 255;
				std::cout << "+";
				}
				else if (Accumulator < 0){
				Accumulator = 0;
				std::cout << "-";
				}*/

				//outputImage->setPixel(x, y, Accumulator);
				Accumulator = abs(Accumulator);

				if (thres > 1){
					if (Accumulator < 0){
						std::cout << Accumulator << " ";
					}
					Accumulator = ((Accumulator - 0) * UINT8_MAX) / (UINT8_MAX - 0);
				}
				else{
					if (Accumulator >= UINT8_MAX)
					{
						Accumulator = UINT8_MAX;
						std::cout << "+";
					}
					else if (Accumulator < 0){
						Accumulator = 0;
						std::cout << "-";
					}
				}
				outputImage->setPixel(x, y, Accumulator);
			}
		}
	}

	void combineGradientMagnitude(const IntensityImage *firstImage, const IntensityImage *secondImage, IntensityImage * outputImage){
		//size check
		if (firstImage->getWidth() == secondImage->getWidth()){
			if (firstImage->getHeight() == secondImage->getHeight()){
				outputImage->set(firstImage->getWidth(), firstImage->getHeight());
			}
			else{
				return;
			}
		}
		else{
			return;
		}


		for (int y = 0; y < firstImage->getHeight(); y++){
			for (int x = 0; x < firstImage->getWidth(); x++){


				//sobel wiki mag add
				//int newPixel = sqrt(pow(firstImage->getPixel(x, y), 2) + pow(secondImage->getPixel(x, y), 2));

				//avg add
				int newPixel = (firstImage->getPixel(x, y) + secondImage->getPixel(x, y)) / 1;

				if (newPixel > UINT8_MAX){
					newPixel = UINT8_MAX;
				}

				outputImage->setPixel(x, y, abs(newPixel));
			}
		}
	}


	void sobelFilter(const IntensityImage * inputImage, IntensityImage * outputImage){

		
		/*
		Kernel sobelX = Kernel(3, 3);
		Kernel sobelY = Kernel(3, 3);

		int sobelXkernel[3][3] = {	{ -3, 0, 3 },
									{ -10, 0, 10 },
									{ -3, 0, 3 } };

		int sobelYkernel[3][3] = {	{ 3, 10, 3 },
									{ 0, 0, 0 },
									{-3,-10,-3 } };

		sobelX.setKernel(sobelXkernel);
		sobelY.setKernel(sobelYkernel);
		*/
		
		Kernel sobelX = Kernel(5, 5);
		Kernel sobelY = Kernel(5, 5);

		int sobelXkernel[5][5] = { { -1, -2, 0, 2, 1 },
		{ -4, -8, 0, 8, 4 },
		{ -6, -12, 0, 12, 6 },
		{ -4, -8, 0, 8, 4 },
		{ -1, -2, 0, 1, 2 }};

		int sobelYkernel[5][5] = {	{ 1, 4, 6,4,2 },
									{ 2, 8, 12,8,1 },
									{ 0, 0, 0,0,0 },
									{ -2, -8, -12,-8,-2 },
									{ -1, -4, -6,-4,-1 } };
		
		sobelX.setKernel(sobelXkernel);
		sobelY.setKernel(sobelYkernel);

		outputImage->set(inputImage->getWidth() - (sobelX.getKernelxOffset() * 2), inputImage->getHeight() - (sobelX.getKernelyOffset() * 2));

		//min max
		int max = INT_MIN;
		int min = INT_MAX;


		for (int y = 0; y < outputImage->getHeight(); y++){
			for (int x = 0; x < outputImage->getWidth(); x++){

				float Accumulator = 0;
				float tempY = 0;
				int xn = -sobelX.getKernelxOffset();
				int yn = -sobelX.getKernelyOffset();

				for (int i = sobelX.getKernelHeight() - 1; i >= 0; i--){
					for (int j = sobelX.getKernelWidth() - 1; j >= 0; j--){
						Accumulator += (sobelX.getKernelPoint(i, j) * inputImage->getPixel(x + sobelX.getKernelxOffset() + xn, y + sobelX.getKernelyOffset() + yn)) / sobelX.getKernelNormalize();
						tempY += (sobelY.getKernelPoint(i, j) * inputImage->getPixel(x + sobelY.getKernelxOffset() + xn, y + sobelY.getKernelyOffset() + yn)) / sobelY.getKernelNormalize();
						xn += 1;
					}
					yn += 1;
					xn = -sobelX.getKernelxOffset();
				}

				Accumulator = sqrt(pow(Accumulator, 2) + pow(tempY, 2));

				if (Accumulator > max){
					max = Accumulator;
				}else if (Accumulator < min){
					min = Accumulator;
				}
			}
		}

		//std::cout << "Acc " << max << " " << min;

		for (int y = 0; y < outputImage->getHeight(); y++){
			for (int x = 0; x < outputImage->getWidth(); x++){

				float Accumulator = 0;
				float tempY = 0;
				int xn = -1;
				int yn = -1;

				for (int i = sobelX.getKernelHeight() - 1; i >= 0; i--){
					for (int j = sobelX.getKernelWidth() - 1; j >= 0; j--){
						Accumulator += (sobelX.getKernelPoint(i, j) * inputImage->getPixel(x + sobelX.getKernelxOffset() + xn, y + sobelX.getKernelyOffset() + yn)) / sobelX.getKernelNormalize();
						tempY += (sobelY.getKernelPoint(i, j) * inputImage->getPixel(x + sobelY.getKernelxOffset() + xn, y + sobelY.getKernelyOffset() + yn)) / sobelY.getKernelNormalize();
						xn += 1;
					}
					yn += 1;
					xn = -1;
				}

				Accumulator = sqrt(pow(Accumulator, 2) + pow(tempY, 2));

				Accumulator = ((Accumulator - min) / (max - min)) * (UINT8_MAX - 0);

				outputImage->setPixel(x, y, Accumulator);
				
			}
		}

	}

}

