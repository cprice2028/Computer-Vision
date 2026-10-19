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
   //string array[] = {"elvis"};
   for (String filename:array){
      Mat img = imread(filename+".png");
      cout<<filename<<endl;
      int rows = img.rows;
      int cols = img.cols;
      cvtColor( img , img , COLOR_BGR2GRAY ) ;
      int black=0;
      int white=0;
      int gray=0;
      for (int r=0;r<rows;r++){
         for(int c=0;c<cols;c++){
            uchar &val = img.at<uchar>(r, c);
            if (val<(uchar)68){
               val=(uchar)0;
               black++;
            }
            else if (val<(uchar)192){
               val=(uchar)127;
               gray++;
            }
            else {
               white++;
               val=(uchar)255;
            }

         }
      }
      double total = rows*cols;
      cout<<"black "<<(double)black/(total)<<endl;
      cout<<"gray "<<(double)gray/(total)<<endl;
      cout<<"white "<<(double)white/(total)<<endl;
      imwrite(filename + "sum_3cond.png", img);
   }

   //
   return 0 ;
}
//
// end
//