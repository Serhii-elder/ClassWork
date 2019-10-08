#pragma once
class MyClass
{
	int data;
public:
	MyClass() {}
	MyClass(int d) : data(d) {}

	void Show() const { cout << data << " "; }
	bool operator < (const MyClass& obj) const
	{
		return this->data < obj.data;
	}
};

int main()
{
	vector<MyClass> v = { 1, 2, 3, 4, 5 };

	for (auto i : v)
		i.Show();
	cout << endl;

	srand(time(0));
	random_shuffle(v.begin(), v.end());

	random_device seed;
	mt19937 rnd(seed());
	shuffle(v.begin(), v.end(), rnd);

	for (auto i : v)
		i.Show();
	cout << endl;

	sort(v.begin(), v.end());

	for (auto i : v)
		i.Show();
	cout << endl;

	system("pause");
	return 0;
}



enum CardType { SIX, SEVEN, EIGHT, NINE, TEN, J, Q, K, T };
enum CardSuit { SPADE, DIAMOND, HEART, CLUB };

class Card
{
	CardType type;
	CardSuit suit;

public:
	Card() {}
	Card(CardType type, CardSuit suit) : type(type), suit(suit) {}

	bool operator < (const Card& other) const;
	void Print() const;
};

class CardDeck
{
	vector<Card> deck;	// оберіть контейнет для збереження карт

public:
	CardDeck() {}

	void InitDeck();
	void SortDeck();
	void ShuffleDeck();
	Card PickCard() const;
	Card PopCard();
	void PrintDeck() const;
};
Co