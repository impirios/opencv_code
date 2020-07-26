#include"opencv4/opencv2/highgui.hpp"
#include<iostream>

using namespace std;
using namespace cv;

int main()
{
    Mat imag;
    imag = imread("sample.png",0);
    namedWindow( "Display window", cv::WINDOW_NORMAL);
    Mat B(imag);
    
    imshow("Display window",B);
    waitKey(0);

}