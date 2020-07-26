#include"opencv2/highgui.hpp"
#include"opencv2/imgproc.hpp"
#include<iostream>

using namespace std;
using namespace cv;

int ThreshholdValue;
Mat gray;
Mat image;
Mat BinaryThreshold;
Mat Gauss;
int point=1;
int sigma=1;



int main(int argc, const char** argv) {

    VideoCapture cap(0);

    namedWindow("Feed");
    
    namedWindow("Gaussian Blur");
    createTrackbar("Threshhold","Feed",&ThreshholdValue,255);
    createTrackbar("Point","Gaussian Blur",&point,3*sigma);
    createTrackbar("sigma","Gaussian Blur",&sigma,10);

    while(true)
    {   
        cap>>image;
        cvtColor(image,gray,CV_BGR2GRAY);
        threshold(gray,BinaryThreshold,ThreshholdValue,255,THRESH_TOZERO);
        GaussianBlur(image,Gauss,Size(point,point),sigma);


        imshow("Gaussian Blur",Gauss);
        if(BinaryThreshold.empty())
        {
            imshow("Feed",gray);
        }
        else
        {
            imshow("Feed",BinaryThreshold);
        }
        

        int c;
        c = waitKey( 20 );
        if( (char)c == 27 )
        { 
            break;
        }
    }

    return 0;
}