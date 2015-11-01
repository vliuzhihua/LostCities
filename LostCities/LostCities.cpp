
#define DLL_FILE
#include "LostCities.h"
using namespace LC;
	
void LCGame::init(int whoStart = 0){
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

}
//player play card
bool LCGame::playerDiscard(Player& p, Card& ca, ErrorMsg* em){
	if (p.playerId == player[whoPlay].playerId){
		whoPlay = (whoPlay + 1) % 2;
		discard_deck[ca.color].push_bottom(ca);
		p.hand.delete_card(ca);
		return true;
	}
	else{
		return false;
	}
}
bool LCGame::playerPlay(Player& p, Card& ca, ErrorMsg* em){
	if (p.playerId == player[whoPlay].playerId){
		whoPlay = (whoPlay + 1) % 2;
		if (p.playedDeck[ca.color].top().number < ca.number){
			p.playedDeck[ca.color].push_bottom(ca);
			p.hand.delete_card(ca);
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


void LCGame::draw(Player& p, int dn = -1 /*discard deck subscript*/){
	if (p.hand.size() <= 7){
		if (dn == -1){
			p.hand.push_bottom(remain_deck.top());
			remain_deck.pop_top();
		}
		else{
			p.hand.push_bottom(discard_deck[dn].top());
			discard_deck[dn].pop_top(); 
		}
		
	}
}

void LCGame::updateStatus(){
	if (remain_deck.size() == 0){
		int val[2];
		val[0] = player[0].cal_val();
		val[1] = player[1].cal_val();
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