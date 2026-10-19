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
   string array[] = { "aloha" } ;
   //string array[] = {"elvis"};
   Mat img = imread("aloha.png");
   int rows = img.rows;
   int cols = img.cols;
   int minp=1569325055;
   int maxp=-1569325055;
   int pixels[rows][cols];
   for (int r=0;r<rows;r++){
      for(int c=0;c<cols;c++){
         Vec3b pixel=img.at<Vec3b>(r, c);
         int pix = (pixel(0)+pixel(1)+pixel(2))/3-((pixel(0)*.11+pixel(1)*.59+pixel(2)*.30)/3);
         //cout<<pix<<endl;
         if (pix<=minp){
            minp=pix;
            cout<<pix<<endl;
         }
         if (pix>=maxp){
            maxp=pix;
            cout<<pix<<endl;
         }
         pixels[r][c]=pix;
      }
   }
   /*convert to grayscale two ways - straight average <and> weighted average 30 red + 59 green + 11 blue

   find the delta at each pixel - find the min delta and the max delta over all pixels

   scale the min-max delta to 0-255 and make an image showing the (scaled) delta*/

   Mat img2(rows,cols,CV_8UC1);

   for (int r=0;r<rows;r++){
      for(int c=0;c<cols;c++){
         img2.at<uchar>(r,c)=(uchar)(pixels[r][c]-minp)*255.0/(maxp-minp);
      }
   }

   imwrite("aloha2.png",img2);
   return 0 ;
   }

//
// end
//