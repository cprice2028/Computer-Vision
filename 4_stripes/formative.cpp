//
#include <fstream>
//
#include <iostream>
//
using namespace std;

typedef unsigned char uchar ;
//
const int W = 440 ;
const int H = 400;
//
void save( uchar img[][W] )
{
    ofstream fout;
    //
    fout . open( "formative.ppm" ) ;
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
            else if( img[r][c] == 2 )  // dark gray
            {
               fout << (uchar)85  << (uchar)85 << (uchar)85  << flush ;
            }
            else if (img[r][c]==3){//light gray

               fout<<(uchar)170<<(uchar)170<<(uchar)170<<flush;
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
      /*Circle( int xc=0 , int yc=0 )
      {
         x = xc ;
         y = yc ;
         //
         r = 40 ;
      }*/
      Circle( int xc=0 , int yc=0 ,int rc=0)
      {
         x = xc ;
         y = yc ;
         //
         r = rc ;
      }
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
      • grayscale 440-by-400, say again: four hundred forty -by- four hundred
      • two circle objects both centered at (200,200) radius 40 and radius 120
      • background: right 200 pixels 170 light gray, left 200 black, middle 40 white
      • dark gray 85 any pixel inside the bigger circle but not in the smaller circle
      • but if the x-coordinate is >= 200 then shift those dark grays 40 to the right
      • result is the middle 40 white pixels will form a gap between the two sides
   */
    uchar img[H][W] ;
    //make background
    for (int r = 0;r<H;r++)
        {
            for (int c = 0; c<W;c++)
            {
               if (c>=W-200)
                  img[r][c]=(uchar)3;
               else if (c>=200&&c<240)
                  img[r][c]=(uchar)4;
               else 
                  img[r][c]=(uchar)1;
            }
        }
    //make circles
    for (int r = 0;r<H;r++)
        {
         for (int c=0;c<W;c++){
            Circle littleCircle=Circle(200,200,40);
            Circle bigCircle=Circle(200,200,120);
            if (bigCircle.contains(r,c)){
               if (!littleCircle.contains(c,r)){
                  if(c>=200)
                     img[r][c+40]=(uchar)2;
                  else
                     img[r][c]=(uchar)2;
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
