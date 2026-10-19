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
      int rows = img.rows;
      int cols = img.cols;
      cvtColor( img , img , COLOR_BGR2GRAY ) ;
      
      Mat thresholded_img;
      threshold(img, thresholded_img, 128, 255, THRESH_BINARY);
      imwrite(filename + "128_black_white.png", thresholded_img);

      int black=0;
      int white=0;

      for (int r=0;r<rows;r++){
         for(int c=0;c<cols;c++){
            uchar val = img . at< uchar > ( r , c ) ;
            if (val<(uchar)128)
               black++;
            else
             white++;

         }
      }
      cout<<"black "<<(double)black/(rows*cols)<<endl;
      cout<<"white "<<(double)white/(rows*cols)<<endl;
   }

   //
   return 0 ;
}
//
// end
//