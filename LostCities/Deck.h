#ifndef DECK_H
#define DECK_H
#include <list>
#include "Card.h"
#include <iostream>

namespace LC{
//#ifdef DLL_FILE
	class _declspec(dllexport) Deck;
//#else
//	class _declspec(dllimport) Deck;
//#endif

	//inhere
	class Deck :public std::list<Card>{
	public:
		//void init(); 
		Deck();

		void shuffle();

		Card top();
		Card bottom();

		void pop_bottom();
		void push_bottom(Card &ca);

		void pop_top();
		void push_top(Card &ca);

		void delete_card(Card& ca);

		//int size();
		int get_val();
		void show(){
			int sz = this->size();
			Deck::iterator it;
			for (it = this->begin(); it != this->end(); it++){
				std::cout << it->number << "   " << it->color << std::endl;
			}
			std::cout << std::endl;
		}
	};
}
#endif