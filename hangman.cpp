#include <iostream>
#include <vector>
#include <fstream>

class Game
{
public:
	void run()
	{
		std::cout << "Welcome to hangman!  You will have 10 guesses to find our word! Good luck!" << std::endl;
		while (guessesLeft > 0)
		{
			this->printGameStatus();
			this->printGuessesLeft();
			this->guessesLeft--;
		}
	}

private:
	int guessesLeft = 10;
	bool isTotalGuessesInitialized = false;
	std::vector<std::string> display{"  | ", "  | ", " [ ", "]", "  | ", "-- ", "-- ", "  | ", " /", " \\"};
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
	void printGuessesLeft()
	{
		std::cout << "Guesses left: " << this->guessesLeft << std::endl;
	}
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

	hangman.run();
	// word.printWordStatus();
	return 0;
}
