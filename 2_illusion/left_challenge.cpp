//
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
//
using namespace std ;
//
typedef unsigned char uchar ;
//
const int W = 640 ;
const int H = 480;
//
void save( uchar img[][W] )
{
    for (int x=0;x<640;x++){

        for( int r = 0 ; r < H ; r++ )
        {
            for( int c = 0 ; c < W ; c++ )
            {
                if (c-x>=0 && c-x<64)
                {
                    if (r>=180 && r<212)
                    {
                        img[r][c]=(uchar)2;
                        if (x>0){
                            img[r][x-1]=(uchar)img[0][x-1];
                        }
                        if(x>576){
                            img[r][x-576]=(uchar)2;
                        }
                    }
                    else if (r>=300 && r<332)
                    {
                        img[r][c]=(uchar)3;
                        if (x>0){
                            img[r][x-1]=(uchar)img[0][x-1];
                        }
                        if(x>576){
                            img[r][x-576]=(uchar)3;
                        }
                    }
                    
                }
            }
        }
        if(x%5==0){
            ofstream fout          ;
                //
            ostringstream oss;
            oss << setfill('0') << setw(3) << x/5;
            string result = oss.str();
            string filename = "frame" + result;
            //
            
            fout . open( filename+".ppm" ) ;
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
                    else if( img[r][c] == 2 )  // blue
                    {
                    fout << (uchar)0  << (uchar)0 << (uchar)255  << flush ;
                    }
                    else if( img[r][c] == 3 )  // yellow
                    {
                    fout << (uchar)255  << (uchar)255 << (uchar)0  << flush ;
                    }
                    else if(img[r][c]==4)    // white
                    {
                    fout << (uchar)255 << (uchar)255 << (uchar)255 << flush ;
                    }
                    else if(img[r][c]==5)                     // faded blue
                    {
                    fout << (uchar)0 << (uchar)0 << (uchar)204 << flush ;
                    }
                    else                   // faded yellow
                    {
                    fout << (uchar)204 << (uchar)204 << (uchar)0 << flush ;
                    }
                }
            }
            //
            fout . close() ;
        }
    }
}

//
int main( int argc , char* argv[] )
{
    uchar img[H][W] ;
    /*
        LEFT
        color 640-by-480 image as a PPM

        vertical stripes 32 pixels wide
        alternate black-white-black-...
        left-most is black + offset by half
        (thus, right-most stripe is __ also) done

        one blue rectangle + one yellow
        size 64-by-32 and upper-left at
        blue x=0y=180
        yellow x=0 y=300
        move together as x++ and wrap
        write every 5th frame 128 total f
        loop forever animation with ghost

    */
    //
    for( int c = 0 ; c < W ; c++ )
    {
        for( int r = 0 ; r < H ; r++ )
        {
            if ((c+16)/32%2==0)
                img[r][c]=(uchar) 1;
            else
                img[r][c]=(uchar)4;
            if (c>=0 && c<64)
            {
                if (r>=180 && r<212)
                {
                        img[r][c]=(uchar)2;
                }
                else if (r>=300 && r<332)
                {
                        img[r][c]=(uchar)3;
                }
            }
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