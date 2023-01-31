#include "MainController.h"
#include "pch.h"



MainController::MainController() 
{
	inputFileA = nullptr;
	inputFileB = nullptr;
	outputFile = nullptr;
	numThreads = 1;
	library = LoadLibraryA("DLL1.dll");
}

MainController::~MainController() 
{
	delete inputFileA;
	delete inputFileB;
	delete outputFile;
	std::remove("tmp.bmp");
}

float MainController::mixPixels(int factor) {

	MixValues test = (MixValues)GetProcAddress(library, "MixValues1");
 
	
	int bytesSection = inputFileA->infoHeader->biHeight;

	int width = inputFileA->infoHeader->biWidth * 3;

	if (width % 4 != 0)
		width += 4 - width % 4;
	

	bytesSection *= width;

	bytesSection /= numThreads;

	if (bytesSection % REGISTER_SIZE != 0)
	{
		bytesSection -= bytesSection % REGISTER_SIZE;
	}
	
	std::thread* threads = new std::thread[numThreads];

	//measure time
	auto start = std::chrono::steady_clock::now();

	for (int i = 0; i < numThreads - 1; i++) {
		threads[i] = std::thread(test, inputFileA->pixels + i * bytesSection, inputFileB->pixels + i * bytesSection, bytesSection, factor, outputFile->pixels + i * bytesSection);
	}

	int numOfBytesLeft = inputFileA->infoHeader->biHeight * width - bytesSection * (numThreads - 1);
	threads[numThreads - 1] = std::thread(test, inputFileA->pixels + (numThreads - 1) * bytesSection, inputFileB->pixels + (numThreads - 1) * bytesSection, numOfBytesLeft, factor, outputFile->pixels + (numThreads - 1) * bytesSection);

	for (int i = 0; i < numThreads; i++)
		threads[i].join();

	auto end = std::chrono::steady_clock::now();
	float elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
	
	delete[] threads;

	outputFile->saveFile("tmp.bmp");

	return elapsedTime;
}

void MainController::loadFileA(const char* filepath)
{
	inputFileA = new BMPFile(filepath);
	outputFile = new BMPFile(*inputFileA);
}

void MainController::loadFileB(const char* filepath)
{
	inputFileB = new BMPFile(filepath);
}
void MainController::setThreads(int number)
{
	this->numThreads = number;
}
void MainController::loadLibrary(Library type)
{
	switch (type)
	{
	case MainController::CPP:
		library = LoadLibraryA("DLL2.dll");
		break;
	case MainController::ASM:
		library = LoadLibraryA("DLL1.dll");
		break;
	}
}
bool MainController::validateImageSize()
{
	if (inputFileA->infoHeader->biWidth == inputFileB->infoHeader->biWidth && inputFileA->infoHeader->biHeight == inputFileB->infoHeader->biHeight)
		return true;
	else
		return false;
}
bool MainController::validateImageLoaded()
{
	if (inputFileA == nullptr || inputFileB == nullptr)
		return false;
	else
		return true;
}


