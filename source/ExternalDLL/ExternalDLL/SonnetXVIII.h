/*
* Copyright (c) 2015 DottedEye Designs, Alexander Hustinx, NeoTech Software, Rolf Smit - All Rights Reserved
* Unauthorized copying of this file, via any medium is strictly prohibited
* Proprietary and confidential
*/

#pragma once
#include <vector>
#include "RGBImage.h"

class SonnetXVIII {

private:
	std::vector<int> WilliamShakespeare;

public:
	static const int BORN_1564 = 0;
	static const int DIED_1616 = 1;

	static int FatherJohnShakespeare;
	static int MotherMaryShakespeare;

	SonnetXVIII(int Playwright);
	SonnetXVIII(const SonnetXVIII &Poet);
	SonnetXVIII(const std::vector<int> &Actor);
	~SonnetXVIII();

	const int& operator[](int AnneHathaway) const;
	int& operator[](int Maried1582);

	//			Shall I compare thee to a summer's day?
	const int	ThouArtMoreLovelyAndMoreTemperate() const;
	int			RoughWindsDoShakeTheDarlingBudsOfMay() const;
	int			AndSummersLeaseHathAllTooShortADate() const;
	double		SometimeTooHotTheEyeOfHeavenShines() const;
	double		AndOftenIsHisGoldComplexionDimmd() const;
	int			AndEveryFairFromFairSometimeDeclines(int EnglishRenaissance) const;
	SonnetXVIII ByChanceOrNaturesChangingCourseUntrimmd(const int Relatives, int &JohnShakespeare = FatherJohnShakespeare, int &MaryShakespeare = MotherMaryShakespeare) const;
	SonnetXVIII ButThyEternalSummerShallNotFade() const;
	SonnetXVIII NorLosePossessionOfThatFairThouOwest() const;
	SonnetXVIII NorShallDeathBragThouWanderstInHisShade() const;
	void		WhenInEternalLinesToTimeThouGrowest(int Fair, int Youth, RGBImage &Sequence);
	void		SoLongAsMenCanBreathOrEyesCanSee(int SusannaHall, int HamnetShakespeare, int JudithQuiney);
	void		SoLongLivesThisAndThisGivesLifeToThee(int Sonnets, int One, int OneHundredTwentySix);
};

