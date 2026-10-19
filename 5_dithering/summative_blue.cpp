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
   //string array[] = { "ants" , "bear" , "bird" , "claw" , "eyes" , "hawk" , "lion" , "wolf" } ;
   ifstream file("blue_noise.txt");
   uchar blue_noise[64][64];
   for (int c=0;c<64;c++){
      for (int r=0;r<64;r++){
         int val;
         file>>val;
         blue_noise[r][c]=(uchar)val;
      }
   }
   string array[] = {"elvis"};
   for (String filename:array){
      Mat img = imread(filename+".png");
      cout<<filename<<endl;
      int rows = img.rows;
      int cols = img.cols;
      cvtColor( img , img , COLOR_BGR2GRAY ) ;
      int black=0;
      int white=0;
      for (int r=0;r<rows;r++){
         for(int c=0;c<cols;c++){
            uchar &val = img.at<uchar>(r, c);
            uchar num = blue_noise[r%64][c%64];
            if (val<(uchar)num){
               val=(uchar)0;
               black++;
            }
            else {
               white++;
               val=(uchar)255;
            }

         }
      }
      double total = rows*cols;
      cout<<"black "<<(double)black/(total)<<endl;
      cout<<"white "<<(double)white/(total)<<endl;
      imwrite(filename + "_blue.png", img);
   }

   //
   return 0 ;
}
//
// end
//