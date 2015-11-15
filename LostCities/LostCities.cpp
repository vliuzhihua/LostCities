
#define DLL_FILE
#include "LostCities.h"
#include "config.h"
using namespace LC;
	
void LCGame::init(const Player& p1, const Player& p2, const int whoStart){
	Random::init(); //important!!!!  need first to init random generator, make sure it work	
	whoPlay = whoStart;
	status = -1;
	for (int i = 0; i < 5; i++){
		for (int j = 1; j <= 10; j++){
			Card ca(i, j);
			remain_deck.push_bottom(ca);
		}
	}
	remain_deck.shuffle();

	player[0] = p1;
	player[1] = p2;

	//debug output
#ifdef DEBUG_OUTPUT
	std::cout << "game init" << std::endl;
#endif
}
//player play card
bool LCGame::playerDiscard(Player* p, const Card& ca, ErrorMsg* em){
	if (p->playerId == player[whoPlay].playerId){
//debug output
#ifdef DEBUG_OUTPUT
		std::cout << "p-" << p->playerId << " discard " << Card::colorName[ca.color] << ":" << ca.number << std::endl;
#endif	
		discard_deck[ca.color].push_bottom(ca);
		p->hand.delete_card(ca);//note that delete will redirect the value in ca
		//update player info in game
		//player[whoPlay] = p;
		whoPlay = (whoPlay + 1) % 2;

		return true;
	}
	else{
		return false;
	}
}
bool LCGame::playerPlay(Player* p, const Card& ca, ErrorMsg* em){
	if (p->playerId == player[whoPlay].playerId){
		
		if (playedDeck[whoPlay][ca.color].size() == 0 || (playedDeck[whoPlay][ca.color].size() != 0 && playedDeck[whoPlay][ca.color].bottom().number <= ca.number)){
//debug output
#ifdef DEBUG_OUTPUT
			std::cout << "p-" << p->playerId << " play " << Card::colorName[ca.color] << ":" << ca.number << std::endl;
#endif			
			playedDeck[whoPlay][ca.color].push_bottom(ca);
			p->hand.delete_card(ca);
			//update player info in game
			//player[whoPlay] = p;
			whoPlay = (whoPlay + 1) % 2;
			

			return true;
		}
		else{
			return false;
		}
	}
	else{
		return false;
	}
}


bool LCGame::draw(Player* p, const int dn /*discard deck subscript*/){
	if (p->hand.size() <= 7){
		if (dn == -1){//if dn equal -1, then we draw card from remain_deck
			if (remain_deck.size() == 0){//no card to draw
				return false;
			}
			p->hand.push_bottom(remain_deck.top());
			remain_deck.pop_top();

			//update player info in game
			//player[whoPlay] = p;//error

#ifdef DEBUG_OUTPUT
			std::cout << "p-" << p->playerId << " draw from remain deck " << Card::colorName[p->hand.back().color] << ":" << p->hand.back().number << std::endl;
#endif
		}
		else{
			if (discard_deck[dn].size() == 0){//no card to draw
				return false;
			}
			p->hand.push_bottom(discard_deck[dn].top());
			discard_deck[dn].pop_top(); 

			//update player info in game
			//player[whoPlay] = p;
#ifdef DEBUG_OUTPUT
			std::cout << "p-" << p->playerId << " draw from discard deck " << dn << " " \
				<< Card::colorName[p->hand.back().color] << ":" << p->hand.back().number << std::endl;
#endif
		}
		
	}
}

void LCGame::updateStatus(){
	if (remain_deck.size() == 0){
		int val[2];
		val[0] = calValue(0);
		val[1] = calValue(1);
		if (val[0] > val[1]){
			status = 0;
		}
		else{
			status = 1;
		}

	}
}
bool LCGame::checkStatus(int* winner){
	if (status == -1){
		return false;
	}
	else{
		*winner = status;
		return true;
	}
}

//void LCGame::addPlayer(Player& player){
//	if ()
//}
int LCGame::calValue(int playerId){
	int val = 0;
	for (int i = 0; i < 5; i++){
		val += playedDeck[playerId][i].get_val();
	}
	return val;
}

LCGame::LCGame(){

}
void LCGame::start(){
	//for (int i = 0; i < 8; i++){
		//draw(player[0]);
		//draw(player[1]);
	//}
	//std::cout << "game start" << std::endl;
	
}