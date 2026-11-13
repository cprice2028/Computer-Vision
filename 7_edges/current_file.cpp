#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace cv;
using namespace std;
int main(int argc,char*argv[]){
    string files[] = {"bluefin_trevally.png","chameleon.png","cheetah.png","chess.png","crab_spider.png","peppers.png","peru.png","seahorse.png","elvis.png"};
    int highthresh= atoi(argv[1]);
    int lowthresh = atoi(argv[2]);

    for (string filename : files) {

        Mat img = imread(filename);
        Mat gray;
        if (img.channels() == 3) {
            cvtColor(img, gray, COLOR_BGR2GRAY);
        }
        else {
            gray = img.clone();
        }

        Mat blurred=gray.clone();
        for (int i =0;i<3;i++){
            Mat temp = blurred.clone();
            for (int r = 1;r<gray.rows-1;r++){
                for (int c= 1;c<gray.cols-1;c++){
                int n1 = temp.at<uchar>(r - 1, c - 1);
                int n2 = temp.at<uchar>(r - 1, c);
                int n3 = temp.at<uchar>(r - 1, c + 1);

                int n4 = temp.at<uchar>(r, c - 1);
                int me = temp.at<uchar>(r, c);
                int n5 = temp.at<uchar>(r, c + 1);

                int n6 = temp.at<uchar>(r + 1, c - 1);
                int n7 = temp.at<uchar>(r + 1, c);
                int n8 = temp.at<uchar>(r + 1, c + 1);
                blurred.at<uchar>(r,c)=(n1+n2*2+n3+n4*2+me*4+n5*2+n6+n7*2+n8)/16;
                }
            }
        }

        Mat high = img.clone();
        Mat low = img.clone();

        for (int r = 1; r < blurred.rows - 1; r++) {
            for (int c = 1; c < blurred.cols - 1; c++) {

                int n1 = blurred.at<uchar>(r - 1, c - 1);
                int n2 = blurred.at<uchar>(r - 1, c);
                int n3 = blurred.at<uchar>(r - 1, c + 1);

                int n4 = blurred.at<uchar>(r, c - 1);
                int me = blurred.at<uchar>(r, c);
                int n5 = blurred.at<uchar>(r, c + 1);

                int n6 = blurred.at<uchar>(r + 1, c - 1);
                int n7 = blurred.at<uchar>(r + 1, c);
                int n8 = blurred.at<uchar>(r + 1, c + 1);

                int Gc = (n3 + 2 * n5 + n8)- (n1 + 2 * n4 + n6);

                int Gr = (n6 + 2 * n7 + n8)- (n1 + 2 * n2 + n3);

                int G = abs(Gc) + abs(Gr);


                if (G > lowthresh) {
                    low.at<Vec3b>(r, c) = Vec3b(0, 0, 255);
                }

                if (G > highthresh) {
                    high.at<Vec3b>(r, c) = Vec3b(0, 0, 255);
                }

            }
        }
        string name = filename.substr(0, filename.find("."));

        imwrite(name + "_gray.png", gray);
        imwrite(name + "_blur.png", blurred);
        imwrite(name + "_high.png", high);
        imwrite(name + "_low.png", low);

        cout << "Finished processing " << filename << endl;
    }

    return 0;
}

