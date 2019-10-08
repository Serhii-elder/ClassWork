#include <iostream>
#include <vector>
#include<iterator>
using namespace std;

enum CardType {SIX = 6,SEVEN,EIGHT,NINE,TEN,J,Q,K,T };
enum CardSuit {H,D,C,S};

struct Card
{
	
	CardType type;
	CardSuit suit;

	Card(){}
	Card(CardType type,CardSuit suit):type(type),suit(suit){}

	
	


};

class DeckCard {

	vector<Card> dec;

	void DecInit() {
		for (int i = 6; i <= 15; i++) {
			for (int j = 0; j < 4; j++){
				
				dec.insert(dec.end(), Card((type)i,(suit)j));
		}
	}
	}




};


int main()
{
	
	DeckCard card;
	
	
	cout << endl;
	system("pause");
	return 0;
}