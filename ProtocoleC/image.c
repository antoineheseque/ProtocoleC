#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "camera.h"
#include "color.h"

void exportIMG(Camera camera, Color * color, char * fileName)
{
	//width, height, and bitcount are the key factors:
	int32_t width = camera.screenWidth;
	int32_t height = camera.screenHeight;
	uint16_t bitcount = 24; // 24-bit bitmap

							//take padding in to account
	int width_in_bytes = ((width * bitcount + 31) / 32) * 4;

	//total image size in bytes, not including header
	uint32_t imagesize = width_in_bytes * height;

	//this value is always 40, it's the sizeof(BITMAPINFOHEADER)
	const uint32_t biSize = 40;

	//bitmap bits start after headerfile,
	//this is sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER)
	const uint32_t bfOffBits = 54;

	//total file size:
	uint32_t filesize = 54 + imagesize;

	//number of planes is usually 1
	const uint16_t biPlanes = 1;

	//create header:
	//copy to buffer instead of BITMAPFILEHEADER and BITMAPINFOHEADER
	//to avoid problems with structure packing
	unsigned char header[54] = { 0 };
	memcpy(header, "BM", 2);
	memcpy(header + 2, &filesize, 4);
	memcpy(header + 10, &bfOffBits, 4);
	memcpy(header + 14, &biSize, 4);
	memcpy(header + 18, &width, 4);
	memcpy(header + 22, &height, 4);
	memcpy(header + 26, &biPlanes, 2);
	memcpy(header + 28, &bitcount, 2);
	memcpy(header + 34, &imagesize, 4);

	//prepare pixel data:
	unsigned char* buf = malloc(imagesize);
	int u = 0;
	for (int row = height - 1; row >= 0; row--)
	{
		for (int col = 0; col < width; col++)
		{
			buf[row * width_in_bytes + col * 3 + 0] = color[u].b;//blue
			buf[row * width_in_bytes + col * 3 + 1] = color[u].g;//green
			buf[row * width_in_bytes + col * 3 + 2] = color[u].r;//red
			u++;
		}
	}
	u = 0;
	const char* extension = ".bmp";
	char* nameWithExt;
	nameWithExt = malloc(strlen(fileName) + 5);
	strcpy(nameWithExt, fileName);
	strcat(nameWithExt, extension);
	FILE *fout = fopen(nameWithExt, "wb");
	fwrite(header, 1, 54, fout);
	fwrite((char*)buf, 1, imagesize, fout);
	fclose(fout);
	free(buf);
}
