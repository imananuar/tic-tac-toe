// tic-tac-toe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

template<typename T>
int size(T& variable)
{
	return sizeof(variable) / sizeof(variable[0][0]);
}

class Board
{
public:
	void printBoard(std::string x[3][3]) const
	{
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				cout << x[i][j];
				if (j != 2) {
					cout << " | ";
				}
				else {
					cout << endl;
					cout << "------------" << endl;
				}
			}
		}
	}

	void changeBoard(std::string x[3][3], std::string new_location)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (x[i][j] == new_location)
				{
					x[i][j] = " X";
					break;
				}
			}
		}
	}
};


int main()
{
	std::string x[3][3] = {
		{"A1", "A2", "A3"},
		{"B1", "B2", "B3"},
		{"C1", "C2", "C3"}
	};
	// 1. Tell user welcome to tictactoe game
	cout << "Welcome to the Tic Tac Toe Game!" << endl;
	cout << "You will play: X" << endl;

	bool still_playing = true;
	std::string player_still_playing;

	while (still_playing) 
	{
		Board board;
		board.printBoard(x);
		std::string player_move;

		cout << "Its your move. Type the location that you wish to put your 'X'" << endl;
		std::cin >> player_move;
		board.changeBoard(x, player_move);

		std::cin >> player_still_playing;
		if (player_still_playing != "f")
		{
			still_playing = false;
		}

	}
	return 0;
}