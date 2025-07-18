#include <iostream>
#include "calc.h"
#include <opencv2/opencv.hpp>

using namespace std;

cv::Mat generateImage (int index) {
    cv::Scalar white(255,255,255);
    cv::Scalar black(0,0,0);
    const int rows = 100, cols=100;
    cv::Mat res(rows, cols, CV_8UC3,black);
    cv::rectangle(res, {10+index, 10}, {50+index, 50}, white, -1);
    return res;
}

void fillPixelEquation (const std::vector<cv::Mat>& images, Matrix <Matrix <double> >& equations, int y, int x) {
    const int frames=9;
    for (int i = 0; i < frames; ++i) {

    }
}
Matrix <std::vector <double> > solveImages (const std::vector<cv::Mat>& images) {
    using std::vector;
    const int frames = 9;
    assert (images.size() == frames);
    Matrix <Matrix <double> > equations (images[0].rows,
            vector <Matrix<double> > (images[0].cols,
            Matrix<double> (frames,
            vector<double> (frames+1,0))));
    for (int i = 0; i < images[0].rows; ++i) {
        for (int j = 0; j < images[0].cols; ++j) {
            fillPixelEquation (images, equations, i, j);
        }
    }
}

int main(int argc, char *argv[])
{
    /*
    int n;
    std::cin >> n;
    Matrix<double> mat(n,n+1);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n+1; ++j) {
            std::cin >> mat.at(i,j);
        }
    }



    std::vector<double> res = Calc::solveLinear(mat);
    for (int i = 0; i < res.size(); ++i) {
        std::cout << res[i] << " ";
    }
    */
    cv::namedWindow("Input", CV_WINDOW_NORMAL);
    const int frames = 9;
    std::vector<cv::Mat> images(frames);
    for (int i = 0; i < images.size(); ++i) {
        images[i] = generateImage(i);
        cv::imshow("Input", images[i]);
        cv::imwrite(std::to_string(i)+".bmp", images[i]);
        cv::waitKey(0);
    }
    Matrix <std::vector <double> > coef = solveImages (images);
    return 0;
}
