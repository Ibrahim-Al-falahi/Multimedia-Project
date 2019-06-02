#include <iostream>
#include "opencv2/imgcodecs.hpp"
#include "Resize.h"
#include<opencv2/opencv.hpp>

using namespace cv;

Mat Resizing(Mat orignal, double hight, double width) {

	Mat modified;
	double hight_v = hight + 200;
	double width_v = width + 200;
	resize(orignal, modified, Size(hight_v, width_v), 1, 1, INTER_NEAREST);
	return modified;
}