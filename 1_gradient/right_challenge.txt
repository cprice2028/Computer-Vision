//
#include <fstream>
#include <string>
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
    
    
        P6
        480 480
        255
        �

    */
    ifstream file("teacup.pgm");
    string format;
    int width, height, maxVal;
    file >> format >> width >> height >> maxVal;
    file.ignore(1); // whitespace 

    uchar    img[512][512];
    uchar teapot[480][480];

    for (int r = 0;r<480;r++)
        {
            for (int c = 0; c<480;c++)
            {
                int red   = file.get();
                int green = file.get();
                int blue  = file.get();
                teapot[r][c] = (uchar)((red + green + blue) / 3);
            }
        }
    //
    //'''
    // teapot, where you draw black instead draw gray 127 and
    //  where you draw white instead draw nothing and the background gradient will show through'''
    for( int c = 0 ; c < 512 ; c++ )
    {
        for( int r = 0 ; r < 512 ; r++ )
            {
                if (c >7 && c<248  && r <504 && r>263)
                    {
                        uchar number = 255-r/2;
                        img[r][c]=(uchar)number;
                        if (teapot[(r-264)*2][(c-8)*2]==(uchar)0)
                            img[r][c]=(uchar)127;
                        //img[r][c]=(uchar)teapot[(r-264)*2][(c-8)*2];
                    }
                else if (r >7 && r<248  && c<504 && c>263)
                    {
                        uchar number = 255-r/2;
                        img[r][c]=(uchar)number;
                        if (teapot[(r-8)*2][(c-264)*2]==(uchar)0)
                            img[r][c]=(uchar)127;
                        //img[r][c]=(uchar)teapot[(r-8)*2][(c-264)*2];
                    }
                else
                    {
                        uchar number = 255-r/2;
                        img[r][c] = (uchar)number;
                    }
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
    fout . open( "teacupmodded.pgm") ;
    //
    fout << "P5" << endl ;
    //
    fout << "512 512" << endl << "255" << endl ;
    //
    for( int r = 0 ; r < 512 ; r++ )
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