//
#include <fstream>
#include <iostream>
#include <vector>
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
    ofstream fout;
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
        black-and-white 640-by-480 image.

        read points (x,y) from TXT file
        determine the number of points
        determine max + min (x,y) values

        then...
        draw a point (r,c) for each (x,y)
        points black + background white
        e except background instead 127 gray
        between y=380_000 and y=410_000

        leave a 5% buffer along the border
        ignore the true aspect ratio
        scale by (x - xmin) / (xmax - xmin)

        hint: don't draw the y upside down!
        13510 points
        END
    */
    
    // 
    ifstream fin;
    fin.open("points.txt");
    int val;
    int num;
    vector<double> xlist;
    vector<double> ylist;
    double maxx=-1.00,maxy=-1.00;
    double miny=999999999999999999.00,minx=9999999999999999999.00;
    while (fin>>val){
        double x = val;
        fin>>num;
        double y = num;
        if (maxx<x)
            maxx=x;
        else if (minx>=x)
            minx=x;
        if (maxy<y)
            maxy=y;
        else if (miny>=y)
            miny=y;
        xlist.push_back(x);
        ylist.push_back(y);
    }
    //std::cout<<maxx<<"  "<<minx<<"  "<<maxy<<"  "<<miny<<endl;
    for (int r = 0;r<H;r++)
        {
            for (int c = 0; c<W;c++)
            {
                img[r][c]=(uchar)3;
                if (r>=380 && r<=410)
                    img[r][c]=(uchar)2;
            }
        }
    for (int i=0;i<xlist.size();i++){
        double x=xlist[i];
        double y=ylist[i];
        double scaled_x = (x-minx)/(maxx-minx)*W*.9 + W*0.05;
        double scaled_y_not_flipped=(y-miny)/(maxy-miny)*H*.9 + H*0.05;
        double scaled_y=H*.95-scaled_y_not_flipped;
        int y_cord=static_cast<int>(scaled_y);
        int x_cord=static_cast<int>(scaled_x);
        img[y_cord][x_cord]=(uchar)1;
    }
    
    //
    save( img ) ;
    //
    return 0 ;
}
//
// end
//