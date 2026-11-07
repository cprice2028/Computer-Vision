#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace cv;
using namespace std;
void mykmeans(Mat& img, int k, int maxSteps, string filename);
int main(int argc,char*argv[]){
    string files[] = {"bluefin_trevally.png","chameleon.png","cheetah.png","chess.png","crab_spider.png","peppers.png","peru.png","seahorse.png"};

    int steps[] = {10, 14, 14, 14, 14, 14, 14, 14, 14};
    string prefix = "k6";

    for (int i = 0; i < 8; i++) {
        Mat img = imread(files[i]);

        mykmeans(img, 6, steps[i], files[i]);
        imwrite(prefix + files[i], img);
    }
}
void mykmeans(Mat& img, int k, int maxSteps, string filename) {
    Mat original = img.clone();
    int rows = img.rows;
    int cols=img.cols;
    vector<Vec3d> clusters(k);
    vector<int> pixtocluster(rows*cols);

    for (int i = 0; i < k; i++) {
        double val = 255.0 * i / (k - 1);
        clusters[i] = Vec3d(val, val, val);
    }

    for (int kstep = 0; kstep < maxSteps; kstep++) {
        vector<Vec3d> sums(k, Vec3d(0, 0, 0));
        vector<int> counts(k, 0);

        for (int r = 0; r < img.rows; r++) {
            for (int c = 0; c < img.cols; c++) {
                Vec3b cur = original.at<Vec3b>(r, c);

                double maxdistance = 999999999;
                int best = 0;

                for (int i = 0; i < k; i++) {
                    double changeb = cur[0] - clusters[i][0];
                    double changeg = cur[1] - clusters[i][1];
                    double changer = cur[2] - clusters[i][2];

                    double dist = changeb * changeb + changeg * changeg + changer * changer;

                    if (dist < maxdistance) {
                        maxdistance = dist;
                        best = i;
                    }
                }

                int index = r * img.cols + c;
                pixtocluster[index] = best;

                sums[best] += Vec3d(cur[0], cur[1], cur[2]);
                counts[best]++;
            }
        }
        for (int j = 0; j < k; j++) {
            if (counts[j] > 0) {
                clusters[j] = sums[j] / counts[j];
            }
        }
    }

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            int index = r * cols + c;
            int j = pixtocluster[index];

            img.at<Vec3b>(r, c) = Vec3b(
                (uchar)(clusters[j][0]),
                (uchar)(clusters[j][1]),
                (uchar)(clusters[j][2])
            );
        }
    }
    cout << filename << endl;
    cout << maxSteps << " steps" << endl;

    for (int i = 0; i < k; i++) {
        cout << "["
            << (int)(clusters[i][0]) << ", "
            << (int)(clusters[i][1]) << ", "
            << (int)(clusters[i][2]) << "]"
            << endl;
    }
    cout << endl;
}