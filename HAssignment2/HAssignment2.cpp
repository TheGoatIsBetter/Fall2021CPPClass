#include <iostream>
#include <stdlib.h>
#include "functions.h"

using namespace std;

int persuasion = 0;


int main() {



	//I can't figure out how to make these multiple lines without breaking things and keeping it a function...  I can't use << and I can't just cut it either...
	confirmationText("This is essentially a tested questionairre.\nThing is, it's near-impossible to tell the correct answers.\nI asked people of different varieties of specific expertises\n for their opinions on what is the best of their expertises is.\nI then made this with that information.\n\n");
	confirmationText("In a world brimming with the hope of new adventures, as a student,\n you often don't find many, but you find yourself in one particular adventure.\nSmall, but there.  You find yourself wanting candy.\nIt just so happens that your current professor has offered a\n candy bar to the student who can answer all of his random questions.\nSo you decide to take him on.  His first question is as follows...\n\n");


	//cheese
	Question("What is my favorite cheese.",
		"Havarti",
		"Blue Cheese",
		"Swiss");
	ChoiceDesignation(getChoice(1, 3),
		1, "Hmmm, not too far off.  Havarti is GOOD when it's good, but it isn't the best of the best.",
		3, "YES, AMAZING, OUTSTANDING. BLUE CHEESE IS THE BEST!",
		-1, "What. No.");

	//philosopher
	Question("Okay, next question.\n Which philosopher is my favorite?",
		"Charles Bukowski",
		"Albert Camus",
		"Mohandas Karamchand Gandhi");
	ChoiceDesignation(getChoice(1, 3),
		2, "Great choice.",
		1, "Gonna have to say you got good taste.",
		0, "Understandable, but he wasn't perfect.");

	//game ost
	Question("Okay, next question.\n Which of the following standalone games has the best soundtrack?",
		"Persona 5 Royal",
		"Final Fantasy 7 Remake",
		"Enter the Gungeon");
	ChoiceDesignation(getChoice(1, 3),
		3, "YES. YES. YES.",
		2, "Perfectly remastered a masterpiece.",
		-1, "I can't even remember a single track from Gungeon...");

	//nerf gun
	Question("Okay, next question.\n Which of the following Nerf guns is the best?",
		"Atom Blaster",
		"Spectrum",
		"Nexus Pro");
	ChoiceDesignation(getChoice(1, 3),
		-5, "WHAT THE... IT LITERALLY JUST FLICKS THEM THOUGH?!?!",
		2, "Really fun, great choice.",
		3, "Hell yeah, definitely the best bang for your buck.");

	//camera brand
	Question("Okay, next question.\n Which of the following camera brands is my favorite?",
		"Leica",
		"Canon",
		"Fujifilm");
	ChoiceDesignation(getChoice(1, 3),
		-3, "No, waaayyyy too expensive for an alright camera.",
		4, "Really good quality, best price, definitely the best you got.",
		0, "Good, but you can get similar quality with a top-end Canon or Nikon for the same price.");

	//finale (figure out what ending you got and do it)
	FinaleChoice("I wanted to give you the candy, I wanted you to do well, yet you somehow did so bad I really can't even give you half a candy bar...",
		"That was brilliant, you got every single question perfectly right.  You aren't reading my mind are you?  Here's a candy bar!",
		"Eh, not perfect, but not too bad.  Here's half of a candy bar, you did well.");

	return 0;
}