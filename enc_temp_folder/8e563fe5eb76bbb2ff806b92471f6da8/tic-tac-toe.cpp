// tic-tac-toe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <algorithm>

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

	void changeBoard(std::string x[3][3], std::string new_location, std::string player)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (x[i][j] == new_location)
				{
					x[i][j] = player == "player" ? "X" : "O";
					break;
				}
			}
		}
	}

	void deleteBoardPosition(std::vector<std::string>& boardPosition, std::string position) {
		boardPosition.erase(std::remove(boardPosition.begin(), boardPosition.end(), position), boardPosition.end());
	}

	bool checkBoardPosition(std::vector<std::string>& boardPosition, std::string position) {
		bool answer = std::find(boardPosition.begin(), boardPosition.end(), position) != boardPosition.end();
		cout << answer << endl;
		return  std::find(boardPosition.begin(), boardPosition.end(), position) != boardPosition.end();
	}
};

// 1. Make a random choice for computer
// 2. Ended the game

std::string computerGenerator(std::vector<std::string> boardPosition) {
	std::srand(std::time(0));

	int randomIndex = std::rand() % boardPosition.size();

	return boardPosition[randomIndex];

}

template <typename T>
void Print(T variable) {
	cout << variable << endl;
}


int main()
{
	std::string x[3][3] = {
		{"A1", "A2", "A3"},
		{"B1", "B2", "B3"},
		{"C1", "C2", "C3"}
	};

	// 1. Tell user welcome to tictactoe game
	Print("Welcome to the Meow-Tac-Toe!");
	Print("Instruction:");
	Print("1. Type the location that you wish to put your position");
	Print("2. You will play as X");
	Print("3. Have fun!");

	bool still_playing = true;
	std::string player_still_playing;

	std::vector<std::string> boardPosition = { "A1", "A2", "A3", "B1", "B2", "B3", "C1", "C2", "C3" };
	std::string player_move;
	while (still_playing) 
	{
		Print("");
		Board board;
		board.printBoard(x);

		std::cout << "Your move: ";
		std::cin >> player_move;
		while (!board.checkBoardPosition(boardPosition, player_move)) {
			Print("Illegal position. Try again!");
			cout << "Your move: " << endl;
			std::cin >> player_move;
		}
		board.changeBoard(x, player_move, "player");
		board.deleteBoardPosition(boardPosition, player_move);

		std::string computer_move = computerGenerator(boardPosition);
		board.changeBoard(x, computer_move, "computer");
		board.deleteBoardPosition(boardPosition, computer_move);

		for (int i = 0; i < boardPosition.size(); i++) {
			cout << boardPosition[i] << endl;
		}
		cout << endl;
	}
	return 0;
}