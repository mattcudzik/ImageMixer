#pragma once
#include "BMPFile.h"
#include <thread>
#include <iostream>
#include <string>
#include <chrono>


typedef void(_stdcall* MixValues)(byte*, byte*, int, int, byte*);

class MainController
{
	BMPFile* inputFileA;
	BMPFile* inputFileB;
	BMPFile* outputFile;
	short numThreads;
	HINSTANCE library;

public:
	static const int REGISTER_SIZE = 8;

	enum Library
	{
		CPP,
		ASM
	};
	MainController();
	~MainController();

	float mixPixels(int factor);
	void loadFileA(const char* filepath);
	void loadFileB(const char* filepath);
	void setThreads(int number);
	void loadLibrary(Library type);
	bool validateImageSize();
	bool validateImageLoaded();
	void measureTime();
};

