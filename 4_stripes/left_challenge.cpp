//
#include <fstream>
//
#include <iostream>
//
using namespace std;

typedef unsigned char uchar ;
//
const int W = 640 ;
const int H = 480;
//
void save( uchar img[][W] )
{
    ofstream fout;
    //
    fout . open( "left_challenge.ppm" ) ;
    //
    fout << "P6" << endl ;
    //
    fout << W << " " << H << endl << "255" << endl ;
    //
    for( int r = 0 ; r < H ; r++ )
    {
        for( int c = 0 ; c < W ; c++ )
        {
            if( img[r][c] == 1 )       // Black
            {
               fout << (uchar)0 << (uchar)0   << (uchar)0  << flush ;
            }
            else if( img[r][c] == 2 )  // soft red
            {
               fout << (uchar)217  << (uchar)0 << (uchar)18  << flush ;
            }
            else if (img[r][c]==3){//soft green 35, 159, 64

               fout<<(uchar)35<<(uchar)159<<(uchar)64<<flush;
            }
            else if (img[r][c]==4){//soft blue
               fout<<(uchar)0<<(uchar)51<<(uchar)160<<flush;
            }
            else if (img[r][c]==5){//tan
               fout<<(uchar)200<<(uchar)176<<(uchar)165<<flush;
            }
            else                       // white
            {
               fout << (uchar)255 << (uchar)255 << (uchar)255 << flush ;
            }
        }
    }
    //
    fout . close() ;
}
//
//
//
class Circle
{
   private : 
      //
      int x ;
      int y ;
      int r ;
   //
   public :
      //
      Circle( int xc=0 , int yc=0 )
      {
         x = xc ;
         y = yc ;
         //
         r = 40 ;
      }
      /*Circle( int xc=0 , int yc=0 ,int rc=0)
      {
         x = xc ;
         y = yc ;
         //
         r = rc ;
      }*/
      //
      Circle( const Circle & c )
      {
         x = c . x ;
         y = c . y ;
         r = c . r ;
      }
      //
      bool contains( int xp , int yp ) const
      {
         int dx = xp - x ;
         int dy = yp - y ;
         //
         return dx*dx + dy*dy <= r*r ;
      }
   //
} ;
//
//
//
int main( int argc , char* argv[] )
{
      /*
      stripes show through circles
      some __ show through some __
      three groups of four circles each
      red group
      green group
      blue group
      */
    uchar img[H][W] ;
    //make background
    for (int r = 0;r<H;r++)
        {
            for (int c = 0; c<W;c++)
            {
               if ((r+3)/6%3==0){
                  img[r][c]=(uchar)2;
               }
               else if ((r+3)/6%3==1){
                  img[r][c]=(uchar)3;
               }
               else{
                  img[r][c]=(uchar)4;
               }
            }
        }
    //make circles
    ifstream fin;
    int x_cord;
    int y_cord;
    vector<int> x_cords;
    vector<int> y_cords;
    vector<Circle> circles;
    fin.open("xy.txt");
    while(fin>>x_cord){
      fin>>y_cord;
      x_cords.push_back(x_cord);
      y_cords.push_back(y_cord);
    }
    for (int i =0;i<x_cords.size();i++){
      circles.push_back(Circle(x_cords[i],y_cords[i]));
    }
    for (int r = 0;r<H;r++){
      for (int c=0;c<W;c++){
         for (int i =0;i<circles.size();i++){
            if (circles[i].contains(c,r)){
               if(i<4){
                  if (img[r][c]!=(uchar)2)
                     img[r][c]=(uchar)5;
                  else 
                     img[r][c]=(uchar)2;
               }
               else if(i<8){
                  if (img[r][c]!=(uchar)3)
                     img[r][c]=(uchar)5;
                  else 
                     img[r][c]=(uchar)3;
               }
               else {
                  if (img[r][c]!=(uchar)4)
                     img[r][c]=(uchar)5;
                  else 
                     img[r][c]=(uchar)4;
               }
            }
         }
      }
   }
    save(img);
    return 0 ;
}
//
// end
//
