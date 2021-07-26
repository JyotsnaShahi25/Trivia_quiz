// File Name: Question.h
// Author: Jyotsna Shahi
// Header file that declares the class Question


#include <iostream>
#include <string>
using namespace std;

class Question
{
	private:
		string stem;
		string answers[4];
		char key;
	public:
		Question();
		Question(string, string[], char);
		void setStem(string);
		string getStem();
		void setAnswers(string[]);
		string getAnswer(int);
		void setKey(char);
		char getKey();
		void swapAnswers(int,int);
		string ask();
};