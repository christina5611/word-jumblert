// World Jumble 
// The classic word jumble game where the player can ask for a hint
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()

{
	cout << "\t\t\tWelcome to Word Jumble!\n\n";
	cout << "Unscramble the letters to make a word.\n";
	bool playAgain = false;


	bool usersPlayAgainChoice;
	// make user do 3 rounds for 1 game
	for (int i = 0; i < 3; ++i)
	{
		cout << "\nWelcome to round " << i + 1 << " of 3.\n\n";
	}

	enum fields { Word, Hint, Num_Fields };
	const int Num_Words = 5;
	const string Words[Num_Words][Num_Fields] =
	{
		{	"return", "Ends the code."} ,
	{"false", "Something that is not right."} ,
	{"bool", "It can be true or false depending on the value of i."},
	{"Try", "one word for attempting to do something."} ,
		{"jumble", "It's what the game is all about."}
	};
	srand(static_cast<unsigned int>(time(0)));
	int choice = (rand() % Num_Words);
	string theWord = Words[choice][Word];
	//word to guess
	string theHint = Words[choice][Hint];
	//hint for word

	string jumble = theWord;
	//jumbled version of word
	int length = jumble.size();
	for (int i = 0; i < length; ++i)
	{
		int index1 = (rand() % length);
		int index2 = (rand() % length);
		char temp = jumble[index1];
		jumble[index1] = jumble[index2];
		jumble[index2] = temp;
	}

	cout << "Enter 'hint' for a hint.\n";
	cout << "Enter 'quit' to quit the game.\n\n";
	cout << "The jumble is: " << jumble;

	string guess;
	cout << "\n\nYour guess: ";
	cin >> guess;

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
		cout << "\n\nYour guess:";
		cin >> guess;
	}
	if (guess == theWord)
	{
		cout << "\nThat's it! You guessed it!\n";
	}


	cout << "\nYou have completed 3 rounds and the game is over!\n";
	cout << "\nWould you like to play again? (y/n) ";
	cin >> usersPlayAgainChoice;

	while (usersPlayAgainChoice == 'y' || usersPlayAgainChoice == 'y');


		cout << "\nThanks for playing. \n";
		return 0;
	
}

