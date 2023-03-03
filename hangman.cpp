#include <iostream>


class Game{
	public:
		int totalGuesses;
		Game(int numberOfGuesses){
			totalGuesses = numberOfGuesses;
		}
};

int main(){
	std::string userInputGuesses;
	std::cout << "How many guesses would you like to have? " << std::flush;
	std::getline(std::cin,userInputGuesses);
	int convertedUserInput = std::stoi(userInputGuesses);
	Game hangman(convertedUserInput );
	std::cout << hangman.totalGuesses << std::endl;
	return 0;
}
