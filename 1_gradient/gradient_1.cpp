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
    uchar    img[384][512] ;
    //
    //
    for( int c = 0 ; c < 512 ; c++ )
    {
        for( int r = 0 ; r < 384 ; r++ )
            {
                if ((c >=64 && c<=128  && r >=64 && r<=128)  || (c >=384 && c<= 448&&  r >=64 && r<=128))
                    {
                        img[r][c]=(uchar)126;
                    }
                else
                    {
                        uchar number = c/2;
                        img[r][c] = (uchar)number;
                    }
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
    //64x64 
    //64 192
    //384 192 
    for (int x = 0; x<321;x++){
        //
        ofstream fout          ;
        //
        ostringstream oss;
        oss << setfill('0') << setw(3) << x;
        string result = oss.str();
        string filename = "frame" + result;
        //
        fout . open( filename+".pgm" ) ;
        //
        fout << "P5" << endl ;
        //
        fout << "512 384" << endl << "255" << endl ;
        //
        for( int r = 0 ; r < 384 ; r++ )
        {
            for( int c = 0 ; c < 512 ; c++ )
            {
                if ((r>=192 &&r<=256) && (c>=(64+x) && c<=(128+x))){
                    img[r][c]=(uchar)126;
                    
                }    
                if(x>0&&c<x+64&&(r>=192 &&r<=256)){
                        uchar number = c/2;
                        img[r][c] = (uchar)number;
                    }

                fout << img[r][c] << flush ;
                //
                //               NOT endl !!!
            }
        }
    //
    fout . close() ;
    }
}
//
// end
//