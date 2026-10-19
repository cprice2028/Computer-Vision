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
      String vals="";
      int rows = img.rows;
      int cols = img.cols;
      int valsarray[256]={0};
      for (int r=0;r<rows;r++){
         for(int c=0;c<cols;c++){
            uchar val = img.at<uchar>(r, c);
            valsarray[int(val)]+=1;
         }
      }
      ofstream fileout("left" + filename + ".txt");
      for (int i = 0; i < 256; i++) {
         fileout << valsarray[i] << "\n";
      }
      fileout.close();
   }

   //
   return 0 ;
}
//
// end
//