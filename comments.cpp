//Description: Performs number operations as many times as required
//Programmers: Emmanuel Valdueza, Jake P Ogsimer, Mark L Perez
//Created: Oct-02-2019 | Oct-08-2019

#include <iostream> //library for using cout, cin
#include <limits>   //library for handling cin unwanted input
#include <string>   //library for using string

using std::cin; //prevents identifier naming conflicts
using std::cout;
using std::string;

string operationAsked; //global variables 13-15
bool invalidOp = true, repeatedOperation = false;
double secondNum, result, firstNum;

string changeWords(string operation);                            //function declarations through lines 17-25
double calculate(string operation, double first, double second); //takes in 2 numbers and an operation, and returns a result
void promptToExit();
bool isItAValidOperation(string op); //gets the operation, returns false if not any of the operations asked
bool isItAValidNumber(bool yesNo);   //basically, it checks if current input is a number. Returns false if not.
double askNumber(bool);              //Gets number and returns it if it is valid. Boolean argument changes sentence
void showResults();
void welcomeMessage();
void askOperation(); //asks for number and stores it to global variable

int main() //main entry point of program
{
  do
  {
    if (!repeatedOperation) //will occur only once
    {
      welcomeMessage();
      firstNum = askNumber(repeatedOperation);
      askOperation();
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
      cout << "\n# You chose to exit the program. #\n\n";
      repeatedOperation = false;
    }
  } while (repeatedOperation); //loops operation as long as repeated is true

  system("pause"); //without this the program would close immediately if told to exit
  return 0;
}

void welcomeMessage()
{
  cout << "\nThis program will perform one or more "
       << "operations as required. \n\n";
}

void askOperation()
{
  do
  {
    cout << "Type +, -, * or /: ";
    cin >> operationAsked;
    if (!isItAValidOperation(operationAsked))
      cout << "Invalid. Please ";
  } while (!isItAValidOperation(operationAsked));
}

void showResults()
{
  cout << "\nResult: "
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
  cout << "\nType the ff operations."
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