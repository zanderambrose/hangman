#include <iostream>

class Game
{
public:
	void getNumberOfGuessesFromUser()
	{
		std::string userInputGuesses;
		std::cout << "How many guesses would you like to have? " << std::flush;
		std::getline(std::cin, userInputGuesses);
		this->setTotalGuesses(userInputGuesses);
	}

	void setTotalGuesses(std::string guesses)
	{
		if (this->isTotalGuessesInitialized == false)
		{
			int convertedUserInput = std::stoi(guesses);
			this->totalGuesses = convertedUserInput;
			this->isTotalGuessesInitialized = true;
		}
	}

	void setTotalGuesses(int guesses)
	{
		if (this->totalGuesses > 0)
		{
			std::cout << "just checking" << std::endl;
			this->totalGuesses -= guesses;
		}
	}

	std::string getTotalGuesses()
	{
		std::cout << "TO STRING: " << std::to_string(this->totalGuesses) << std::endl;
		return std::to_string(this->totalGuesses);
	}

private:
	int totalGuesses;
	bool isTotalGuessesInitialized = false;
};

class Word
{
public:
	std::string randomWord = "hello world";
};

class Guess
{
};

int main()
{
	Game hangman;
	hangman.getNumberOfGuessesFromUser();
	hangman.getTotalGuesses();
	return 0;
}
