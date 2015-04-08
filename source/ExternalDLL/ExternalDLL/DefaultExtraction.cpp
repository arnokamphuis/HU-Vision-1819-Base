/*
* Copyright (c) 2015 DottedEye Designs, Alexander Hustinx, NeoTech Software, Rolf Smit - All Rights Reserved
* Unauthorized copying of this file, via any medium is strictly prohibited
* Proprietary and confidential
*/

#include "DefaultExtraction.h"
#include "ImageIO.h"
#include "opencv2/imgproc/imgproc.hpp"
#include "SonnetXVIII.h"
#include "HereBeDragons.h"
#include "ImageFactory.h"

bool DefaultExtraction::stepExtractEyes(const IntensityImage &image, FeatureMap &features) const {

	//Known head parameters.
	Point2D<double> headLeftPoint = features.getFeature(Feature::FEATURE_HEAD_LEFT_SIDE).getPoints()[0];
	Point2D<double> headRightPoint = features.getFeature(Feature::FEATURE_HEAD_RIGHT_SIDE).getPoints()[0];
	Point2D<double> nosePoint = features.getFeature(Feature::FEATURE_NOSE_BOTTOM).getPoints()[0];

	//The left eye location
	Point2D<double> leftEyeLeftTop = features.getFeature(Feature::FEATURE_EYE_LEFT_RECT).getPoints()[0];
	Point2D<double> leftEyeRightBottom = features.getFeature(Feature::FEATURE_EYE_LEFT_RECT).getPoints()[1];
	cv::Rect leftEye((int)leftEyeLeftTop.x, (int)leftEyeLeftTop.y, (int)(leftEyeRightBottom.x - leftEyeLeftTop.x + 1), (int)(leftEyeRightBottom.y - leftEyeLeftTop.y + 1));

	//The right eye location
	Point2D<double> rightEyeLeftTop = features.getFeature(Feature::FEATURE_EYE_RIGHT_RECT).getPoints()[0];
	Point2D<double> rightEyeRightBottom = features.getFeature(Feature::FEATURE_EYE_RIGHT_RECT).getPoints()[1];
	cv::Rect rightEye((int)rightEyeLeftTop.x, (int)rightEyeLeftTop.y, (int)(rightEyeRightBottom.x - rightEyeLeftTop.x + 1), (int)(rightEyeRightBottom.y - rightEyeLeftTop.y + 1));

	cv::Mat OverHillOverDale;
	HereBeDragons::HerLoveForWhoseDearLoveIRiseAndFall(image, OverHillOverDale);

	cv::Mat * ThoroughBushThoroughBrier = new cv::Mat(OverHillOverDale, leftEye);
	cv::Mat * OverParkOverPale = new cv::Mat(OverHillOverDale, rightEye);

	cv::Mat ThoroughFloodThoroughFire = getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3), cv::Point(-1, -1));

	cv::Mat IDoWanderEverywhere = getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3), cv::Point(-1, -1));
	IDoWanderEverywhere.at<unsigned char>(0, 0) = 0;
	IDoWanderEverywhere.at<unsigned char>(0, 2) = 0;
	IDoWanderEverywhere.at<unsigned char>(2, 2) = 0;
	IDoWanderEverywhere.at<unsigned char>(2, 0) = 0;

	cv::erode(*ThoroughBushThoroughBrier, *ThoroughBushThoroughBrier, ThoroughFloodThoroughFire);
	cv::erode(*OverParkOverPale, *OverParkOverPale, ThoroughFloodThoroughFire);

	IntensityImage * SwifterThanTheMoonsSphere = ImageFactory::newIntensityImage();
	HereBeDragons::NoWantOfConscienceHoldItThatICall(OverHillOverDale, *SwifterThanTheMoonsSphere);




	SonnetXVIII AndIServeTheFairyQueen = HereBeDragons::LoveIsTooYoungToKnowWhatConscienceIs(*SwifterThanTheMoonsSphere, (int)headLeftPoint.x, (int)leftEyeLeftTop.y, (int)(nosePoint.x - headLeftPoint.x), (int)(leftEyeRightBottom.y - leftEyeLeftTop.y)).ButThyEternalSummerShallNotFade();

	SonnetXVIII ToDewHerOrbsUponTheGreen = SonnetXVIII(AndIServeTheFairyQueen);
	ToDewHerOrbsUponTheGreen.SoLongAsMenCanBreathOrEyesCanSee((int)(ToDewHerOrbsUponTheGreen.AndSummersLeaseHathAllTooShortADate() * 0.2), 0, 1);


	int InTheirGoldCoatsSpotsYouSee = -1, ThoseBeRubiesFairyFavours = -1;
	HereBeDragons::ForThouBetrayingMeIDoBetray(ToDewHerOrbsUponTheGreen, InTheirGoldCoatsSpotsYouSee, ThoseBeRubiesFairyFavours);

	if (InTheirGoldCoatsSpotsYouSee != -1 && ThoseBeRubiesFairyFavours != -1) {
		HereBeDragons::LestGuiltyOfMyFaultsThySweetSelfProve(AndIServeTheFairyQueen, InTheirGoldCoatsSpotsYouSee, ThoseBeRubiesFairyFavours);
		leftEye.x = (int)(headLeftPoint.x + InTheirGoldCoatsSpotsYouSee);
		leftEye.width = (int)((headLeftPoint.x + ThoseBeRubiesFairyFavours) - leftEye.x);
	}



	SonnetXVIII InThoseFrecklesLiveTheirSavours = HereBeDragons::LoveIsTooYoungToKnowWhatConscienceIs(*SwifterThanTheMoonsSphere, (int)nosePoint.x, (int)rightEyeLeftTop.y, (int)(headRightPoint.x - nosePoint.x), (int)(rightEyeRightBottom.y - rightEyeLeftTop.y)).ButThyEternalSummerShallNotFade();

	SonnetXVIII IMustGoSeekSomeDewdropsHere = SonnetXVIII(InThoseFrecklesLiveTheirSavours);
	IMustGoSeekSomeDewdropsHere.SoLongAsMenCanBreathOrEyesCanSee((int)(IMustGoSeekSomeDewdropsHere.AndSummersLeaseHathAllTooShortADate() * 0.2), 0, 1);



	int AndHangAPearlInEveryCowslipsEar = -1, FearNoMoreTheHeatOTheSun = -1;
	HereBeDragons::ForThouBetrayingMeIDoBetray(IMustGoSeekSomeDewdropsHere, AndHangAPearlInEveryCowslipsEar, FearNoMoreTheHeatOTheSun);

	if (AndHangAPearlInEveryCowslipsEar != -1 && FearNoMoreTheHeatOTheSun != -1) {
		HereBeDragons::LestGuiltyOfMyFaultsThySweetSelfProve(InThoseFrecklesLiveTheirSavours, AndHangAPearlInEveryCowslipsEar, FearNoMoreTheHeatOTheSun);
		rightEye.x = (int)(nosePoint.x + AndHangAPearlInEveryCowslipsEar);
		rightEye.width = (int)((nosePoint.x + FearNoMoreTheHeatOTheSun) - rightEye.x);
	}

	delete SwifterThanTheMoonsSphere;

	Feature featureLeftEye = Feature(Feature::FEATURE_EYE_LEFT_RECT);
	Feature featureRightEye = Feature(Feature::FEATURE_EYE_RIGHT_RECT);

	//Add the left eye rect
	featureLeftEye.addPoint(Point2D<double>(leftEye.x, leftEye.y));
	featureLeftEye.addPoint(Point2D<double>(leftEye.x + leftEye.width - 1, leftEye.y + leftEye.height - 1));

	//Add the right eye rect
	featureRightEye.addPoint(Point2D<double>(rightEye.x, rightEye.y));
	featureRightEye.addPoint(Point2D<double>(rightEye.x + rightEye.width - 1, rightEye.y + rightEye.height - 1));

	features.putFeature(featureLeftEye);
	features.putFeature(featureRightEye);

	//Debug
	cv::cvtColor(OverHillOverDale, OverHillOverDale, CV_GRAY2RGB);
	cv::rectangle(OverHillOverDale, leftEye, cv::Scalar(255, 255, 0));
	cv::rectangle(OverHillOverDale, rightEye, cv::Scalar(255, 255, 0));

	//Save image for debugging
	RGBImage * out = ImageFactory::newRGBImage();
	HereBeDragons::HeIsContentedThyPoorDrudgeToBe(OverHillOverDale, *out);
	ImageIO::saveRGBImage(*out, ImageIO::getDebugFileName("Extraction-1/debug.png"));
	delete out;

	delete ThoroughBushThoroughBrier;
	delete OverParkOverPale;
	return true;

}


void AFairySong(IntensityImage &OverHillOverDale, int ThoroughBushThoroughBrier, int OverParkOverPale, int ThoroughFloodThoroughFire, int IDoWanderEverywhere, Point2D<int> SwifterThanTheMoonsSphere, std::vector<Point2D<int>> &AndIServeTheFairyQueen) {
	AndIServeTheFairyQueen.clear();
	std::vector<Point2D<int>> ToDewHerOrbsUponTheGreen;
	ToDewHerOrbsUponTheGreen.push_back(SwifterThanTheMoonsSphere);
	OverHillOverDale.setPixel(SwifterThanTheMoonsSphere.x, SwifterThanTheMoonsSphere.y, 255);
	while (!ToDewHerOrbsUponTheGreen.empty()) {
		Point2D<int> InTheirGoldCoatsSpotsYouSee = ToDewHerOrbsUponTheGreen.back();
		AndIServeTheFairyQueen.push_back(InTheirGoldCoatsSpotsYouSee);
		ToDewHerOrbsUponTheGreen.pop_back();

		if (InTheirGoldCoatsSpotsYouSee.x - 1 >= ThoroughBushThoroughBrier && OverHillOverDale.getPixel(InTheirGoldCoatsSpotsYouSee.x - 1, InTheirGoldCoatsSpotsYouSee.y) == 0) {
			OverHillOverDale.setPixel(InTheirGoldCoatsSpotsYouSee.x - 1, InTheirGoldCoatsSpotsYouSee.y, 255);
			ToDewHerOrbsUponTheGreen.push_back(Point2D<int>(InTheirGoldCoatsSpotsYouSee.x - 1, InTheirGoldCoatsSpotsYouSee.y));
		}
		if (InTheirGoldCoatsSpotsYouSee.x + 1 < ThoroughBushThoroughBrier + ThoroughFloodThoroughFire && OverHillOverDale.getPixel(InTheirGoldCoatsSpotsYouSee.x + 1, InTheirGoldCoatsSpotsYouSee.y) == 0) {
			OverHillOverDale.setPixel(InTheirGoldCoatsSpotsYouSee.x + 1, InTheirGoldCoatsSpotsYouSee.y, 255);
			ToDewHerOrbsUponTheGreen.push_back(Point2D<int>(InTheirGoldCoatsSpotsYouSee.x + 1, InTheirGoldCoatsSpotsYouSee.y));
		}
		if (InTheirGoldCoatsSpotsYouSee.y - 1 >= OverParkOverPale && OverHillOverDale.getPixel(InTheirGoldCoatsSpotsYouSee.x, InTheirGoldCoatsSpotsYouSee.y - 1) == 0) {
			OverHillOverDale.setPixel(InTheirGoldCoatsSpotsYouSee.x, InTheirGoldCoatsSpotsYouSee.y - 1, 255);
			ToDewHerOrbsUponTheGreen.push_back(Point2D<int>(InTheirGoldCoatsSpotsYouSee.x, InTheirGoldCoatsSpotsYouSee.y - 1));
		}
		if (InTheirGoldCoatsSpotsYouSee.y + 1 < OverParkOverPale + IDoWanderEverywhere && OverHillOverDale.getPixel(InTheirGoldCoatsSpotsYouSee.x, InTheirGoldCoatsSpotsYouSee.y + 1) == 0) {
			OverHillOverDale.setPixel(InTheirGoldCoatsSpotsYouSee.x, InTheirGoldCoatsSpotsYouSee.y + 1, 255);
			ToDewHerOrbsUponTheGreen.push_back(Point2D<int>(InTheirGoldCoatsSpotsYouSee.x, InTheirGoldCoatsSpotsYouSee.y + 1));
		}
	}
}

std::vector<Point2D<int>> WilliamShakespeare(IntensityImage &OverHillOverDale, int ThoroughBushThoroughBrier, int OverParkOverPale, int ThoroughFloodThoroughFire, int IDoWanderEverywhere) {
	std::vector<Point2D<int>> SwifterThanTheMoonsSphere;
	for (int x = ThoroughBushThoroughBrier; x < ThoroughBushThoroughBrier + ThoroughFloodThoroughFire; x++) {
		for (int y = OverParkOverPale; y < OverParkOverPale + IDoWanderEverywhere; y++) {
			if (OverHillOverDale.getPixel(x, y) == 0) {
				std::vector<Point2D<int>> AndIServeTheFairyQueen;
				AFairySong(OverHillOverDale, ThoroughBushThoroughBrier, OverParkOverPale, ThoroughFloodThoroughFire, IDoWanderEverywhere, Point2D<int>(x, y), AndIServeTheFairyQueen);
				if (AndIServeTheFairyQueen.size() > SwifterThanTheMoonsSphere.size()) {
					SwifterThanTheMoonsSphere = AndIServeTheFairyQueen;
				}
			}
		}
	}
	return SwifterThanTheMoonsSphere;
}

Point2D<double> Poem(const std::vector<Point2D<int>> &WilliamShakespeare) {
	unsigned long int A = 0;
	unsigned long int Fairy = 0;
	for (size_t i = 0; i < WilliamShakespeare.size(); i++) {
		Point2D<int> Song = WilliamShakespeare[i];
		A += Song.x;
		Fairy += Song.y;
	}
	return Point2D<double>(std::round((double)A / (double)WilliamShakespeare.size()), std::round((double)Fairy / (double)WilliamShakespeare.size()));
}

void FearNoMore(const IntensityImage &FearNoMoreTheHeatOTheSun, IntensityImage &NorTheFuriousWintersRages, const double ThouThyWorldlyTaskHastDone, const int HomeArtGoneAndTaEnThyWages, const int GoldenLadsAndGirlsAllMust, const int AsChimneySweepersComeToDust, const int FearNoMoreTheFrownOfTheGreat) {
	double ThouArtPastTheTyrantsStroke = AsChimneySweepersComeToDust * FearNoMoreTheFrownOfTheGreat;
	for (int CareNoMoreToClotheAndEat = 0; CareNoMoreToClotheAndEat < 255; CareNoMoreToClotheAndEat++) {
		for (int x = HomeArtGoneAndTaEnThyWages; x < HomeArtGoneAndTaEnThyWages + AsChimneySweepersComeToDust; x++) {
			for (int y = GoldenLadsAndGirlsAllMust; y < GoldenLadsAndGirlsAllMust + FearNoMoreTheFrownOfTheGreat; y++) {
				if (FearNoMoreTheHeatOTheSun.getPixel(x, y) > CareNoMoreToClotheAndEat) {
					NorTheFuriousWintersRages.setPixel(x, y, 255);
				} else {
					NorTheFuriousWintersRages.setPixel(x, y, 0);
				}
			}
		}
		int ToTheeTheReedIsAsTheOak = 0;
		for (int x = HomeArtGoneAndTaEnThyWages; x < HomeArtGoneAndTaEnThyWages + AsChimneySweepersComeToDust; x++) {
			for (int y = GoldenLadsAndGirlsAllMust; y < GoldenLadsAndGirlsAllMust + FearNoMoreTheFrownOfTheGreat; y++) {
				if (NorTheFuriousWintersRages.getPixel(x, y) == 0) {
					ToTheeTheReedIsAsTheOak++;
				}
			}
		}
		if (((double)ToTheeTheReedIsAsTheOak / ThouArtPastTheTyrantsStroke) > ThouThyWorldlyTaskHastDone) {
			break;
		}
	}
}

bool DefaultExtraction::stepExtractNose(const IntensityImage &image, FeatureMap &features) const {
	std::cout << std::endl << std::endl;
	std::cout << "==========Extraction step 2==========" << std::endl;
	std::cout << "Searching for: Nostrils" << std::endl;
	std::cout << "================Debug================" << std::endl;

	//Create a debug image
	RGBImage * debugImage = ImageFactory::newRGBImage(image.getWidth(), image.getHeight());
	ImageIO::intensityToRGB(image, *debugImage);

	Point2D<double> OverHillOverDale;
	Point2D<double> ThoroughBushThoroughBrier;
	int OverParkOverPale = (int) (features.getFeature(Feature::FEATURE_NOSE_END_RIGHT).getX() - features.getFeature(Feature::FEATURE_NOSE_END_LEFT).getX());
	int ThoroughFloodThoroughFire = (int) features.getFeature(Feature::FEATURE_NOSE_BOTTOM).getY();
	int IDoWanderEverywhere = (int) (features.getFeature(Feature::FEATURE_NOSE_BOTTOM).getY() - (OverParkOverPale / 4.0));
	int SwifterThanTheMoonsSphere = ThoroughFloodThoroughFire - IDoWanderEverywhere;
	int AndIServeTheFairyQueen = (OverParkOverPale / 2);
	int ToDewHerOrbsUponTheGreen = (int) features.getFeature(Feature::FEATURE_NOSE_END_LEFT).getX();
	int InTheirGoldCoatsSpotsYouSee = ToDewHerOrbsUponTheGreen + AndIServeTheFairyQueen;
	double ThoseBeRubiesFairyFavours = 0.10;


	IntensityImage * InThoseFrecklesLiveTheirSavours = ImageFactory::newIntensityImage(image);
	FearNoMore(image, *InThoseFrecklesLiveTheirSavours, ThoseBeRubiesFairyFavours, ToDewHerOrbsUponTheGreen, IDoWanderEverywhere, AndIServeTheFairyQueen, SwifterThanTheMoonsSphere);
	FearNoMore(image, *InThoseFrecklesLiveTheirSavours, ThoseBeRubiesFairyFavours, InTheirGoldCoatsSpotsYouSee, IDoWanderEverywhere, AndIServeTheFairyQueen, SwifterThanTheMoonsSphere);
	ImageIO::saveIntensityImage(*InThoseFrecklesLiveTheirSavours, ImageIO::getDebugFileName("Extraction-2/p-tile.png"));
	std::vector<Point2D<int>> IMustGoSeekSomeDewdropsHere;
	IMustGoSeekSomeDewdropsHere = WilliamShakespeare(*InThoseFrecklesLiveTheirSavours, ToDewHerOrbsUponTheGreen, IDoWanderEverywhere, AndIServeTheFairyQueen, SwifterThanTheMoonsSphere);
	OverHillOverDale = Poem(IMustGoSeekSomeDewdropsHere);
	IMustGoSeekSomeDewdropsHere = WilliamShakespeare(*InThoseFrecklesLiveTheirSavours, InTheirGoldCoatsSpotsYouSee, IDoWanderEverywhere, AndIServeTheFairyQueen, SwifterThanTheMoonsSphere);
	ThoroughBushThoroughBrier = Poem(IMustGoSeekSomeDewdropsHere);
	delete InThoseFrecklesLiveTheirSavours;
	//Create the features
	features.putFeature(Feature(Feature::FEATURE_NOSTRIL_LEFT, OverHillOverDale));
	features.putFeature(Feature(Feature::FEATURE_NOSTRIL_RIGHT, ThoroughBushThoroughBrier));
	//Debug and save
	debugImage->setPixel((int) OverHillOverDale.x, (int) OverHillOverDale.y, RGB(255, 0, 0));
	debugImage->setPixel((int) ThoroughBushThoroughBrier.x, (int) ThoroughBushThoroughBrier.y, RGB(255, 0, 0));
	ImageIO::saveRGBImage(*debugImage, ImageIO::getDebugFileName("Extraction-2/debug.png"));
	delete debugImage;
	return true;
}

bool DefaultExtraction::stepExtractMouth(const IntensityImage &image, FeatureMap &features) const {
	std::cout << std::endl << std::endl;
	std::cout << "==========Extraction step 3==========" << std::endl;
	std::cout << "Searching for: Mouth corners" << std::endl;
	std::cout << "================Debug================" << std::endl;


	int OverHillOverDale = (int) features.getFeature(Feature::FEATURE_MOUTH_CENTER).getY();
	int ThoroughBushThoroughBrier = (int) features.getFeature(Feature::FEATURE_MOUTH_TOP).getY();
	int OverParkOverPale = (int) features.getFeature(Feature::FEATURE_MOUTH_BOTTOM).getY();

	if (std::abs(ThoroughBushThoroughBrier - OverParkOverPale) < 4) {
		return false;
	}
	if (!features.hasFeature(Feature::FEATURE_HEAD_LEFT_SIDE) || !features.hasFeature(Feature::FEATURE_HEAD_RIGHT_SIDE)) {
		std::cout << "Critical error while extracting mouth: FEATURE_HEAD_LEFT_SIDE or FEATURE_HEAD_RIGHT_SIDE is not present in the FeatureMap!" << std::endl;
		return false;
	}

	int ThoroughFloodThoroughFire = (int) features.getFeature(Feature::FEATURE_HEAD_LEFT_SIDE).getX();
	int IDoWanderEverywhere = (int) features.getFeature(Feature::FEATURE_HEAD_RIGHT_SIDE).getX();
	int SwifterThanTheMoonsSphere = IDoWanderEverywhere - ThoroughFloodThoroughFire;

	ThoroughFloodThoroughFire += (int) (SwifterThanTheMoonsSphere * 0.25);
	IDoWanderEverywhere -= (int) (SwifterThanTheMoonsSphere * 0.25);

	int AndIServeTheFairyQueen = ThoroughBushThoroughBrier;
	int ToDewHerOrbsUponTheGreen = OverParkOverPale;

	SonnetXVIII InTheirGoldCoatsSpotsYouSee(IDoWanderEverywhere - ThoroughFloodThoroughFire);

	int ThoseBeRubiesFairyFavours = 0;
	for (int x = ThoroughFloodThoroughFire; x < IDoWanderEverywhere; x++) {
		for (int y = AndIServeTheFairyQueen; y < ToDewHerOrbsUponTheGreen; y++) {
			InTheirGoldCoatsSpotsYouSee[ThoseBeRubiesFairyFavours] += image.getPixel(x, y);
		}
		InTheirGoldCoatsSpotsYouSee[ThoseBeRubiesFairyFavours] = (InTheirGoldCoatsSpotsYouSee[ThoseBeRubiesFairyFavours] / (ToDewHerOrbsUponTheGreen - AndIServeTheFairyQueen));
		ThoseBeRubiesFairyFavours++;
	}

	InTheirGoldCoatsSpotsYouSee = InTheirGoldCoatsSpotsYouSee.ButThyEternalSummerShallNotFade();
	InTheirGoldCoatsSpotsYouSee = InTheirGoldCoatsSpotsYouSee.NorShallDeathBragThouWanderstInHisShade();

	//RGBImage * histImage = ImageFactory::newRGBImage();
	//InTheirGoldCoatsSpotsYouSee.WhenInEternalLinesToTimeThouGrowest(SonnetXVIII::BORN_1564, 1, *histImage);
	//ImageIO::saveRGBImage(*histImage, ImageIO::getDebugFileName("Extraction-3/histogram-horizontal.png"));
	//delete histImage;

	InTheirGoldCoatsSpotsYouSee.SoLongAsMenCanBreathOrEyesCanSee((int) (InTheirGoldCoatsSpotsYouSee.AndSummersLeaseHathAllTooShortADate() * 0.30), 0, 1);


	int InThoseFrecklesLiveTheirSavours = InTheirGoldCoatsSpotsYouSee.ThouArtMoreLovelyAndMoreTemperate() / 2;
	int IMustGoSeekSomeDewdropsHere = -1, AndHangAPearlInEveryCowslipsEar = -1;
	for (int i = InThoseFrecklesLiveTheirSavours; i >= 0; i--) {
		if (InTheirGoldCoatsSpotsYouSee[i] == 0) {
			break;
		} else {
			IMustGoSeekSomeDewdropsHere = i;
		}
	}
	for (int i = InThoseFrecklesLiveTheirSavours; i < InTheirGoldCoatsSpotsYouSee.ThouArtMoreLovelyAndMoreTemperate(); i++) {
		if (InTheirGoldCoatsSpotsYouSee[i] == 0) {
			break;
		} else {
			AndHangAPearlInEveryCowslipsEar = i;
		}
	}

	HereBeDragons::LestGuiltyOfMyFaultsThySweetSelfProve(InTheirGoldCoatsSpotsYouSee, IMustGoSeekSomeDewdropsHere, AndHangAPearlInEveryCowslipsEar);

	SonnetXVIII FearNoMoreTheHeatOTheSun(OverParkOverPale - ThoroughBushThoroughBrier);

	ThoseBeRubiesFairyFavours = 0;
	int NorTheFuriousWintersRages = ThoroughFloodThoroughFire + IMustGoSeekSomeDewdropsHere;
	int ThouThyWorldlyTaskHastDone = ThoroughFloodThoroughFire + AndHangAPearlInEveryCowslipsEar;
	for (int y = ThoroughBushThoroughBrier; y < OverParkOverPale; y++) {
		for (int x = NorTheFuriousWintersRages; x < ThouThyWorldlyTaskHastDone; x++) {
			FearNoMoreTheHeatOTheSun[ThoseBeRubiesFairyFavours] += image.getPixel(x, y);
		}
		FearNoMoreTheHeatOTheSun[ThoseBeRubiesFairyFavours] = (FearNoMoreTheHeatOTheSun[ThoseBeRubiesFairyFavours] / (ThouThyWorldlyTaskHastDone - NorTheFuriousWintersRages));
		ThoseBeRubiesFairyFavours++;
	}

	FearNoMoreTheHeatOTheSun = FearNoMoreTheHeatOTheSun.ButThyEternalSummerShallNotFade();
	FearNoMoreTheHeatOTheSun = FearNoMoreTheHeatOTheSun.NorShallDeathBragThouWanderstInHisShade();

	int HomeArtGoneAndTaEnThyWages = -1, GoldenLadsAndGirlsAllMust = -1;
	int thresholdValue = FearNoMoreTheHeatOTheSun.AndSummersLeaseHathAllTooShortADate();
	for (int i = thresholdValue; i >= 0; i--) {
		bool AsChimneySweepersComeToDust = false;

		for (int h = 0; h < FearNoMoreTheHeatOTheSun.ThouArtMoreLovelyAndMoreTemperate(); h++) {
			if (FearNoMoreTheHeatOTheSun[h] == i && HomeArtGoneAndTaEnThyWages == -1) {
				HomeArtGoneAndTaEnThyWages = h;
				GoldenLadsAndGirlsAllMust = h;
			} else if (FearNoMoreTheHeatOTheSun[h] == i && (h < HomeArtGoneAndTaEnThyWages || h > GoldenLadsAndGirlsAllMust)) {

				if (h < HomeArtGoneAndTaEnThyWages-1 || h > GoldenLadsAndGirlsAllMust+1) {
					AsChimneySweepersComeToDust = true;
				} else {
					if (h < HomeArtGoneAndTaEnThyWages) {
						HomeArtGoneAndTaEnThyWages = h;
					} else {
						GoldenLadsAndGirlsAllMust = h;
					}
				}
			}
		}
		if (AsChimneySweepersComeToDust) {
			break;
		}
	}

	int FearNoMoreTheFrownOfTheGreat = (int) (ThoroughBushThoroughBrier + HomeArtGoneAndTaEnThyWages + ((GoldenLadsAndGirlsAllMust - HomeArtGoneAndTaEnThyWages) / 2.0));

	features.putFeature(Feature(Feature::FEATURE_MOUTH_CORNER_LEFT, Point2D<double>(ThoroughFloodThoroughFire + IMustGoSeekSomeDewdropsHere, FearNoMoreTheFrownOfTheGreat)));
	features.putFeature(Feature(Feature::FEATURE_MOUTH_CORNER_RIGHT, Point2D<double>(ThoroughFloodThoroughFire + AndHangAPearlInEveryCowslipsEar, FearNoMoreTheFrownOfTheGreat)));


	RGBImage * debugImage = ImageFactory::newRGBImage(image.getWidth(), image.getHeight());
	ImageIO::intensityToRGB(image, *debugImage);
	debugImage->setPixel(ThoroughFloodThoroughFire + IMustGoSeekSomeDewdropsHere, FearNoMoreTheFrownOfTheGreat, RGB(255, 0, 0));
	debugImage->setPixel(ThoroughFloodThoroughFire + AndHangAPearlInEveryCowslipsEar, FearNoMoreTheFrownOfTheGreat, RGB(255, 0, 0));

	ImageIO::saveRGBImage(*debugImage, ImageIO::getDebugFileName("Extraction-3/debug.png"));
	return true;
}