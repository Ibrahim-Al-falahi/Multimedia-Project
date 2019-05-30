#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>
#include "Lighten_Darken.h"
#include "Resize.h"
#include "Erosion_Dilation.h"
#include "Canny.h"
#include "Panorama.h"
#include<opencv2/opencv.hpp>


using namespace cv;
using namespace std;

int iSliderValue1, iSliderValue2, iSliderValue3, iSliderValue4, iSliderValue5, iSliderValue6, iSliderValue7;
Mat src, l;
int i;
String img , path;
int main()
{
	cout << "Project demo" << endl;
	cout << "The function of this project demo divided into two parts" << endl;
	cout << "the First Part contains: \n 0: Lighten & Darken \n 1: Erosion & Dilation \n 2: Resize \n 3: Canny Edge Detection" << endl;
	cout << "The Second Part contains only Panorama/Stitching" << endl;
	cout << "To choose First Part type (1) / to choose Second Part type(2) " << endl;
	cout << "Please enter an integer value: " << endl;
	cin >> i;
	
	if (i==1)
	{
		cout << "Please enter an Image Name with its Extension i.e(lena.jpg) : " << endl;
		cin >> img;
		src = imread(img);
		Mat track(1, 300, CV_8U, Scalar::all(255));


		//namedWindow("Contrast", 1);
		namedWindow("Brightness", WINDOW_NORMAL);
		namedWindow("Rezise", 1);
		namedWindow("Control", WINDOW_NORMAL);
		namedWindow("Erosion", WINDOW_NORMAL);
		namedWindow("Dilation", WINDOW_NORMAL);
		namedWindow("Edge Detection", WINDOW_NORMAL);

		// Initialize values

		//iSliderValue2 = 50.0;
		iSliderValue1 = 50;
		iSliderValue2 = 50;
		iSliderValue3 = 50;
		iSliderValue4 = 0;
		iSliderValue5 = 0;
		iSliderValue6 = 0;
		iSliderValue7 = 0;




		//createTrackbar("ContrastBar", "Contrast", &iSliderValue2, 100);
		createTrackbar("Brightness Bar: ", "Control", &iSliderValue1, 100);
		createTrackbar("Width Bar: ", "Control", &iSliderValue2, 100);
		createTrackbar("Hight Bar: ", "Control", &iSliderValue3, 100);
		createTrackbar("Element:\n 0: Rect \n 1: Cross \n 2: Ellipse", "Control", &iSliderValue4, 2);
		createTrackbar("Erosion Bar: ", "Control", &iSliderValue5, 21);
		createTrackbar("Dilation Bar: ", "Control", &iSliderValue6, 21);
		createTrackbar("Canny Bar: ", "Control", &iSliderValue7, 100);




		while (true)
		{
			//double Contrast = iSliderValue2 / 50.0;
			/*double bright = iSliderValue1-50 ;
			bright = bright * 3;*/
			/*double hight = iSliderValue2 + 200;
			double width = iSliderValue3 + 200;*/
			//src.convertTo(l, -1, Contrast, 0);
			//src.convertTo(brightness, -1, 1, bright);
			Mat Bright = changeBrightness(src, l, iSliderValue1);
			Mat Resize = Resizing(src, l, iSliderValue2, iSliderValue3);
			Mat Erosion = changeErosion(src, l, iSliderValue4, iSliderValue5);
			Mat Dilation = changeDilation(src, l, iSliderValue4, iSliderValue6);
			Mat Canny = EdgeDetection(src, l, iSliderValue7);

			//imshow("Contrast", l);
			imshow("Brightness", Bright);
			imshow("Rezise", Resize);
			imshow("Erosion", Erosion);
			imshow("Dilation", Dilation);
			imshow("Edge Detection", Canny);
			imshow("Control", track);

			waitKey(33);

		}
	}
	else if(i==2){

		cout << "Please enter an Images path : " << endl;
		cin >> path;
		Mat Panorama = Stitching(path);
		namedWindow("Panorama", WINDOW_NORMAL);
		while (true)
		{
			imshow("Panorama", Panorama);
			waitKey(33);
		}
	}
	
}