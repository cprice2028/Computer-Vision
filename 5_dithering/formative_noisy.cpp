//
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/dnn/dnn.hpp>
//
#include <iostream>
// string array[] = { "ants" , "bear" , "bird" , "claw" , "eyes" , "hawk" , "lion" , "wolf" } ;
using namespace std ;
using namespace cv ;
//
int main( int argc , char* argv[] )
{
   //     height width   uchar
   string array[] = { "ants" , "bear" , "bird" , "claw" , "eyes" , "hawk" , "lion" , "wolf" } ;
   for (String filename:array){
    Mat img = imread(filename+".png");
    cout<<filename<<endl;
    cvtColor(img, img, COLOR_BGR2GRAY);

    int rows = img.rows;
    int cols = img.cols;
    RNG rng(1933641);

    uchar rand_tile[64][64];
    for (int r = 0; r < 64; r++) {
        for (int c = 0; c < 64; c++) {
            rand_tile[r][c] = (uchar)rng.uniform(0, 256); 
        }
    }
    int black = 0;
    int white = 0;

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            uchar &val = img.at<uchar>(r, c);
            int rand = rand_tile[r % 64][c % 64];
            if (val < rand) {
                val = 0;
                black++;
            } else {
                val = 255;
                white++;
            }
        }
    }
    double total = black + white;
    double black_ratio = black * 1.0 / total;
    double white_ratio = white * 1.0 / total;

    cout << "black " << black_ratio  << endl;
    cout << "white " << white_ratio  << endl;

    imwrite(filename + "_sid_threshold.png", img);
   }
    return 0;
}
//
// end
//