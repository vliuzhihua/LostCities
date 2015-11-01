
#define DLL_FILE
#include "Deck.h"
#include "Random.h"
using namespace LC;
//namespace LC{
	Deck::Deck(){
		cardList.clear();
	}

	void Deck::shuffle(){
		int sz = cardList.size();
		Card* cardTmp = new Card[sz];
		std::list<Card>::iterator it;
		int c = 0;
		for (it = cardList.begin(); it != cardList.end(); it++){
			cardTmp[c] = *it;
			c++;
		}
		for (int i = 0; i < sz; i++){
			int val = i + Random::getRandom() % (sz - i);
			Card tc = cardTmp[i];
			cardTmp[i] = cardTmp[val];
			cardTmp[val] = tc;
		}
		cardList.clear();
		for (int i = 0; i < sz; i++){
			cardList.push_back(cardTmp[i]);
		}
	}



	Card Deck::top(){
		return cardList.front();
	}

	void Deck::pop_bottom(){
		cardList.pop_front();
	}
	void Deck::push_top(Card &ca){
		cardList.push_front(ca);
	}
	void Deck::pop_top(){
		cardList.pop_front();
	}
	void Deck::push_bottom(Card &ca){
		cardList.push_back(ca);
	}
	
	void Deck::delete_card(Card& ca){
		cardList.remove(ca);
	}
	int Deck::size(){
		return cardList.size();
	}
	int Deck::get_val(){
		std::list<Card>::iterator it;
		bool countMul = true;
		int mulFactor = 1;
		int val = 0;
		for (it = cardList.begin(); it != cardList.end(); it++){
			if (countMul){
				if (it->number == 1){
					mulFactor++;
				}
				else{
					countMul = false;
					val += it->number;
				}
			}
			else{
				val += it->number;
			}
		}
		if (val != 0){
			val -= 20;
			val *= mulFactor;
		}
		return val;
	}