#include <iostream>
#include <vector>

class Game
{
public:
	void printGameStatus()
	{
		for (int i = 0; i < this->display.size(); i++)
		{
			if (i != 2 && i != 5 && i != 8)
			{
				std::cout << this->display[i] << std::endl;
			}
			else
			{
				std::cout << this->display[i];
			}
		}
	}

private:
	int totalGuesses;
	bool isTotalGuessesInitialized = false;
	std::vector<std::string> display{"  | ", "  | ", " [ ", "]", "  | ", "-- ", "-- ", "  | ", " /", " \\"};
};

class Word
{
public:
	Word()
	{
		this->randomWord = "hello random";
	}
	bool guessLetter(char letter)
	{
		return true;
	}
	void printWordStatus()
	{
		std::cout << "Word Status" << std::endl;
	}

private:
	std::string randomWord;
};

int main()
{
	Game hangman;
	hangman.printGameStatus();
	return 0;
}
