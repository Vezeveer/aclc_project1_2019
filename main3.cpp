//Description: Performs number operations as many times as required
//Programmers: Emmanuel Valdueza, Jake P Ogsimer, Mark L Perez
//Created: Oct-02-2019 | Oct-08-2019

#include <iostream>
#include <limits> //library for handling cin unwanted input
#include <string>

using std::cin;
using std::cout;

double currentNumber = 0.0, numFollowUp;
bool firstNumAlreadyAsked = false, keepGoing = true;
char op;
std::string operaString, doAgain = "n";

std::string showOperationType(char op);
char convertToChar(std::string opera);
double calculation(char operation, double num);
void welcome();
void askNumber();
void askOperation();
void askForNextNumber();
void result();
void askToKeepGoing();

int main()
{
  welcome();
  askNumber();

  do
  {
    askOperation();
    askNumber();
    result();
    askToKeepGoing();
  } while (keepGoing);

  cout << "You chose to exit. \n\n\n";

  system("pause");
  return 0;
}

void askToKeepGoing()
{
  cout << "\n\nType \"yes\" to do another opertaion"
       << " on the result else type \"exit\". ";
  cin >> doAgain;
  if (doAgain != "yes")
    keepGoing = false;
  cout << "\n";
}

void result()
{
  cout << "\nResult: "
       << calculation(op, numFollowUp);
}

void askOperation()
{
  bool invalidOperation = true;
  while (invalidOperation)
  {
    cout << "Enter an operation \"+, -, / or *\": ";
    cin >> operaString;
    op = convertToChar(operaString);

    if (op == '+' || op == '-' || op == '/' || op == '*')
    {
      invalidOperation = false;
    }
    else
    {
      invalidOperation = true;
      cout << "Invalid operator. ";
    }
  }
}

void askNumber()
{
  int isValid = 0;
  do
  {
    if (firstNumAlreadyAsked)
    {
      cout << "Enter a number "
           << showOperationType(op)
           << currentNumber
           << ": ";
      cin >> numFollowUp;
    }
    else
    {
      cout << "Enter a number: ";
      cin >> currentNumber;
    }

    if (cin.fail()) //cin.fail() becomes true if input is not of specified data type
    {
      cin.clear(); //resets cin.fail() to false
      cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      /*cin.ignore() clears the characters that would make cin.fail() true
        where the first argument indicates no limit to the number of characters
        to ignore and the second argument the character from which to stop ignoring
        which is the character for enter.
      */
      cout << "Invalid input. ";
    }
    else
    {
      firstNumAlreadyAsked = true;
      isValid = 1;
    }

  } while (isValid == 0);
}

void welcome()
{
  cout << "This program will perform one or more "
       << "operations as required. \n\n";
}

char convertToChar(std::string opera)
{
  return opera[0]; //returns first char of word
}

double calculation(char operation, double num)
{
  switch (operation)
  {
  case '+':
    return currentNumber = currentNumber + num;
  case '-':
    return currentNumber = currentNumber - num;
  case '*':
    return currentNumber = currentNumber * num;
  case '/':
    return currentNumber = currentNumber / num;
  default:
    return 404;
  }
}

std::string showOperationType(char op)
{
  switch (op)
  {
  case '+':
    return "to add to ";
  case '-':
    return "to subtract from ";
  case '*':
    return "to multiply with ";
  case '/':
    return "to divide ";
  default:
    return "[Not Valid]";
  }
}