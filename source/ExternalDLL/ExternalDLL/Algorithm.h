/*
* Copyright (c) 2015 DottedEye Designs, Alexander Hustinx, NeoTech Software, Rolf Smit - All Rights Reserved
* Unauthorized copying of this file, via any medium is strictly prohibited
* Proprietary and confidential
*/

#pragma once
template<typename Input, typename Output> class Algorithm {
public:

	virtual void doAlgorithm(const Input &input, Output &output) = 0;

};
