//Description: Performs number operations as many times as required
//Programmers: Emmanuel Valdueza, Jake P Ogsimer, Mark L Perez
//Created: Oct-02-2019 | Oct-08-2019

#include <iostream>
#include <limits> //library for handling cin unwanted input
#include <string>

using std::cin; //prevents identifier naming conflicts
using std::cout;
using std::string;

string operationAsked;
bool invalidOp = true, repeatedOperation = false;
double secondNum, result, firstNum;

string changeWords(string operation);
double calculate(string operation, double first, double second);
void promptToExit();
bool isItAValidOperation(string op);
bool isItAValidNumber(bool yesNo);
double askNumber(bool);
void showResults();
void welcomeMessage();
void askOperation(bool repeatedOpera);
void display();

int main()
{
	display();
	do
	{
		if (!repeatedOperation)
		{
			welcomeMessage();
			firstNum = askNumber(repeatedOperation);
			askOperation(repeatedOperation);
		}

		secondNum = askNumber(true);
		result = calculate(operationAsked, firstNum, secondNum);

		showResults();
		promptToExit();

		cin >> operationAsked;
		if (isItAValidOperation(operationAsked))
		{
			firstNum = result;
			repeatedOperation = true;
		}
		else
		{
			cout << "\n\n\n# You chose to exit the program. #\n\n\n\n";
			repeatedOperation = false;
		}
	} while (repeatedOperation);

	system("pause");
	return 0;
}

void display()
{
	system("CLS");
	cout << "\n##                                                                   ## "
			 << "\n# This program will perform one or more calculations as required  #"
			 << "\n##                                                                   ##"
			 << "\n"
			 << "\nLeft Hand Number: _"
			 << "\nOperation Symbol: _"
			 << "\nRight Hand Number: _"
			 << "\nResult: _"
			 << "\n"
			 << "\nEnter Left Hand Number: ";
}

void welcomeMessage()
{
	cout << "\nThis program will perform one or more "
			 << "operations as required. \n\n";
}

void askOperation(bool repeatedOpera)
{
	if (!repeatedOpera)
	{
		do
		{
			cout << "Type +, -, * or /: ";
			cin >> operationAsked;
			if (!isItAValidOperation(operationAsked))
				cout << "Please ";
		} while (!isItAValidOperation(operationAsked));
	}
}

void showResults()
{
	cout << "\n    Result: "
			 << firstNum << " "
			 << operationAsked << " "
			 << secondNum << " = "
			 << result << "\n";
}

double askNumber(bool repeatedOpera)
{
	double num;
	do
	{
		if (repeatedOpera)
		{
			cout << "\nEnter number "
					 << changeWords(operationAsked)
					 << firstNum << ": ";
		}
		else
			cout << "\nEnter number: ";
		cin >> num;
	} while (!isItAValidNumber(cin.fail()));
	return num;
}

double calculate(string operation, double first, double second)
{
	if (operation == "+")
		return first + second;
	if (operation == "-")
		return first - second;
	if (operation == "*")
		return first * second;
	if (operation == "/")
		return first / second;

	return 0;
}

bool isItAValidOperation(string op)
{
	if (op == "+" || op == "-" || op == "*" || op == "/")
		return true;
	else
	{
		return false;
	}
}

string changeWords(string operation)
{
	if (operation == "+")
		return "to add to ";
	if (operation == "-")
		return "to subtract from ";
	if (operation == "*")
		return "to multiply with ";
	if (operation == "/")
		return "to divide ";

	return ""; //will never reach
}

void promptToExit()
{
	cout << "\nType any of the ff operations."
			 << "\nInvalid input will exit program."
			 << "\n+, -, *, /:";
}

bool isItAValidNumber(bool yesNo)
{
	if (yesNo)
	{
		cin.clear(); //resets cin.fail() to false
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		/*
      cin.ignore() clears the characters that would make 
			cin.fail() true where the first argument indicates no
			limit to the number of characters to ignore and the
			second argument the character from which to stop ignoring
      which is the character for enter.
    */
		cout << "Invalid input. ";
		return false;
	}
	else
	{
		/*
      Discards extra input.
      If user types in numbers then letters, the
      letters and everything after will be discarded.
    */
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return true;
	}
}