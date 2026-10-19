//
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/dnn/dnn.hpp>
//
#include <iostream>
#include <fstream>
// string array[] = { "ants" , "bear" , "bird" , "claw" , "eyes" , "hawk" , "lion" , "wolf" } ;
using namespace std ;
using namespace cv ;
//
int main( int argc , char* argv[] )
{
   //     height width   uchar
   string array[] = { "panels" } ;

   //string array[] = {"elvis"};
   for (String filename:array){
      Mat img = imread(filename+".png");
      cvtColor(img, img, COLOR_BGR2GRAY);
      int rows = img.rows;
      int cols = img.cols;
      Mat img_3(rows/3,cols,CV_8UC3);
      for (int r=0;r<rows/3;r++){
         for(int c=0;c<cols;c++){
            uchar red = img.at<uchar>(r, c);
            uchar green = img.at<uchar>(r+rows/3-8,c-5);
            uchar blue = img.at<uchar>(r+2*rows/3-20,c-10);
            img_3.at<Vec3b>(r, c) = Vec3b(red, green, blue);
         }
      }
      imwrite("3panels.png",img_3);
   }

   //
   return 0 ;
}
//
// end
//