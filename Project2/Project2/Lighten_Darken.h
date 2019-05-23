#pragma once
#ifndef LIGHTEN_DARKEN_H    // To make sure you don't declare the function more than once by including the header multiple times.
#define LIGHTEN_DARKEN_H

#include "opencv2/imgcodecs.hpp"

using namespace cv;


Mat changeBrightness(Mat orignal, Mat modified, double value);

#endif