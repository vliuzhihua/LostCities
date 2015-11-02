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
		Deck remain_deck;
		Deck discard_deck[5];
		Player player[2];
		int whoPlay;
		int status;//-1 indicate no people win, else indicate subscript win
		void init(int whoStart);
		bool playerDiscard(Player& p, Card& ca, ErrorMsg* em);

		bool playerPlay(Player& p, Card& ca, ErrorMsg* em);

		void draw(Player& p, int dn /*discard deck subscript*/);

		void updateStatus();
		
		bool checkStatus(int* winner);//true indicate terminal the game, else winner
		



	};
}
#endif