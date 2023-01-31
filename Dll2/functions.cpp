#include "pch.h"
#include "functions.h"

void MixValues1(byte* inputA, byte* inputB, int numOfPixels, int factor, byte* output) {

	for (int i = 0; i < numOfPixels; i++) {
		*(output + i) = *(inputA + i) * factor + *(inputB + i) * (256 - factor) >> 8;
	}
}

void MixValues2(byte* inputA, byte* inputB, int numOfPixels, int factor, byte* output)
{
	int valuesA[256];
	int valuesB[256];

	for (int i = 0; i < 256; i++)
	{
		valuesA[i] = i * factor;
		valuesB[i] = i * (256 - factor);
	}

	for (int i = 0; i < numOfPixels; i++)
	{
		*(output + i) = valuesA[*(inputA + i)] + valuesB[*(inputB + i)] >> 8;
	}
}
