#include "BMPFile.h"
#include "MainController.h"

BMPFile::BMPFile(const char* fileName)
{
	this->fileName = fileName;

	std::ifstream file(fileName, std::fstream::binary);

	if (file)
	{

		file.seekg(0, file.end);
		dataSize = file.tellg();
		file.seekg(0, file.beg);

		data = new byte[dataSize + 100];
		file.read((char*)data, dataSize);

		fileHeader = PBITMAPFILEHEADER(data);
		infoHeader = PBITMAPINFOHEADER(data + sizeof(BITMAPFILEHEADER));
		pixels = data + fileHeader->bfOffBits;
	}

	file.close();
}

BMPFile::BMPFile(const BMPFile& file)
{
	this->fileName = file.fileName;
	this->dataSize = file.dataSize;

	this->data = new byte[dataSize + 100];
	std::copy(file.data, file.data + file.dataSize, this->data);

	fileHeader = PBITMAPFILEHEADER(data);
	infoHeader = PBITMAPINFOHEADER(data + sizeof(BITMAPFILEHEADER));
	this->pixels = data + fileHeader->bfOffBits;
}

BMPFile::~BMPFile()
{
	delete[] data;
}

void BMPFile::saveFile()
{
	saveFile(this->fileName);
}

void BMPFile::saveFile(const char* _fileName)
{
	std::ofstream file(_fileName, std::fstream::binary);
	if (file)
	{
		file.write((char*)this->data, dataSize);
	}
	file.close();
}