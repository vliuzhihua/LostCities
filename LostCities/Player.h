#ifndef PLAYER_H
#define PLAYER_H

#include "Deck.h"
#include <string>
namespace LC{
//#ifdef DLL_FILE
	class _declspec(dllexport) Player;
//#else
//	class _declspec(dllimport) Player;
//#endif

	class Player{
	public:
		std::string playerId;
		Deck hand;
		Deck playedDeck[5];
		int cal_val();
		Player(std::string id = "");
	};
}
#endif