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
   string array[] = { "ants" , "bear" , "bird" , "claw" , "eyes" , "hawk" , "lion" , "wolf" } ;

   //string array[] = {"elvis"};
   for (String filename:array){
      Mat img = imread(filename+".png");
      cvtColor(img, img, COLOR_BGR2GRAY);
      ofstream fileout("right" + filename + ".txt");
      for (int t=1;t<256;t++){
         Mat t_img;
         threshold(img, t_img, t, 255, THRESH_BINARY);
         int black=0;
         int white=0;
         int rows = t_img.rows;
         int cols = t_img.cols;
         for (int r=0;r<rows;r++){
            for(int c=0;c<cols;c++){
               uchar val = t_img.at<uchar>(r, c);
               if (val == uchar(0)) {
                  black++;
               } else {
                  white++;
               }
            }
         }
         double ratio = (double)black / (black + white);
         fileout << ratio << "\n";
      }
      fileout.close();
   }

   //
   return 0 ;
}
//
// end
//