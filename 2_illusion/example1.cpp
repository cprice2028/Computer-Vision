//
#include <fstream>
//
using namespace std ;
//
typedef unsigned char uchar ;
//
const int W = 1200 ;
const int H = 560;
//
void save( uchar img[][W] )
{
    ofstream fout ;
    //
    fout . open( "example1.ppm" ) ;
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
            else if( img[r][c] == 2 )  // Gray
            {
               fout << (uchar)127  << (uchar)127 << (uchar)127  << flush ;
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
int main( int argc , char* argv[] )
{
    uchar img[H][W] ;
    /*
        grayscale 1200-by-560 image has 8 rows + height of each row is 70 pixels • 
        across each row are 12.5 bricks white-black-white-black-...-black-white •
        top row has a half-brick 48 pixels wide at left then 12 bricks each 96 pixels • 
        second row has the 12 full-bricks first and ends with half-brick at right, etc • 
        at both the top and bottom of each brick are 2-pixel tall gray-127 lines • 
        so the very top- and bottom-most are just 2 but all the others are 4 total 
    */
    //
    for( int c = 0 ; c < W ; c++ )
    {
        for( int r = 0 ; r < H ; r++ )
        {
            if (r/70%2==0){
                if((r%70)<=1 || (r%70)>=68)
                    img[r][c]=(uchar)2;
                else
                    if ((c+48)/96%2==1)
                        img[r][c]=(uchar)1;
                    else
                        img[r][c]=(uchar)3;
            }
            else{
                if((r%70)<=1 || (r%70)>=68)
                    img[r][c]=(uchar)2;
                else
                    if (c/96%2==1)
                        img[r][c]=(uchar)1;
                    else
                        img[r][c]=(uchar)3;
            }
            
            
                      
            
            
            /*if(H/2/10== r/10 || H/2/10== r/10+1)
                img[r][c] =(uchar)1;
            else
                img[r][c] = (uchar)3; 
            if ((c/10%10%2==0 && r/10%10%2!=0) || (c/10%10%2!=0 && r/10%10%2==0))
                if ( W/2/10== c/10 || W/2/10== c/10+1)
                    img[r][c]=(uchar)1;
                else
                    img[r][c] = (uchar)2;*/
        }
    }
    //
    save( img ) ;
    //
    return 0 ;
}
//
// end
//