#include <iostream>
#include <opencv2/opencv.hpp>
#include <fstream>
#include <sstream>
#include <iomanip>

int main(int argc, const char * argv[])
{
    const std::string& video_src = argv[1];

    int f_id = 0;

    cv::VideoCapture cap(video_src);
    if (!cap.isOpened())
    {
        return -1;
    }

    cv::Mat img;
    cv::Mat small;
    while(cap.read(img))
    {
        cv::resize(img, small, cv::Size(), 0.25, 0.25);

        cv::imshow("Image", small);

        int key = cv::waitKey(30);
        if (key == ' ')
        {
            std::stringstream ss;
            ss << std::setw(5) << std::setfill('0') << f_id;
            cv::imwrite(ss.str() + ".jpg" ,img);
            ++f_id;
        }
        else if (key == 27)
        {
            break;
        }
    }

    std::stringstream ss;
    return 0;
}