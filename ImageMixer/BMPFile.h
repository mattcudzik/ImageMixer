#pragma once
#include <fstream>
#include <Windows.h>

typedef unsigned char byte;

struct BMPFile
{
	PBITMAPFILEHEADER fileHeader;
	PBITMAPINFOHEADER infoHeader;
	byte* data;
	byte* pixels;
	size_t dataSize;
	const char* fileName;

public:
	BMPFile(const char* fileName);
	BMPFile(const BMPFile& file);
	~BMPFile();
	void saveFile();
	void saveFile(const char* fileName);
};

