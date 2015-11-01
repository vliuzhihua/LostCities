#ifndef RANDOM_H
#define RNAANDOM_H
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

namespace LC{
	class _declspec(dllexport) Random;
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