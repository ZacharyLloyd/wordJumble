//Word Jumble
//Classic word jumble where player can ask for a hint
//Allows input and output
#include <iostream>
//Allows the use of strings
#include <string>
//Includes functions involving memory allocation, process control, conversions and others
#include <cstdlib>
//Needed for random numbers
#include <ctime>
//Shortcut allowing me to declare this once instead of every function that uses it
using namespace std;

int main()
{
	//This is the switch to play the game again or not
	bool playAgain = false;

	do {
		//Words and hints
		enum fields { WORD, HINT, NUM_FIELDS };
		const int NUM_WORDS = 10;
		const string WORDS[NUM_WORDS][NUM_FIELDS] =
		{
			{"secret", "Classified information"},
			{"computer", "Terminal for information"},
			{"agent", "This is you!"},
			{"criminal", "The bad guy"},
			{"drop", "Package exchange."},
			{"operation", "Work assignment."},
			{"mission", "Should you choose to accept this."},
			{"martini", "Alcoholic beverage of choice."},
			{"rifle", "Your primiary weapon."},
			{"knife", "Close quarters weapon."}

		};
		//Functions needed for jumble to happen
		srand(static_cast<unsigned int>(time(0)));
		int choice = (rand() % NUM_WORDS);
		string theWord = WORDS[choice][WORD];  // word to guess
		string theHint = WORDS[choice][HINT];  // hint for word

		string jumble = theWord;  //Jumbled version of word
		int length = jumble.size();
		//Loop for the game to jumble the words
		for (int i = 0; i < length; ++i)
		{
			int index1 = (rand() % length);
			int index2 = (rand() % length);
			char temp = jumble[index1];
			jumble[index1] = jumble[index2];
			jumble[index2] = temp;
		}

		cout << "\t\t\tWelcome to Word Jumble!\n\n";
		cout << "Unscramble the letters to make a word.\n";
		cout << "Enter 'hint' for a hint.\n";
		cout << "Enter 'quit' to quit the game.\n\n";
		cout << "The jumble is: " << jumble;
		//player's guess
		string guess;
		cout << "\n\nYour guess: ";
		cin >> guess;
		//guessing the word and asking for hints
		while ((guess != theWord) && (guess != "quit"))
		{
			if (guess == "hint")
			{
				cout << theHint;
			}
			else
			{
				cout << "Sorry, that's not it.";
			}

			cout << "\n\nYour guess: ";
			cin >> guess;
		}

		if (guess == theWord)
		{
			cout << "\nThat's it!  You guessed it!\n";
		}
		//For play again
		char userChoice;

		cout << "Would you like to play again? (Y/N)" << endl;
		cin >> userChoice;
		//user input to keep playing
		if (userChoice == 'y' || userChoice == 'Y')
		{
			playAgain = true;
		}
		else
		{
			playAgain = false;
		}
		//get out of loop
	} while (playAgain == true);

	cout << "\nThanks for playing.\n";

	return 0;
}