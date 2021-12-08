#pragma once

#include <string>
using std::string;
extern int persuasion;


//function prototypes go here
int dummy();
int getChoice(int min, int max);
void ChoiceDesignation(int choice, int val0, string str0, int val1, string str1, int val2, string str2);
void Question(string question, string a0, string a1, string a2);
void FinaleChoice(string worst, string best, string middle);
void confirmationText(string text);