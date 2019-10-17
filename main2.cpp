//Title: A Simple Calculator
//Description: Performs number calculations as many times as required
//Programmers: Emmanuel Valdueza, Jake P Ogsimer, Mark L Perez
//Created: Oct-02-2019 | Oct-08-2019

#include <iostream>
#include <limits> //library to help handle cin unwanted input
#include <string>

using std::cin; //prevents namespace naming conflicts
using std::cout;
using std::string;

string userOperatorInput, savedOperator;
double secondNum, result, firstNum;

bool invalidOp = true, loopProgram = false;
bool displayFirstNum = false, displayOpera = false;
bool displaySecondNum = false, displayResultNum = false;

string changeWords(string operation); //changes sentence accordingly
double calculate(string operation, double first, double second);
bool isItAValidOperation(string op);
bool isItAValidNumber(bool yesNo);
double askNumber(bool); //returns a number if valid
void askOperation(bool repeatedOpera);
void refreshExitDisplay(); //asks user to exit or continue
void refreshDisplay();		 //changes what is displayed accordingly

int main()
{
	refreshDisplay();
	do
	{
		if (!loopProgram)
		{
			firstNum = askNumber(loopProgram);
			displayFirstNum = true;
			refreshDisplay();
			askOperation(loopProgram);
			displayOpera = true;
		}

		refreshDisplay();
		secondNum = askNumber(true);
		displaySecondNum = true;
		result = calculate(userOperatorInput, firstNum, secondNum);
		displayResultNum = true;

		refreshExitDisplay();

	} while (loopProgram);

	system("pause");
	return 0;
}

void refreshDisplay()
{
	system("CLS"); //clears a previous refreshDisplay()
	cout << "\n"
			 << "\n-- This program will perform one or more calculations as required --"
			 << "\n"
			 << "\n";

	cout << "\nLeft Hand Number: ";
	if (displayFirstNum)
		cout << firstNum;
	else
		cout << "_ ";

	cout << "\nOperation Symbol: ";
	if (displayOpera)
		cout << userOperatorInput;
	else
		cout << "_ ";

	cout << "\nRight Hand Number: ";
	if (displaySecondNum)
		cout << secondNum;
	else
		cout << "_ ";

	cout << "\nResult: ";
	if (displayResultNum)
		cout << result;
	else
		cout << "_ ";

	cout << "\n";
}

void refreshExitDisplay()
{
	bool loopExitPrompt = true;
	do
	{
		refreshDisplay();
		cout << "\n\nEnter +, -, *, /, Operation Symbol or any other character to EXIT: ";
		savedOperator = userOperatorInput; //we want to keep the operator during this loop
		cin >> userOperatorInput;
		if (isItAValidOperation(userOperatorInput))
		{
			firstNum = result;
			loopProgram = true;
			displaySecondNum = false;
			displayResultNum = false;
			loopExitPrompt = false;
		}
		else
		{
			string exitYesNo;
			cout << "Are you sure you want to exit? 'y' for yes, any characters for no. ";
			cin >> exitYesNo;
			if (exitYesNo == "y" || exitYesNo == "Y")
			{
				cout << "\n\n\n# You chose to exit the program. #\n\n\n\n";
				loopProgram = false;
				loopExitPrompt = false;
			}
			else
			{
				userOperatorInput = savedOperator;
				loopProgram = true;
			}
		}
	} while (loopExitPrompt);
}

void askOperation(bool repeatedOpera)
{
	bool passedOnce = false;
	if (!repeatedOpera)
	{
		do
		{
			if (!isItAValidOperation(userOperatorInput) && passedOnce)
				cout << "\n-- Invalid Input --\nEnter +, -, *, /, Operation Symbol:";
			else
				cout << "\n\nEnter +, -, *, /, Operation Symbol: ";
			cin >> userOperatorInput;
			passedOnce = true;
			refreshDisplay();
		} while (!isItAValidOperation(userOperatorInput));
	}
}

double askNumber(bool repeatedOpera) //returns a number if valid
{
	double num;
	bool didItFail = true;
	do
	{
		if (repeatedOpera)
		{
			if (didItFail)
			{
				cout << "\n\nEnter number "
						 << changeWords(userOperatorInput)
						 << firstNum << ": ";
			}
			else
			{
				cout << "\n-- Invalid Input --\nEnter number "
						 << changeWords(userOperatorInput)
						 << firstNum << ": ";
			}
		}
		else
		{
			if (didItFail)
				cout << "\n\nEnter number ";
			else
				cout << "\n-- Invalid Input --\nEnter number ";
		}
		cin >> num;
		refreshDisplay();
		didItFail = isItAValidNumber(cin.fail());
	} while (!didItFail);
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
		return false;
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

bool isItAValidNumber(bool yesNo) //returns true if valid
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