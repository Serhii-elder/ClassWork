#include<iostream>
#include <algorithm>
#include<vector>

using namespace std;

class Card
{
public:
	enum ESuit
	{
		kSuit_Heart,
		kSuit_Club,
		kSuit_Diamond,
		kSuit_Spade,
		kSuit_Count
	};

	enum ERank
	{
		kRank_Ace,
		kRank_Two,
		kRank_Three,
		kRank_Four,
		kRank_Five,
		kRank_Six,
		kRank_Seven,
		kRank_Eight,
		kRank_Nine,
		kRank_Ten,
		kRank_Jack,
		kRank_Queen,
		kRank_King,
		kRank_Count
	};

private:
	ESuit mSuit;
	ERank mRank;
public:
	static int const skNumCards = kSuit_Count * kRank_Count;

	Card(int cardIndex): mSuit(static_cast<ESuit>(cardIndex / kRank_Count)), mRank(static_cast<ERank>(cardIndex % kRank_Count))
	{}

	ESuit GetSuit() const {
		return mSuit );
		ERank GetRank() const {
			return mRank );

		}
		

			rstl::vector<Card> mCards;
		mCards.reserve(Card::skNumCards);

		for (int cardValue = 0; cardValue < Card::skNumCards; ++cardValue)
		{
			mCards.push_back(Card(cardValue));
		}
		


			std::random_shuffle(mCards.begin(), mCards.end());
		

			if (mCards[0].GetSuit() == Card::kRank_Club && mCards[0].GetRank() == Card::kRank_Ace)
			{
				std::cout << "ACE OF CLUBS!" << std::endl;
			}