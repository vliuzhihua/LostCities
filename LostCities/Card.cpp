#define DLL_FILE
#include "Card.h"

using namespace LC;
//namespace LC{
	Card::Card(){

	}
	Card::Card(int color, int number){
		this->color = color;
		this->number = number;
	}
	bool Card::operator==(const Card& ca){
	if (this->color == ca.color && this->number == ca.number){
		return true;
	}
	else{
		return false;
	}
		}

//}

