
#include "opencv2/highgui/highgui.hpp"

using namespace cv;

int main( int argc, char** argv )
{
	if(argc<2)
		{
		printf("Usage: ./displayAVI [AVIfile]\n\nExiting..\n");
		return -1;
		};

	cvNamedWindow( "ReadAVI", CV_WINDOW_AUTOSIZE );
	CvCapture* capture = cvCreateFileCapture( argv[1] );

	IplImage* frame;


	while(1) {
		frame = cvQueryFrame( capture );
		if( !frame )
			{
			printf("AVI file is finished\n");
			break;
			}
		cvShowImage( "ReadAVI", frame );
		char c = cvWaitKey(33);
		if( c == 27 )
		{
			printf("You pressed ESC\n");
			break;
		}
	}

	cvReleaseCapture( &capture );
	cvDestroyWindow( "ReadAVI" );

	printf("Exiting..\n");

	return 0;
}


