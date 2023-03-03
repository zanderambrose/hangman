#include <iostream>

class Game{
	public:
		void getNumberOfGuesses(){
			std::string userInputGuesses;
			std::cout << "How many guesses would you like to have? " << std::flush;
			std::getline(std::cin,userInputGuesses);
	    	int convertedUserInput = std::stoi(userInputGuesses);
			this->setTotalGuesses(convertedUserInput);
		} 
		void setTotalGuesses(int guesses){
			this->totalGuesses = guesses;
		}
		std::string getTotalGuesses(){
			std::cout << "TO STRING: " << std::to_string(this->totalGuesses) << std::endl;
			return std::to_string(this->totalGuesses);
		}

	private:
		int totalGuesses;

};

class Word{
	public:
		std::string randomWord = "hello world";
};

int main(){
	Game hangman;
	hangman.getNumberOfGuesses();
	hangman.getTotalGuesses();
	return 0;
}
