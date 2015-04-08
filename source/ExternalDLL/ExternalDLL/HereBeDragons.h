/*
* Copyright (c) 2015 DottedEye Designs, Alexander Hustinx, NeoTech Software, Rolf Smit - All Rights Reserved
* Unauthorized copying of this file, via any medium is strictly prohibited
* Proprietary and confidential
*/

#pragma once

#include "SonnetXVIII.h"
#include "IntensityImage.h"
#include <opencv2/imgproc/imgproc.hpp>
#include "Point2D.h"

class HereBeDragons {
public:
	static void				SonnetCLI(const IntensityImage &Sonnet, IntensityImage &CLI);
	static SonnetXVIII		LoveIsTooYoungToKnowWhatConscienceIs(const IntensityImage &Love, const int Is, const int Too, const int Young, const int To);
	static SonnetXVIII		YetWhoKnowsNotConscienceIsBornOfLove(const IntensityImage &Yet, const int Who, const int Knows, const int Not, const int Conscience);
	static void				ThenGentleCheaterUrgeNotMyAmiss(SonnetXVIII &Then, const int Gentle, const int Cheater);
	static void				LestGuiltyOfMyFaultsThySweetSelfProve(const SonnetXVIII &Lest, int &Guilty, int &Of);
	static void				ForThouBetrayingMeIDoBetray(const SonnetXVIII &For, int & Thou, int & Betraying);
	static void				MyNoblerPartToMyGrossBodysTreason(cv::Mat &My);
	static Point2D<double>	MySoulDothTellMyBodyThatHeMay(Point2D<double> My, Point2D<double> Soul);
	static void				TriumphInLoveFleshStaysNoFatherReason(RGBImage &Triumph, const Point2D<double> In, const RGB Love); //OK I know this is madness but these three lines can actually be used to draw debug points, lines and rectangles
	static void				ButRisingAtThyNameDothPointOutThee(RGBImage &But, const Point2D<double> Rissing, const Point2D<double> At, const RGB Thy);
	static void				AsHisTriumphantPrizeProudOfThisPride(RGBImage &As, const Point2D<double> His, const Point2D<double> Triumphant, const RGB Prize);
	static void				HeIsContentedThyPoorDrudgeToBe(const cv::Mat &He, RGBImage &Is);
	static void				ToStandInThyAffairsFallByThySide(const RGBImage &To, cv::Mat &Stand);
	static void				NoWantOfConscienceHoldItThatICall(const cv::Mat &No, IntensityImage &Want);
	static void				HerLoveForWhoseDearLoveIRiseAndFall(const IntensityImage &Her, cv::Mat &Love);
};