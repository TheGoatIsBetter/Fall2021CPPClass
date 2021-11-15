#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;


int main() {
	// Display Title of the program to the user
	cout << "This is the Keywords II Course" << endl;

	// Ask the recruit to log in using their name
	cout << "Please log in using your name" << endl;

	// Hold the recruit's name in a var, and address them by it throughout the simulation.
	string name;
	cin >> name;
	cout << endl;


	//not sure about how to go about this other than like this.  The directions didn't ever say the random words had to be unique, just a new set,
	//  so I didn't really do much to prevent such
	// Display an overview of what Keywords II is to the recruit 
	cout << "Hello, you are basically just gonna be playing a game of hangman with 3 words randomized from an array of 10 existing words." << endl;
	// Display directions to the recruit on how to use Keywords
	cout << "Note that duplicates may occur, though that just makes your job easier." << endl;


	// Create a collection of 10 words you had written down manually
	const char* words[10] = { "Caliburn", "Durendal", "Gram", "Muramasa", "Arondight", "Ascalon", "Galatine", "Masamune", "Falchion", "Zangetsu" };

	// Create an int var to count the number of simulations being run starting at 1
	int simcount = 1;

	while (true) {
		// Display the simulation # is starting to the recruit. 
		cout << "Simulation #" << simcount << endl;

		// Pick new 3 random words from your collection as the secret code word the recruit has to guess. 
		srand((int)time(NULL));
		string guessWord = (string)words[rand() % 10] + (string)words[rand() % 10] + (string)words[rand() % 10];

		// While recruit hasn’t made too many incorrect guesses and hasn’t guessed the secret word
		int incorrectLeft = 3;
		bool guessed = false;
		vector<char> guessedLetters;
		string currentGuessed;
		while (incorrectLeft > 0 && guessed == false) {

			//     Tell recruit how many incorrect guesses he or she has left
			cout << "You have  " << incorrectLeft << " incorrect guesses left." << endl;

			//     Show recruit the letters he or she has guessed
			cout << "Guessed letters:" << endl;
			for (int i = 0; i < (int)guessedLetters.size(); i++) {
				cout << guessedLetters[i] << " ";
			}

			//     Show player how much of the secret word he or she has guessed
			cout << endl << "Current Code Word:" << endl;
			cout << currentGuessed << endl;


			//     Get recruit's next guess
			//     While recruit has entered a letter that he or she has already guessed
			//          Get recruit ’s guess
				//there is definitely a better way of doing this I'm too tired to remember right now...
			char guess;
			bool guessSame = true;
			while (guessSame == true) {
				cout << "\n\nWhat is your next guess " << name << "?" << endl;
				cin >> guess;
				guessSame = false;
				for (int i = 0; i < (int)guessedLetters.size(); i++) {
					if (guess == guessedLetters[i]) {
						guessSame = true;
						break;
					}
				}
			}


			//     Add the new guess to the group of used letters
			guessedLetters.push_back(guess);

			//     If the guess is in the secret word
			bool isGuessInWord = false;
			for (int i = 0; i < (int)guessWord.size(); i++) {
				if (guess == guessWord[i]) {
					isGuessInWord = true;
				}
			}

			if (isGuessInWord) {
				//          Tell the recruit the guess is correct
				cout << "Your guess is correct." << endl;
				currentGuessed = "";

				//          Update the word guessed so far with the new letter
				for (int i = 0; i < (int)guessWord.size(); i++) {
					for (int j = 0; j < (int)guessedLetters.size(); j++) {
						if (guessedLetters[j] == guessWord[i]) {
							currentGuessed += guessedLetters[j];

						}

					}
				}
			}
			//     Otherwise
			else {
				//          Tell the recruit the guess is incorrect
				cout << "Your guess is incorrect." << endl;
				//          Decrement the number of incorrect guesses the recruit has made
				incorrectLeft -= 1;
			}

			if (currentGuessed == guessWord) {
				guessed = true;
			}
		}

		// If the recruit has made too many incorrect guesses
		if (guessed == false) {
			//     Tell the recruit that he or she has failed the Keywords II course.
			cout << "You have failed the course..." << endl;
		}
		// Otherwise
		else {
			//     Congratulate the recruit on guessing the secret words
			cout << "You have successfully completed the course, good job " << name << "!" << endl;
		}

		// Ask the recruit if they would like to run the simulation again
		char tryAgain = 'f';
		while (tryAgain != 'y' && tryAgain != 'n') {
			cout << "Would you like to try again? \ny/n" << endl;
			cin >> tryAgain;
		}

		// If the recruit wants to run the simulation again
		if (tryAgain == 'y') {
			//     Increment the number of simulations ran counter
			simcount++;
			//     Move program execution back up to // Display the simulation # is starting to the recruit.
				//will run to loop back
		}
		// Otherwise 
		else {
			//     Display End of Simulations to the recruit
			cout << "The simulation has ended, please exit the program." << endl;
			break;
		}
	}

	//     Pause the Simulation with press any key to continue
	//uses name because that exists already and it doesn't matter since it's at the end
	cin >> name;

	return 0;
}