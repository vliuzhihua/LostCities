#ifndef CARD_H
#define CARD_H
namespace LC{
//#ifdef DLL_FILE
	class _declspec(dllexport) Card;
//#else
//	class _declspec(dllimport) Card;
//#endif
	
	class Card{
	public:
		static enum CardColor{ red, blue, white, yellow, green };
		int color;  //enum red, blue, white, yellow, green
		int number; // 1~10  use 1 to indicate multiple card
		Card(int color, int number);
		Card();
		bool operator ==(const Card& ca);
	};

}

#endif