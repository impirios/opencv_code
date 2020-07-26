//Opencv C++ Example of Operation on Arrays:absdiff  
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
 
using namespace cv;
using namespace std;
 
int main()
{
 
    Mat image1,image2,dst;
    image1 = imread("images/cat.jpg",0);
    if( !image1.data ) { printf("Error loading image1 \n"); return -1;}
    image2 = imread("images/coffee2.jpg",0);
    if( !image2.data ) { printf("Error loading image2 \n"); return -1;}
           
    absdiff( image1,  image2,  dst);
  
    namedWindow( "Display window", CV_WINDOW_AUTOSIZE );  
    imshow( "Display window", image2 );                 

    namedWindow( "Display windo", CV_WINDOW_AUTOSIZE );  
    imshow( "Display windo", image1 );         

    namedWindow( "Result window", CV_WINDOW_AUTOSIZE );   
    imshow( "Result window", dst );
    
    //imwrite("C:\\Users\\arjun\\Desktop\\opencv-dst.jpg",dst);
    waitKey(0);                                         
    return 0;
}
