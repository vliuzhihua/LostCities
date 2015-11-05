
#define DLL_FILE
#include "Deck.h"
#include "Random.h"
#include "config.h"
using namespace LC;
//namespace LC{
	Deck::Deck():list<Card>(){
		this->clear();
	}

	void Deck::shuffle(){
		int sz = this->size();
		Card* cardTmp = new Card[sz];
		std::list<Card>::iterator it;
		int c = 0;
		for (it = this->begin(); it != this->end(); it++){
			cardTmp[c] = *it;
			c++;
		}
		for (int i = 0; i < sz; i++){
			int val = i + Random::getRandom() % (sz - i);
			Card tc = cardTmp[i];
			cardTmp[i] = cardTmp[val];
			cardTmp[val] = tc;
		}
		this->clear();
		for (int i = 0; i < sz; i++){
			this->push_back(cardTmp[i]);
		}
		delete[] cardTmp;
	}



	Card Deck::top(){
		//list<int> ls;
		
		return this->front();
	}
	Card Deck::bottom(){
		return this->back();
	}
	void Deck::pop_bottom(){
		this->pop_front();
	}
	void Deck::push_top(Card &ca){
		this->push_front(ca);
	}
	void Deck::pop_top(){
		this->pop_front();
	}
	void Deck::push_bottom(Card &ca){
		this->push_back(ca);
	}
	
	void Deck::delete_card(Card& ca){
		this->remove(ca);
	}
	//int Deck::size(){
	//	return this->size();
	//}
	int Deck::get_val(){
		Deck::iterator it;
		bool countMul = true;
		int mulFactor = 1;
		int val = 0;
		for (it = this->begin(); it != this->end(); it++){
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