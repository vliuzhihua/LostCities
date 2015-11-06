#ifndef LOSTCITIES_H
#define LOSTCITIES_H
#include "Random.h"
#include "Deck.h"
#include "Card.h"
#include "Player.h"
using ErrorMsg = int;
namespace LC{
//#ifdef DLL_FILE
	class _declspec(dllexport) LCGame;
//#else
//	class _declspec(dllimport) LCGame;
//#endif

	class LCGame{
	public:
		Deck remain_deck;	//
		Deck discard_deck[5];//discard deck
		Player player[2];	//two player in the game just to save the player status in game.
		int whoPlay;	//this time who play card
		int status;//-1 indicate no people win, else indicate subscript win

		LCGame();	//default constructor
		void init(Player& p1, Player& p2, int whoStart = 0);
		bool playerDiscard(Player& p, Card& ca, ErrorMsg* em);

		bool playerPlay(Player& p, Card& ca, ErrorMsg* em);

		bool draw(Player& p, int dn = -1 /*discard deck subscript*/);	//if dn == -1,then we draw card from remain_deck.

		void updateStatus(Player& p0, Player& p1);
		
		bool checkStatus(int* winner);//true indicate terminal the game, else continue
		
		//void addPlayer(Player &player);	//add player to the game;

		void start();

	};
}
#endif