#include"GL/glut.h"
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>

void CaptureScreen(char *Filename, int Width, int Height)
{
	BITMAPFILEHEADER bf;
	BITMAPINFOHEADER bi;

	unsigned char *image	= (unsigned char*)malloc(sizeof(unsigned char)*Width*Height*3);
	FILE *file	 = fopen("capture.bmp", "wb");

	if( image!=NULL ) {
		if( file!=NULL ) {
			glReadPixels( 0, 0, Width, Height, GL_BGR_EXT, GL_UNSIGNED_BYTE, image );

			memset( &bf, 0, sizeof( bf ) );
			memset( &bi, 0, sizeof( bi ) );

			bf.bfType	 = 'MB';
			bf.bfSize	 = sizeof(bf)+sizeof(bi)+Width*Height*3;
			bf.bfOffBits = sizeof(bf)+sizeof(bi);
			bi.biSize	 = sizeof(bi);
			bi.biWidth	 = Width;
			bi.biHeight	 = Height;
			bi.biPlanes	 = 1;
			bi.biBitCount	 = 24;
			bi.biSizeImage	 = Width*Height*3;

			fwrite( &bf, sizeof(bf), 1, file );
			fwrite( &bi, sizeof(bi), 1, file );
			fwrite( image, sizeof(unsigned char), Height*Width*3, file );

			fclose( file );
		}
		free( image );
	}
}