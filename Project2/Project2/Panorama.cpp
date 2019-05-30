// CPP program to Stitch 
// input images (panorama) using OpenCV  
#include <iostream> 
#include <fstream> 

// Include header files from OpenCV directory 
// required to stitch images. 
#include "opencv2/imgcodecs.hpp" 
#include "opencv2/highgui.hpp" 
#include "opencv2/stitching.hpp" 
#include "Panorama.h"

using namespace std;
using namespace cv;

// Define mode for stitching as panoroma  
// (One out of many functions of Stitcher) 
Stitcher::Mode mode = Stitcher::PANORAMA;

// Array for pictures 
vector<Mat> imgs;

Mat Stitching(String path) {

	path = path+"/img";
	// Get all the images that need to be  
	// stitched as arguments from command line  
	for (int i = 1; i < 8; ++i)
	{
		// Read the ith argument or image  
		// and push into the image array 
		Mat img = imread(path + to_string(i) + ".jpg");
		if (img.empty())
		{
			// Exit if image is not present 
			cout << "Can't read image '" << path + to_string(i) << "'\n";
		}
		imgs.push_back(img);
	}

	// Define object to store the stitched image 
	Mat pano;

	// Create a Stitcher class object with mode panoroma 
	Ptr<Stitcher> stitcher = Stitcher::create(mode);

	// Command to stitch all the images present in the image array 
	Stitcher::Status status = stitcher->stitch(imgs, pano);

	if (status != Stitcher::OK)
	{
		// Check if images could not be stiched 
		// status is OK if images are stiched successfully 
		cout << "Can't stitch images\n";
	}

	return pano;
}