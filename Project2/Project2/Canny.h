#pragma once
#ifndef Canny_H    // To make sure you don't declare the function more than once by including the header multiple times.
#define Canny_H

#include "opencv2/imgcodecs.hpp"

using namespace cv;


Mat EdgeDetection(Mat orignal, double threshold1, double threshold2);

#endif