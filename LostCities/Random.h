#ifndef RANDOM_H
#define RNAANDOM_H
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

namespace LC{
//#ifdef DLL_FILE
	class _declspec(dllexport) Random;
//#else
//	class _declspec(dllimport) Random;
//#endif
	class Random{
	public:
		static void init(){
			srand((int)time(0));
		}
		static int getRandom(){
			return rand();
		}
	};
}
#endif