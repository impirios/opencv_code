#include"opencv4/opencv2/highgui.hpp"
#include<iostream>

using namespace std;
using namespace cv;


int main(int argc, char const *argv[])
{

    Mat M(2,2, CV_8SC3, Scalar(100,127,256));
    cout << "M = " << endl << " " << M << endl << endl;
    return 0;
}

