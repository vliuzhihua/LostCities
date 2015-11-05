#include <iostream>
#include <windows.h>
using namespace std;
#include "LostCities.h"
using namespace LC;


//void playerDraw(Player &p, )

int main(){

	//create two player
	Player p[2];
	p[0].playerId = "one";
	p[1].playerId = "two";

	//init game
	LCGame lcg;
	lcg.init(p[0], p[1]);

	cout << lcg.remain_deck.size() << endl;
	lcg.remain_deck.show();
	//game start
	//lcg.start();//all player draw card;
	
	for (int i = 0; i < 8; i++){
		lcg.draw(p[0]);
		lcg.draw(p[1]);
	}
	int winner;
	int round = 2;
	int oldRound = 0;
	//auto play strategy
	while (!lcg.checkStatus(&winner)){
		if (round != oldRound){
			cout << "round " << round << endl;
			oldRound = round;
		}
		
		Player& tp = p[rand() % 2]; //determine who play
		int playToWhere = rand() % 2;
		
		ErrorMsg em;
		//lcg.draw(p[0]);
		//lcg.draw(p[1]);

		if (playToWhere){
			//play normal
			Deck::iterator it;
			int playedOutOrNot = 0;
			for (it = tp.hand.begin(); it != tp.hand.end(); it++){
				if (lcg.playerPlay(tp, *it, &em)){
					playedOutOrNot = 1;
					break;
				}
			}
			if (!playedOutOrNot){
				continue;
				//lcg.playerDiscard(tp, tp.hand.top(), &em);
			}
		}
		else{
			//play to discard deck
			if (!lcg.playerDiscard(tp, tp.hand.top(), &em)){
				continue;
			}
		}

		for (;;){
			int drawFromWhere = rand() % 2;
			Sleep(100);
			if (drawFromWhere){
				//draw from remain deck
				if (lcg.draw(tp)){
					break;
				}
			}
			else{
				//draw from discrad deck
				int drawFrom = rand() % 5;
				if (lcg.draw(tp, drawFrom)){
					break;
				}
			}
			
		}
		lcg.updateStatus();
		round++;
		Sleep(100);
		//system("pause");
	}
	cout << "game end" << endl;
	




}