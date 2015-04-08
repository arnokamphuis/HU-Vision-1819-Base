/*
 * Copyright (c) 2015 DottedEye Designs, Alexander Hustinx, NeoTech Software, Rolf Smit - All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 */

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using System.Drawing;

namespace FaceRecognitionGUI {

    class FaceRecognitionTask {


        public class FaceRecognitionException : System.Exception {

            public FaceRecognitionException() {
            }

            public FaceRecognitionException(string message) : base(message) {
            }
        }





        IntPtr inputPointer;
        public Bitmap preProcessing1;
        public Bitmap preProcessing2;
        public Bitmap preProcessing3;
        public Bitmap preProcessing4;

        public Bitmap localizationDebug;
        public Bitmap extractionDebug;

        IntPtr task;

        public FaceRecognitionTask(Bitmap input) {
            inputPointer = VisionDLL.getRGBImageFromBitmap(input);
            task = VisionDLL.getDLLExecutionTask(inputPointer);
        }


        public void dispose() {
            VisionDLL.freeDLLExecutionTask(task);
            VisionDLL.imageFreeRGB(inputPointer);
        }

        public static void setImageImplementation(bool student) {
            VisionDLL.setImageImplementation(student);
        }


        public bool executePostProcessing() {
            return VisionDLL.executePostProcessing(task);
        }

        public bool executeRepresentation() {
            return VisionDLL.executeRepresentation(task);
        }

        public double[] getFacialParameters(){
            double[] parameters = new double[16];
            VisionDLL.getFacialParameters(task, parameters);
            return parameters;
        }


        public void prepareExtraction() {
            if (!VisionDLL.prepareExtraction(task)) {
                throw new FaceRecognitionTask.FaceRecognitionException("Extraction preparation: failed!");
            }
        }

        public void executeExtractionStep1(bool student) {
            if (VisionDLL.executeExtractionStep1(task, student)) {
                extractionDebug = VisionDLL.getBitmapFromRGBImage(VisionDLL.getExtractionDebugImage(task));
                return;
            }
            throw new FaceRecognitionTask.FaceRecognitionException("Extraction step 1: failed!");
        }

        public void executeExtractionStep2(bool student) {
            if (VisionDLL.executeExtractionStep2(task, student)) {
                extractionDebug = VisionDLL.getBitmapFromRGBImage(VisionDLL.getExtractionDebugImage(task));
                return;
            }
            throw new FaceRecognitionTask.FaceRecognitionException("Extraction step 2: failed!");
        }

        public void executeExtractionStep3(bool student) {
            if (VisionDLL.executeExtractionStep3(task, student)) {
                extractionDebug = VisionDLL.getBitmapFromRGBImage(VisionDLL.getExtractionDebugImage(task));
                return;
            }
            throw new FaceRecognitionTask.FaceRecognitionException("Extraction step 3: failed!");
        }














        public void prepareLocalization() {
            if (!VisionDLL.prepareLocalization(task)) {
                throw new FaceRecognitionTask.FaceRecognitionException("Localization preparation: failed!");
            }
        }

        public void executeLocalizationStep1(bool student) {
            if (VisionDLL.executeLocalizationStep1(task, student)) {
                localizationDebug = VisionDLL.getBitmapFromRGBImage(VisionDLL.getLocalizationDebugImage(task));
                return;
            }
            throw new FaceRecognitionTask.FaceRecognitionException("Localization step 1: failed!");
        }

        public void executeLocalizationStep2(bool student) {
            if (VisionDLL.executeLocalizationStep2(task, student)) {
                localizationDebug = VisionDLL.getBitmapFromRGBImage(VisionDLL.getLocalizationDebugImage(task));
                return;
            }
            throw new FaceRecognitionTask.FaceRecognitionException("Localization step 2: failed!");
        }

        public void executeLocalizationStep3(bool student) {
            if (VisionDLL.executeLocalizationStep3(task, student)) {
                localizationDebug = VisionDLL.getBitmapFromRGBImage(VisionDLL.getLocalizationDebugImage(task));
                return;
            }
            throw new FaceRecognitionTask.FaceRecognitionException("Localization step 3: failed!");
        }

        public void executeLocalizationStep4(bool student) {
            if (VisionDLL.executeLocalizationStep4(task, student)) {
                localizationDebug = VisionDLL.getBitmapFromRGBImage(VisionDLL.getLocalizationDebugImage(task));
                return;
            }
            throw new FaceRecognitionTask.FaceRecognitionException("Localization step 4: failed!");
        }

        public void executeLocalizationStep5(bool student) {
            if (VisionDLL.executeLocalizationStep5(task, student)) {
                localizationDebug = VisionDLL.getBitmapFromRGBImage(VisionDLL.getLocalizationDebugImage(task));
                return;
            }
            throw new FaceRecognitionTask.FaceRecognitionException("Localization step 5: failed!");
        }










        public void executePreProcessingStep1(bool student){
            if (VisionDLL.executePreProcessingStep1(task, student)) {
                IntPtr image = VisionDLL.getResultPreProcessingStep1(task);
                preProcessing1 = VisionDLL.getBitmapFromRGBImage(image);
                VisionDLL.imageFreeRGB(image);
                return;
            }
            throw new FaceRecognitionTask.FaceRecognitionException("Pre-Processing step 1: failed!");
        }

        public void executePreProcessingStep2(bool student){
            if (VisionDLL.executePreProcessingStep2(task, student)){
                IntPtr image = VisionDLL.getResultPreProcessingStep2(task);
                preProcessing2 = VisionDLL.getBitmapFromRGBImage(image);
                VisionDLL.imageFreeRGB(image);
                return;
            }
            throw new FaceRecognitionTask.FaceRecognitionException("Pre-Processing step 2: failed!");
        }

        public void executePreProcessingStep3(bool student){
            if (VisionDLL.executePreProcessingStep3(task, student)){
                IntPtr image = VisionDLL.getResultPreProcessingStep3(task);
                preProcessing3 = VisionDLL.getBitmapFromRGBImage(image);
                VisionDLL.imageFreeRGB(image);
                return;
            }
            throw new FaceRecognitionTask.FaceRecognitionException("Pre-Processing step 3: failed!");
        }

        public void executePreProcessingStep4(bool student) {
            if (VisionDLL.executePreProcessingStep4(task, student)) {
                IntPtr image = VisionDLL.getResultPreProcessingStep4(task);
                preProcessing4 = VisionDLL.getBitmapFromRGBImage(image);
                VisionDLL.imageFreeRGB(image);
                return;
            }
            throw new FaceRecognitionTask.FaceRecognitionException("Pre-Processing step 4: failed!");
        }
    }
}