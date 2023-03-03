#include <iostream>
#include <vector>
#include <fstream>

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
		std::vector<std::string> randomWordVector;
		std::ifstream file("randomwords.txt");
		std::string word;
		while (std::getline(file, word))
			randomWordVector.push_back(word);

		srand(time(0));
		int randomNumber = 1 + (rand() % randomWordVector.size());
		this->randomWord = randomWordVector[randomNumber];
	}

	bool guessLetter(char letter)
	{
		return true;
	}

	void printWordStatus()
	{
		std::cout << this->randomWord << std::endl;
	}

private:
	std::string randomWord;
};

int main()
{
	Game hangman;
	Word word;

	// hangman.printGameStatus();
	word.printWordStatus();
	return 0;
}
