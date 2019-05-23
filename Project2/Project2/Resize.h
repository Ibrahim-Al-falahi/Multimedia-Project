#pragma once
#ifndef Resize_H    // To make sure you don't declare the function more than once by including the header multiple times.
#define Resize_H

#include "opencv2/imgcodecs.hpp"

using namespace cv;


Mat Resizing(Mat orignal, Mat modified, double hight, double width);

#endif
