/*
* Copyright (c) 2015 DottedEye Designs, Alexander Hustinx, NeoTech Software, Rolf Smit - All Rights Reserved
* Unauthorized copying of this file, via any medium is strictly prohibited
* Proprietary and confidential
*/

#ifdef VISION_DLL_EXPORTS
#define VISION_DLL_EXPORTS_API __declspec(dllexport) 
#else
#define VISION_DLL_EXPORTS_API __declspec(dllimport) 
#endif


#include "RGBImage.h"
#include "DLLExecution.h"





extern "C" _declspec(dllexport) DLLExecution * getDLLExecutionTask(RGBImage * image);
extern "C" _declspec(dllexport) void freeDLLExecutionTask(DLLExecution * dllExecution);

extern "C" _declspec(dllexport) void setImageImplementation(bool student);


extern "C" _declspec(dllexport) bool executePreProcessingStep1(DLLExecution * dllExecution, bool student);
extern "C" _declspec(dllexport) bool executePreProcessingStep2(DLLExecution * dllExecution, bool student);
extern "C" _declspec(dllexport) bool executePreProcessingStep3(DLLExecution * dllExecution, bool student);
extern "C" _declspec(dllexport) bool executePreProcessingStep4(DLLExecution * dllExecution, bool student);


extern "C" _declspec(dllexport) RGBImage * getResultPreProcessingStep1(DLLExecution * dllExecution);
extern "C" _declspec(dllexport) RGBImage * getResultPreProcessingStep2(DLLExecution * dllExecution);
extern "C" _declspec(dllexport) RGBImage * getResultPreProcessingStep3(DLLExecution * dllExecution);
extern "C" _declspec(dllexport) RGBImage * getResultPreProcessingStep4(DLLExecution * dllExecution);



extern "C" _declspec(dllexport) bool prepareLocalization(DLLExecution * dllExecution);
extern "C" _declspec(dllexport) bool executeLocalizationStep1(DLLExecution * dllExecution, bool student);
extern "C" _declspec(dllexport) bool executeLocalizationStep2(DLLExecution * dllExecution, bool student);
extern "C" _declspec(dllexport) bool executeLocalizationStep3(DLLExecution * dllExecution, bool student);
extern "C" _declspec(dllexport) bool executeLocalizationStep4(DLLExecution * dllExecution, bool student);
extern "C" _declspec(dllexport) bool executeLocalizationStep5(DLLExecution * dllExecution, bool student);
extern "C" _declspec(dllexport) RGBImage * getLocalizationDebugImage(DLLExecution * dllExecution);


extern "C" _declspec(dllexport) bool prepareExtraction(DLLExecution * dllExecution);
extern "C" _declspec(dllexport) bool executeExtractionStep1(DLLExecution * dllExecution, bool student);
extern "C" _declspec(dllexport) bool executeExtractionStep2(DLLExecution * dllExecution, bool student);
extern "C" _declspec(dllexport) bool executeExtractionStep3(DLLExecution * dllExecution, bool student);
extern "C" _declspec(dllexport) RGBImage * getExtractionDebugImage(DLLExecution * dllExecution);



extern "C" _declspec(dllexport) bool executePostProcessing(DLLExecution * dllExecution);
extern "C" _declspec(dllexport) bool executeRepresentation(DLLExecution * dllExecution);

extern "C" _declspec(dllexport) void getFacialParameters(DLLExecution * dllExecution, double facialParameters[]);









extern "C" _declspec(dllexport) RGBImage * getRGBImageFromData(int width, int height, unsigned char * pixels, int stride);



extern "C" _declspec(dllexport) int getVersion();



extern "C" _declspec(dllexport) RGBImage * imageNewRGB(int width, int height);
extern "C" _declspec(dllexport) void imageFreeRGB(RGBImage * image);
extern "C" _declspec(dllexport) int imageWidth(Image * image);
extern "C" _declspec(dllexport) int imageHeight(Image * image);

extern "C" _declspec(dllexport) void getImageBytes(RGBImage * image, unsigned char * pixels, int stride);
extern "C" _declspec(dllexport) void openImageWithOpenCV(char * file);