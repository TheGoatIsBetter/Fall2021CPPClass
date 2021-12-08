#include <iostream>
#include <stdlib.h>
#include "functions.h"

using namespace std;

//dummy function for debugging purposes, I'm leaving it because I wanna
int dummy() {
	printf("hello");
	return 0;
}

//asks the player to make a choice.
int getChoice(int min, int max) {
	int choice;

	cout << "\nWhich is it?" << endl;
	cin >> choice;

	//if not valid, then recursively ask.
	if (choice < min || choice > max) {
		choice = getChoice(min, max);
	}

	return choice;
}

//adds to the persuasion counter, and gives responses for each choice
void ChoiceDesignation(int choice, int val0, string str0, int val1, string str1, int val2, string str2) {
	choice -= 1; //humanize the choice

	switch (choice) {
	case 0:
		persuasion += val0;
		cout << str0 << endl;
		break;
	case 1:
		persuasion += val1;
		cout << str1 << endl;
		break;
	case 2:
		persuasion += val2;
		cout << str2 << endl;
		break;
	}
}

//asks a quesiton and displays the possible answers.  Mostly just to get rid of messiness when this wasn't a function
void Question(string question, string a0, string a1, string a2) {
	cout << question << endl;
	cout << "	1. " << a0 << endl;
	cout << "	2. " << a1 << endl;
	cout << "	3. " << a2 << endl;
}

//Just sorts through and figures out which ending should be printed and prints it.  Nothing special, more for unification
void FinaleChoice(string worst, string best, string middle) {
	if (persuasion == 15) {
		cout << best;
	}
	else if (persuasion > 0) {
		cout << middle;
	}
	else {
		cout << worst;
	}
}

//loop until confirmation
void confirmationText(string text) {
	string inputconf = "";
	while (true) {
		cout << text;
		cout << "\nDid you get all that?\n Type 'y' or 'yes' for confirmation\n" << endl;
		cin >> inputconf;

		//if the input was true then break from the infinite loop
		if (inputconf == "y" || inputconf == "yes")
			break;
	}
}