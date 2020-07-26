
#include "opencv4/opencv2/highgui.hpp"

#include <iostream>

using namespace cv;

int main(int argc, char* argv[])
{
    cv::VideoCapture cap(0);
    if (!cap.isOpened())
    {
        std::cout << "!!! Failed to open file: " << std::endl;
        return -1;
    }

    cv::Mat frame;
    for(;;)
    {

        if (!cap.read(frame))             
            break;

        cv::imshow("window", frame);

        char key = waitKey(10);
        if (key == 27) // ESC
            break;
    }

    return 0;
}
