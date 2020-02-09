// World Jumble 
// The classic word jumble game where the player can ask for a hint
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()

{
	//play again

	bool playAgain = false;

	//For play again

	char usersPlayAgainChoice;

	cout << "\t\t\tWelcome to Word Jumble!\n\n";

	cout << "Unscramble the letters to make a word.\n";

	cout << "Enter 'hint' for a hint.\n";

	cout << "Enter 'quit' to quit the game.\n\n";
	for (int i = 0; i < 3; i++)
	{
		cout << "\nWelcome to round " << i + 1 << " of 3.\n\n";
	}


	do {

		for (int i = 0; i < 3; i++) {

			//Words and hints

			enum fields { WORD, HINT, NUM_FIELDS };
			const int NUM_WORDS = 10;
			const string WORDS[NUM_WORDS][NUM_FIELDS] =

			{

			{	"return", "Ends the code."} ,
	{"false", "Something that is not right."} ,
	{"bool", "It can be true or false depending on the value of i."},
	{"Try", "one word for attempting to do something."} ,
		{"jumble", "It's what the game is all about."}

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

		}



		cout << "Would you like to play again? (Y/N)" << endl;

		cin >> usersPlayAgainChoice;

		//user input to keep playing

		if (usersPlayAgainChoice == 'y' || usersPlayAgainChoice == 'Y')

		{

			playAgain = true;

		}

		else

		{

			playAgain = false;

		}

		//get out of loop

	} while (playAgain = true);



	cout << "\nThanks for playing.\n";



	return 0;

}