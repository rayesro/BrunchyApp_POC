#include <iostream>
#include <string>

using namespace std;

int main()
{
	int menuOption = 0;

	string characters[5];
	characters[0] = "Marco";
	characters[1] = "Fio";
	characters[2] = "Ralph";
	characters[3] = "Clark";
	characters[4] = "Leona";

	struct Player
	{
		int selectedCharacterIndex;
		int scorePoints;
		int level;
	};
	Player p1,p2,p3,p4;
	Player players[5];

	do {
		system("cls");
		cout << "____METAL SLUG X____" << endl << endl;
		cout << " 1) Main Mission" << endl;
		cout << " 2) Multiplayer" << endl;
		cout << " 3) Leaderboard" << endl;
		cout << " 4) Quit game" << endl;
		cout << " Select an option: ";
		cin >> menuOption;

		switch (menuOption)
		{
		case 1:
		{
			system("cls");
			cout << "____METAL SLUG X____" << endl << endl;
			cout << "____Main mission____" << endl << endl;
	
			for (int i = 0; i < 5; i++)
			{
				cout << "Character #" << i + 1 <<") - " << characters[i] << endl;
			}

			cout << "---> Choose your character: ";
			cin >> p1.selectedCharacterIndex;
			p1.selectedCharacterIndex--;

			cout << "---> Enter your score points: ";
			cin >> p1.scorePoints;

			p1.level = p1.scorePoints / 1000;

			cout << "____INFO____" << endl << endl;
			cout << "Your character: " << characters[p1.selectedCharacterIndex] << endl;
			cout << "Your score: " << p1.scorePoints << endl;
			cout << "Your level: " << p1.level << endl;

			break;
		}
		case 2:
		{
			int playersCount = 0;
			
			system("cls");
			cout << "____METAL SLUG X____" << endl << endl;
			cout << "____Multiplayer____" << endl << endl;

			cout << "How many players will play?: ";
			cin >> playersCount;

			for (int i = 0; i < 5; i++)
			{
				cout << "Character #" << i + 1 << ") - " << characters[i] << endl;
			}

			for (int i = 0; i < playersCount; i++)
			{
				cout << "---> Player "<< i + 1 <<", choose your character: ";
				cin >> players[i].selectedCharacterIndex;
				players[i].selectedCharacterIndex--;

				cout << "---> Player " << i + 1 << ", enter your score points: ";
				cin >> players[i].scorePoints;
				players[i].level = players[i].scorePoints / 1000;
			}

			cout <<endl << "____INFO____" << endl << endl;

			for (int i = 0; i < playersCount; i++)
			{
				cout << "____Player " << i + 1 << "____" << endl;
				cout << "Your character: " << characters[players[i].selectedCharacterIndex] << endl;
				cout << "Your score: " << players[i].scorePoints<< endl;
				cout << "Your level: " << players[i].level << endl << endl;
			}
			break;
		}
		case 3:
		{
			cout << "____METAL SLUG X____" << endl << endl;
			cout << "____LEADERBOARD____" << endl << endl;
			cout << "Sorry =( This option is unavailable."<<endl;
			break;
		}
		case 4:
		{
			cout << endl << "Thanks for playing Metal Slug X" << endl;
			cout << "See ya!!" << endl;
			break;
		}
		default:
			cout << endl;
			cout << "*********************************" << endl;
			cout << "The option " << menuOption << " is not valid." << endl;
			cout << "Please, enter a valid option." << endl;
			cout << "*********************************" << endl;
			break;
		}

		cout << endl << "Press any key to continue." << endl;
		cin.get();
		cin.ignore();
	} while (menuOption != 4);



}


