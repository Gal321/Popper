#pragma once
/******************************************************************
*                                                                 *
* EE_Base.h - Include and declare all the cores.                  *
*                                                                 *
******************************************************************/

#ifdef _DEBUG
#include <cstdio>
#define DEBUG_PRINT(...) fprintf(stderr, __VA_ARGS__) 
#else
#define DEBUG_PRINT(x) (do {} while (0))
#endif

#define DEFAULT_FONT "../Res/SourceSansPro-Light.ttf"
#define DEFAULT_WIDTH 450
#define DEFAULT_HEIGHT 150

/******************************************************************
*                                                                 *
* -------^^^^^^^------- Includes and defines -------^^^^^^------- *
*                                                                 *
* -------vvvvvvvvvv-------- Declarations --------vvvvvvvvv------- *
*                                                                 *
******************************************************************/

namespace EE
{
	typedef unsigned char Byte;

	typedef struct Size
	{
		static Size Get(int width = 10, int height = 10) { return {width, height}; }

		int width;
		int height;
	} Size;

	typedef struct Point
	{
		static Point Get(int x = 0, int y = 0) { return {x, y}; }

		int x;
		int y;
	} Point;

	typedef unsigned char Uint8;
	typedef unsigned short Uint16;
	typedef unsigned int Uint32;
	typedef unsigned long long Uint64;
}
