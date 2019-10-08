
#include<iostream>
#include<string>
					using namespace std;

				class Player
				{
				private:
					string name;
					int age;
					float points;
					bool isMale;
					int games;
					double avgPointsPerGame;

					void SetAvgPointsPerGame()
					{
						avgPointsPerGame = points / games;
					}

				public:
					// Setters
					void SetName(const string newName);
					void SetAge(const int newAge)
					{
						if (newAge < 0 || newAge > 300)
							return;

						age = newAge;
					}
					void SetPoints(const int newPoints)
					{
						if (newPoints < 0)
							return;

						points = newPoints;
						SetAvgPointsPerGame();
					}
					void SetGames(const int newGames)
					{
						if (newGames < 0)
							return;

						games = newGames;
						SetAvgPointsPerGame();
					}
					void SetGender(const bool newIsMale)
					{
						isMale = newIsMale;
					}

					void ChangeGender()
					{
						SetGender(!isMale);
					}

					// Getters
					string GetName() const
					{
						return name;
					}
					int GetAge() const
					{
						return age;
					}
					int GetGames() const
					{
						return games;
					}
					int GetPoints() const
					{
						return points;
					}
					int GetAveragePointsPerGame() const
					{
						return avgPointsPerGame;
					}

					void Show() const
					{
						cout << "Name: " << name << endl;
						cout << "Age: " << age << endl;
						cout << "Points: " << points << endl;
						cout << "Games: " << games << endl;
						cout << "Avg: " << avgPointsPerGame << endl;
						cout << "Gender: " << (isMale ? "Male" : "Female") << endl;
					}

					void Fill()
					{
						cout << "Name: "; cin >> name;
						cout << "Age: "; cin >> age;
						cout << "Points: "; cin >> points;
						cout << "Games: "; cin >> games;
						cout << "Gender (0 - female, 1 - male): "; cin >> isMale;

						SetAvgPointsPerGame();
					}
				};
				void main() {
					Player p;

					p.Fill();

					cout << "----------------------------" << endl;
					p.Show();
					cout << "----------------------------" << endl;

					//	p.GetName();
					system("pause");
				}
				