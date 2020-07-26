#include"opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include<vector>
//#pragma once
#include<iostream>

using namespace cv;
using namespace std;
int main()
{
    cv::VideoCapture cap(0);//"images/vtest.avi");
    cv::Mat Frame1,Frame2,Gray1,Gray2,thresh,Gauss,GaussTest;

    

    if(!cap.isOpened())
    {
        std::cout << "Cannot access the camera of this device" << std::endl;
        return -1;
    }


    cap>>Frame1;
    cap>>Frame2;


    
    Mat Diff;
    for(;;)
    {    
        vector<vector<Point>> contours;

        cvtColor(Frame1,Gray1,CV_BGR2GRAY);
        cvtColor(Frame2,Gray2,CV_BGR2GRAY);

        absdiff(Gray1,Gray2,Diff);

        //smoothing frame or reducing noise
        GaussianBlur(Diff,Gauss,Size(7,7),1);
        GaussianBlur(Frame1,GaussTest,Size(5,5),1);
        threshold(Gauss,thresh,80,255,CV_THRESH_BINARY);
        findContours(thresh,contours,CV_RETR_TREE,CV_CHAIN_APPROX_SIMPLE,Point(0,0));
        cout<<contours.size()<<endl;
        if(contours.size()>0)
        {
            vector<Rect> BoundingRectangles(contours.size());
            vector<vector<Point>> c_poly(contours.size());

        for (int i = 0;i<contours.size();i++)
        {
            RotatedRect minRect = minAreaRect( Mat(contours[i]) );
            Point2f rect_points[4];
            minRect.points( rect_points ); 
            for( int j = 0; j < 4; j++ )
                line( Frame1, rect_points[j], rect_points[(j+1)%4],Scalar(50,250,50),2);
        }

        }
        

        imshow("Difference", Diff);
        //imshow("Frame",Frame1);

        imshow("Gaussian Blur",Gauss);
        //imshow("Test",GaussTest);
        imshow("Threshholding",thresh);
        imshow("feed",Frame1);


        Frame1 = Frame2.clone();
        cap>>Frame2;

        if (Frame2.empty())
        {
            break;
        }
        

        
        if (waitKey(10) == 27) // ESC
            break;
    }    

}
