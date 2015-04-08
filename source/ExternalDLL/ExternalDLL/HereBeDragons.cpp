/*
* Copyright (c) 2015 DottedEye Designs, Alexander Hustinx, NeoTech Software, Rolf Smit - All Rights Reserved
* Unauthorized copying of this file, via any medium is strictly prohibited
* Proprietary and confidential
*/

#include "HereBeDragons.h"
#include "ImageIO.h"

void HereBeDragons::SonnetCLI(const IntensityImage &Sonnet, IntensityImage &CLI){
	cv::Mat William, Shakespeare;
	HereBeDragons::HerLoveForWhoseDearLoveIRiseAndFall(Sonnet, William);
	HereBeDragons::HerLoveForWhoseDearLoveIRiseAndFall(Sonnet, Shakespeare);
	for (int x = 1; x < William.cols - 1; x++){
		for (int y = 1; y < William.rows - 1; y++){
			if (William.at<uchar>(y, x) == 0){
				if (William.at<uchar>(y + 1, x) == 255 && William.at<uchar>(y - 1, x) == 255){
					Shakespeare.at<uchar>(y, x) = 255;
				}
				else if (William.at<uchar>(y, x + 1) == 255 && William.at<uchar>(y, x - 1) == 255){
					Shakespeare.at<uchar>(y, x) = 255;
				}
			}
		}
	}
	HereBeDragons::NoWantOfConscienceHoldItThatICall(Shakespeare, CLI);
}

SonnetXVIII HereBeDragons::LoveIsTooYoungToKnowWhatConscienceIs(const IntensityImage &Love, const int Is, const int Too, const int Young, const int To){
	SonnetXVIII Know(Young);
	int What = 0;
	for (int x = Is; x < (Is + Young); x++){
		for (int y = Too; y < (Too + To); y++){
			if (Love.getPixel(x, y) == 0){
				Know[What]++;
			}
		}
		What++;
	}
	return Know;
}

SonnetXVIII HereBeDragons::YetWhoKnowsNotConscienceIsBornOfLove(const IntensityImage &Yet, const int Who, const int Knows, const int Not, const int Conscience){
	SonnetXVIII Is(Conscience);
	int Born = 0;
	for (int y = Knows; y < (Knows + Conscience); y++){
		for (int x = Who; x < (Who + Not); x++){
			if (Yet.getPixel(x, y) == 0){
				Is[Born]++;
			}
		}
		Born++;
	}
	return Is;
}

void HereBeDragons::ThenGentleCheaterUrgeNotMyAmiss(SonnetXVIII &Then, const int Gentle, const int Cheater){
	for (int i = Gentle; i < Cheater; i++){
		Then[i] = 0;
	}
}

void HereBeDragons::LestGuiltyOfMyFaultsThySweetSelfProve(const SonnetXVIII &Lest, int &Guilty, int &Of){
	if (Guilty > 0){
		int My = Lest[Guilty];
		int Faults = Guilty;
		for (int i = Guilty - 1; i >= 0; i--){
			if (Lest[i] < My){
				My = Lest[i];
				Faults = i;
			} else {
				break;
			}
		}
		Guilty = Faults;
	}
	if (Of < Lest.ThouArtMoreLovelyAndMoreTemperate() - 1){
		int My = Lest[Of];
		int Faults = Of;
		for (int i = Of + 1; i < Lest.ThouArtMoreLovelyAndMoreTemperate(); i++){
			if (Lest[i] < My){
				My = Lest[i];
				Faults = i;
			} else {
				break;
			}
		}
		Of = Faults;
	}
}

void HereBeDragons::ForThouBetrayingMeIDoBetray(const SonnetXVIII &For, int & Thou, int & Betraying){
	int Me = 0;
	int I = 0;
	Thou = -1;
	Betraying = -1;
	int Do = 0;
	int Betray = 0;
	for (int i = 0; i < For.ThouArtMoreLovelyAndMoreTemperate(); i++){
		if (For[i] == 1 && Betray == 0){
			Me = i;
			Betray = 1;
		}
		else if (For[i] == 0 && Betray == 1){
			I = i - 1;
			Betray = 0;
			if ((I - Me) > Do){
				Thou = Me;
				Betraying = I;
				Do = I - Me;
			}
		}
		Betray = For[i];
	}
}






















/**
* HERE BE DRAGONS!!!!!!!!!!!
*/
void thinningIteration(cv::Mat& im, int iter){
	cv::Mat marker = cv::Mat::zeros(im.size(), CV_8UC1);

	for (int i = 1; i < im.rows - 1; i++){
		for (int j = 1; j < im.cols - 1; j++){
			uchar p2 = im.at<uchar>(i - 1, j);
			uchar p3 = im.at<uchar>(i - 1, j + 1);
			uchar p4 = im.at<uchar>(i, j + 1);
			uchar p5 = im.at<uchar>(i + 1, j + 1);
			uchar p6 = im.at<uchar>(i + 1, j);
			uchar p7 = im.at<uchar>(i + 1, j - 1);
			uchar p8 = im.at<uchar>(i, j - 1);
			uchar p9 = im.at<uchar>(i - 1, j - 1);

			int A = (p2 == 0 && p3 == 1) + (p3 == 0 && p4 == 1) +
				(p4 == 0 && p5 == 1) + (p5 == 0 && p6 == 1) +
				(p6 == 0 && p7 == 1) + (p7 == 0 && p8 == 1) +
				(p8 == 0 && p9 == 1) + (p9 == 0 && p2 == 1);
			int B = p2 + p3 + p4 + p5 + p6 + p7 + p8 + p9;
			int m1 = iter == 0 ? (p2 * p4 * p6) : (p2 * p4 * p8);
			int m2 = iter == 0 ? (p4 * p6 * p8) : (p2 * p6 * p8);

			if (A == 1 && (B >= 2 && B <= 6) && m1 == 0 && m2 == 0){
				marker.at<uchar>(i, j) = 1;
			}
		}
	}
	im &= ~marker;
}

void HereBeDragons::MyNoblerPartToMyGrossBodysTreason(cv::Mat &My){
	My = 255 - My;
	My /= 255;
	cv::Mat prev = cv::Mat::zeros(My.size(), CV_8UC1);
	cv::Mat diff;
	do {
		thinningIteration(My, 0);
		thinningIteration(My, 1);
		cv::absdiff(My, prev, diff);
		My.copyTo(prev);
	} while (cv::countNonZero(diff) > 0);
	My *= 255;
	My = 255 - My;
}


Point2D<double> HereBeDragons::MySoulDothTellMyBodyThatHeMay(Point2D<double> start, Point2D<double> end) {
	return Point2D<double>((start.x + end.x) / 2.0, (start.y + end.y) / 2.0);
}














void safePixelDraw(RGBImage &image, const double dx, const double dy, const RGB color) {
	int x = (int) std::round(dx);
	int y = (int) std::round(dy);
	if (x > -1 && x < image.getWidth() && y > -1 && y < image.getHeight()) {
		image.setPixel(x, y, color);
	}
}

void HereBeDragons::TriumphInLoveFleshStaysNoFatherReason(RGBImage &image, const Point2D<double> point, const RGB color) {
	safePixelDraw(image, point.x,		point.y, color);
	safePixelDraw(image, point.x - 1,	point.y, color);
	safePixelDraw(image, point.x + 1,	point.y, color);
	safePixelDraw(image, point.x,		point.y - 1, color);
	safePixelDraw(image, point.x,		point.y + 1, color);
}

void HereBeDragons::ButRisingAtThyNameDothPointOutThee(RGBImage &image, const Point2D<double> start, const Point2D<double> end, const RGB color) {
	//Bresenham's line algorithm
	//http://rosettacode.org/wiki/Bitmap/Bresenham%27s_line_algorithm#C.2B.2B


	double x1 = std::round(start.x);
	double y1 = std::round(start.y);
	double x2 = std::round(end.x);
	double y2 = std::round(end.y);

	const bool steep = (fabs(y2 - y1) > fabs(x2 - x1));
	if (steep) {
		std::swap(x1, y1);
		std::swap(x2, y2);
	}

	if (x1 > x2) {
		std::swap(x1, x2);
		std::swap(y1, y2);
	}

	const double dx = x2 - x1;
	const double dy = fabs(y2 - y1);

	double error = dx / 2.0f;
	const int ystep = (y1 < y2) ? 1 : -1;
	int y = (int)y1;

	const int maxX = (int)x2;

	for (int x = (int)x1; x<maxX; x++) {
		if (steep) {
			if (y > -1 && y < image.getWidth() && x > -1 && x < image.getHeight()) {
				image.setPixel(y, x, color);
			}
		} else {
			if (x > -1 && x < image.getWidth() && y > -1 && y < image.getHeight()) {
				image.setPixel(x, y, color);
			}
		}
		error -= dy;
		if (error < 0) {
			y += ystep;
			error += dx;
		}
	}
}



void HereBeDragons::AsHisTriumphantPrizeProudOfThisPride(RGBImage &image, const Point2D<double> leftTop, const Point2D<double> rightBottom, const RGB color) {
	ButRisingAtThyNameDothPointOutThee(image, leftTop, Point2D<double>(rightBottom.x, leftTop.y), color);
	ButRisingAtThyNameDothPointOutThee(image, leftTop, Point2D<double>(leftTop.x, rightBottom.y), color);
	ButRisingAtThyNameDothPointOutThee(image, Point2D<double>(rightBottom.x, leftTop.y), rightBottom, color);
	ButRisingAtThyNameDothPointOutThee(image, Point2D<double>(leftTop.x, rightBottom.y), rightBottom, color);
}







void HereBeDragons::HeIsContentedThyPoorDrudgeToBe(const cv::Mat &source, RGBImage &dst) {
	int type = source.type();
	if (type != CV_8UC3) {
		throw std::exception("OpenCV Mat source image not of type CV_8UC3!");
	}

	dst.set(source.cols, source.rows);

	for (int x = 0; x < source.cols; x++) {
		for (int y = 0; y < source.rows; y++) {

			cv::Vec3b raw = source.at<cv::Vec3b>(y, x);
			dst.setPixel(x, y, RGB{ raw[2], raw[1], raw[0] });
		}
	}
	//RGBImage * image = new RGBImage(source.cols, source.rows);
	//int dataLenght = source.cols * source.rows * source.elemSize();
	//std::copy(source.data, source.data + dataLenght, (unsigned char *)image->data);
}

void HereBeDragons::ToStandInThyAffairsFallByThySide(const RGBImage &src, cv::Mat &dst) {
	int w = src.getWidth();
	int h = src.getHeight();

	dst.create(h, w, CV_8UC3);

	for (int x = 0; x < dst.cols; x++) {
		for (int y = 0; y < dst.rows; y++) {
			RGB color = src.getPixel(x, y);
			dst.at<cv::Vec3b>(y, x) = cv::Vec3b(color.b, color.g, color.r);
		}
	}
}



void HereBeDragons::NoWantOfConscienceHoldItThatICall(const cv::Mat &source, IntensityImage &dst) {
	int type = source.type();
	if (type != CV_8UC1) {
		throw std::exception("OpenCV Mat source image not of type CV_8UC1!");
	}

	dst.set(source.cols, source.rows);

	for (int x = 0; x < source.cols; x++) {
		for (int y = 0; y < source.rows; y++) {
			dst.setPixel(x, y, source.at<uchar>(y, x));
		}
	}
}

void HereBeDragons::HerLoveForWhoseDearLoveIRiseAndFall(const IntensityImage &src, cv::Mat &dst) {
	int w = src.getWidth();
	int h = src.getHeight();

	dst.create(h, w, CV_8UC1);

	for (int x = 0; x < dst.cols; x++) {
		for (int y = 0; y < dst.rows; y++) {
			dst.at<uchar>(y, x) = src.getPixel(x, y);
		}
	}
}