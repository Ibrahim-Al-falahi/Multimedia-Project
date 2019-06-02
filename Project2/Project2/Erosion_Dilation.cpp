#include <iostream>
#include "opencv2/imgcodecs.hpp"
#include "opencv2/imgproc.hpp"
#include "Erosion_Dilation.h"

using namespace cv;

Mat changeErosion(Mat orignal, int type, double value) {

	Mat modified;
	int erosion_type = 0;
	if (type == 0) { erosion_type = MORPH_RECT; }
	else if (type == 1) { erosion_type = MORPH_CROSS; }
	else if (type == 2) { erosion_type = MORPH_ELLIPSE; }
	Mat element = getStructuringElement(erosion_type,
		Size(2 * value + 1, 2 * value + 1),
		Point(value, value));
	erode(orignal, modified, element);

	return modified;
}

Mat changeDilation(Mat orignal, int type, double value) {
	
	Mat modified;
	int dilation_type = 0;
	if (type == 0) { dilation_type = MORPH_RECT; }
	else if (type == 1) { dilation_type = MORPH_CROSS; }
	else if (type == 2) { dilation_type = MORPH_ELLIPSE; }
	Mat element = getStructuringElement(dilation_type,
		Size(2 * value + 1, 2 * value + 1),
		Point(value, value));
	dilate(orignal, modified, element);

	return modified;
}