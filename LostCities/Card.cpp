#define DLL_FILE
#include "Card.h"
#include "config.h"

using namespace LC;
//namespace LC{
std::string Card::colorName[5] = { "red", "blue", "white", "yellow", "green" };
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

	bool Card::operator <(const Card& ca) const{
		if (this->color < ca.color){
			return true;
		}
		else if (this->color > ca.color){
			return false;
		}
		else{
			if (this->number < ca.number){
				return true;
			}
			else{
				return false;
			}
		}
	}

//}

