// lab_10_1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "lab_10_dll.h"


// DLL 


extern "C" __declspec(dllexport) int fnc2(double p1, char p2)
{
	return p1 + p2;
}

