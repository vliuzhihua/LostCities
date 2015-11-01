#ifndef DECK_H
#define DECK_H
#include <list>
#include "Card.h"
#include <iostream>

namespace LC{
	class _declspec(dllexport) Deck;

	class Deck{
	public:
		std::list<Card> cardList;

		//void init(); 
		Deck();

		void shuffle();

		Card top();

		void pop_bottom();
		void push_bottom(Card &ca);

		void pop_top();
		void push_top(Card &ca);

		void delete_card(Card& ca);

		int size();
		int get_val();
		void show(){
			int sz = cardList.size();
			std::list<Card>::iterator it;
			for (it = cardList.begin(); it != cardList.end(); it++){
				std::cout << it->number << "   " << it->color << std::endl;
			}
			std::cout << std::endl;
		}
	};
}
#endif