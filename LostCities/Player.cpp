#include "Player.h"
#include "config.h"


using namespace LC;

int Player::cal_val(){
	int val = 0;
	for (int i = 0; i < 5; i++){
		val += playedDeck[i].get_val();
	}
	return val;

}

Player::Player(std::string id){
	playerId = id;
}