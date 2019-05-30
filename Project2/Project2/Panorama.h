#pragma once
#ifndef Panorama_H    // To make sure you don't declare the function more than once by including the header multiple times.
#define Panorama_H

#include "opencv2/imgcodecs.hpp"

using namespace cv;


Mat Stitching(String path);

#endif
