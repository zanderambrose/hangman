#include <iostream>

class Game {
	public:
		void getNumberOfGuessesFromUser(){
			std::string userInputGuesses;
			std::cout << "How many guesses would you like to have? " << std::flush;
			std::getline(std::cin,userInputGuesses);
	    	int convertedUserInput = std::stoi(userInputGuesses);
			this->setTotalGuesses(convertedUserInput);
		} 
		void setTotalGuesses(int guesses){
            this->totalGuesses -= guesses;
			if(this->totalGuesses > 0){
			}
		}
		std::string getTotalGuesses(){
			std::cout << "TO STRING: " << std::to_string(this->totalGuesses) << std::endl;
			return std::to_string(this->totalGuesses);
		}

	private:
		int totalGuesses;

};

class Word {
	public:
		std::string randomWord = "hello world";
};

class Guess {

};

int main(){
	Game hangman;
	hangman.getNumberOfGuessesFromUser();
	hangman.getTotalGuesses();
	return 0;
}
