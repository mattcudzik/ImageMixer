#pragma once
#ifdef DllExport
#undef DllExport
#define DllExport __declspec(dllexport)
#else
#define DllExport __declspec(dllimport)
#endif

typedef unsigned char byte;
extern "C" void DllExport MixValues1(byte* inputA, byte* inputB, int numOfPixels, int factor, byte* output);
extern "C" void DllExport MixValues2(byte* inputA, byte* inputB, int numOfPixels, int factor, byte* output);
