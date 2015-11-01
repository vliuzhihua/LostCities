#ifndef PLAYER_H
#define PLAYER_H

#include "Deck.h"
#include <string>
namespace LC{
	class _declspec(dllexport) Player;

	class Player{
	public:
		std::string playerId;
		Deck hand;
		Deck playedDeck[5];
		int cal_val();
	};
}
#endif