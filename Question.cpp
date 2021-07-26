// File Name: Question.cpp
// Author: Jyotsna Shahi
// File to create the member functions for the class Question.

#include <iostream>
#include <iomanip>
#include "Question.h"
using namespace std;

//*********************************************************************
// Question: Empty Constructor
//
// stem: Variable to store the question from the text file, initalized as an empty string
// key: Variable to store the correct answer for each question, initalized as X
//**********************************************************************

Question::Question()
{
	stem = "";
	key = 'X';
}

//*********************************************************************
// Question: Constructor with its three components
// 
// stem: Variable to store the question from the text file, 
// initalized as an empty string
// key: Variable to store the correct answer for each question, initalized as X
// answers: Variable to store mutiple choice answers
//**********************************************************************

Question::Question(string q, string a[], char k)
{
	stem = q;
	key = k;
	for(int i = 0; i < 4; i++)
	{
		answers[i] = a[i];
	}
}

//*********************************************************************
// getStem: Funtion that returns the stem question
// 
// stem: Variable to store the question from the text file, 
// Returns the stem question
//**********************************************************************

string Question::getStem()
{
	return stem;
}

//*********************************************************************
// getAnswer: Funtion that returns the multiple choice answers
// 
// answers: Variable to store mutiple choice answers
// Returns the answers
//**********************************************************************

string Question::getAnswer(int i)
{
	return answers[i];
}

//*********************************************************************
// getKey: Funtion that sets the key letter
// 
// Returns the key
//**********************************************************************

char Question::getKey()
{
	return key;
}

//*********************************************************************
// ask: Funtion that Compose the stem and answers each on a separate line, as a string
// options: Variable that appends letters A to D to each answer
// Returns the formatted string
//**********************************************************************

string Question::ask()
{	
	string options = stem;
	string choices[] = {"A","B","C","D"};
	for (int i = 0; i < 4 ; i++)
	{
		options += "\n"+choices[i]+". " + answers[i];
	}
	return options;
}

//*********************************************************************
// setStem: Function that sets the stem question
//**********************************************************************

void Question::setStem(string q)
{
	stem = q;
}

//*********************************************************************
// setAnswers: Function that sets the 4 answers given in an array.
//**********************************************************************

void Question::setAnswers(string ans[])
{
	for(int i = 0; i < 4; i++)
	{
		answers[i] = ans[i];

	}
}

//*********************************************************************
// setKey: Function that sets the key letter
//**********************************************************************

void Question::setKey(char k)
{
	key = k;
}

//*********************************************************************
// swapAnswers: Function that swaps two answers and updates the key
// index1, index2: Used to convert a and b into range from 0 to 3
// keys: An array of values from A to D
// keyindex: Stores the index of the correct key
// temp: Temporary variable used to swap the two answers
//**********************************************************************

void Question::swapAnswers(int a, int b)
{
	int index1 = a%4;
	int index2 = b%4;
	char keys[] = {'A','B','C','D'};
	int keyindex = -1;
	if(index1 != index2)
	{
		for (int i = 0; i < 4; i++)
		{
			if (key==keys[i])
				keyindex = i;
		}
		for (int j = 0; j < 4;j++)
		{
			if (keyindex == index1)
				key = keys[index2];
			else if (keyindex == index2)
				key = keys[index1];
		}
		string temp = answers[index1];
		answers[index1] = answers[index2];
		answers[index2] = temp;
	}
}