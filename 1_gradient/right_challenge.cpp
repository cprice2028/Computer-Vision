//
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>
//
using namespace std ;
//
typedef unsigned char uchar ;
//
//
void save( uchar img[][512] ) ;
//
//
int main( int argc , char* argv[] )
{
    //
    /*
    teapots instead of squares
    grayscale 512-by-512 (i.e., taller)
    row-pairs instead of column-pairs
    255 at top down to 0 at bottom
    read teapot from PGM binary file
    scaled down by half each dimension
    from 480-by-480 down to 240-by-240
    upper-left at (8,264) and (264,8)
    
    
    */
    uchar    img[512][512] ;
    //
    //
    for( int c = 0 ; c < 512 ; c++ )
    {
        for( int r = 0 ; r < 512 ; r++ )
            {
                img[r][c]=(uchar)126;
                   
                //upper left corner of 64x64 at 64,64
                //upper left corner of 64x64 at 384,64
                //color 127
        }
    }
    //
    save( img ) ;
    //
    return 0 ;
}
//
void save( uchar img[][512] )
{
        //
    ofstream fout          ;
    //
    //
    fout . open( "teacup.pgm" ) ;
    //
    fout << "P5" << endl ;
    //
    fout << "512 384" << endl << "255" << endl ;
    //
    for( int r = 0 ; r < 384 ; r++ )
    {
        for( int c = 0 ; c < 512 ; c++ )
        {
            fout << img[r][c] << flush ;
            //
            //               NOT endl !!!
        }
    }
    //
    fout . close() ;
    }

//
// end
//