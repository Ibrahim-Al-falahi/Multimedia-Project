#pragma once
#ifndef Erosion_Dilation_H    // To make sure you don't declare the function more than once by including the header multiple times.
#define Erosion_Dilation_H

#include "opencv2/imgcodecs.hpp"

using namespace cv;


Mat changeErosion(Mat orignal, int type, double value);
Mat changeDilation(Mat orignal, int type, double value);

#endif
