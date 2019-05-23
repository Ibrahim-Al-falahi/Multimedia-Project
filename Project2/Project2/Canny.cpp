#include <iostream>
#include "opencv2/imgcodecs.hpp"
#include "opencv2/imgproc.hpp"
#include "Canny.h"

using namespace cv;

Mat EdgeDetection(Mat orignal, Mat modified, double value)
{
	Mat src_gray, detected_edges;

	/// Create a matrix of the same type and size as src (for dst)
	modified.create(orignal.size(), orignal.type());

	/// Convert the image to grayscale
	cvtColor(orignal, src_gray, COLOR_BGR2GRAY);

	/// Reduce noise with a kernel 3x3
	blur(src_gray, detected_edges, Size(3, 3));

	/// Canny detector
	Canny(detected_edges, detected_edges, value, value*3, 3);

	/// Using Canny's output as a mask, we display our result
	modified = Scalar::all(0);

	orignal.copyTo(modified, detected_edges);
	return modified;
}