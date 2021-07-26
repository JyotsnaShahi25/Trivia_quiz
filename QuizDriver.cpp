// File Name: QuestionDriver.cpp
// Author: Jyotsna Shahi
// Driver to run the main program.

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "Question.h"
using namespace std;

//*********************************************************************
// readQuestionFile: Reads the text file and stores it in an Array.
//
// string stem: Variable to store the question from the text file 
// string answers[]: Variable to store mutiple choice answers
// char key: Variable to store the correct answer for each question 
// string line: Variable to store each line read from the text file
//**********************************************************************

void readQuestionFile(Question questions[], int &size)
{	
	string stem;
	string answers[4];
	char key;
	std::ifstream file("questions.txt");	
	if (file.is_open())
	{
		string line;
		while (std::getline(file, line)) 
		{
			if (line == "") continue;
			stem = line; // Extract and store the questions from text file
			for (int i=0;i<4;i++)
			{
				std::getline(file, answers[i]); // Extract all the options
			}
    	 	file>>key; // Extract and save the key
    	 	std::getline(file, line);
    	 	questions[size].setStem(stem);
    	 	questions[size].setAnswers(answers);
    	 	questions[size].setKey(key);
    	 	questions[size].swapAnswers(0,1);
    	 	questions[size].swapAnswers(2,3);
    	 	size++;
    	}
    file.close();
	}
}

//*********************************************************************
// calculateUserScore: Reads the array of question object, displays the quiz
// and calculates user score based on user input
//
// char userInput: Variable to store the user's answer for each question 
// int userScore: Variable to store the score based on the number of correct answers
//**********************************************************************

void calculateUserScore(Question questions[], int size)
{	
	char userInput;
	int userScore = 0;
	for (int i=0;i<size;i++)
	{
		cout<<(i + 1)<<". ";
		cout<<questions[i].ask();
		cout<<endl;
		cout<<"Your answer (enter the letter): ";
		cin>>userInput;
		cout<<endl;
		if(std::toupper(userInput) == questions[i].getKey())
			userScore++;
	}
	cout<<"Answers: "<<endl;
	for(int i = 0; i < size; i++)
		cout<<questions[i].getKey()<<" ";
	cout<<endl;
	cout<<endl;
	cout<<"Your score out of "<<size<<": "<<userScore <<endl;
}

int main()
{
	Question questions[5];
	int size = 0;
	readQuestionFile(questions,size);
	calculateUserScore(questions,size);
	return 0;
}