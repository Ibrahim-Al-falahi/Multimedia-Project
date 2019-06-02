#include <iostream>
#include "opencv2/imgcodecs.hpp"
#include "Lighten_Darken.h"

using namespace cv;


Mat changeBrightness(Mat orignal, double value) {

	Mat modified;
	double bright = value - 50;
	bright = bright * 3;
	orignal.convertTo(modified, -1, 1, bright);
	return modified;
}