#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

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

	bool guessLetter()
	{
		std::vector<size_t> indexVector;
		std::cout << "Select a letter: ";
		std::string guessedLetter;
		std::getline(std::cin, guessedLetter);
		if (guessedLetter.size() > 1)
		{
			std::cout << "You can only guess one letter!  Try again." << std::endl;
			this->guessLetter();
		}
		if (std::find(guessedLettersVector.begin(), guessedLettersVector.end(), guessedLetter) != guessedLettersVector.end())
		{
			std::cout << "You have already guessed this letter!  Tru again." << std::endl;
			this->guessLetter();
		}
		else
		{
			size_t position = this->randomWord.find(guessedLetter);
			while (position != std::string::npos)
			{
				indexVector.push_back(position);
				this->randomWord.find(guessedLetter, position + 1);
			}
		}
		if (indexVector.empty())
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	void printWordStatus()
	{
		std::cout << this->randomWord << std::endl;
	}

private:
	std::string randomWord;
	std::vector<std::string> guessedLettersVector;
};

class Game
{
public:
	void run()
	{
		std::cout << "Welcome to hangman!  You will have 10 guesses to find our word! Good luck!" << std::endl;
		while (incorrectGuesses < 10)
		{
			this->printGuessesLeft();
			bool isCorrectGuess = this->word.guessLetter();
			if (isCorrectGuess)
			{
				continue;
			}
			else
			{
				this->incorrectGuesses++;
			}
		}
		std::cout << "You lose!" << std::endl;
	}

private:
	Word word;
	int incorrectGuesses = 0;
	std::vector<std::string> display{"  | ", "  | ", " [ ", "]", "  | ", "-- ", "-- ", "  | ", " /", " \\"};
	void printGameStatus()
	{
		for (int i = 0; i < this->incorrectGuesses; i++)
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
		std::cout << "Guesses left: " << (10 - this->incorrectGuesses) << std::endl;
	}
};

int main()
{
	Game hangman;
	hangman.run();
	return 0;
}
