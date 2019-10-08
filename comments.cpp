//Description: Continuously asks if the user wants to do an operation on the specified number
//Programmers: Emmanuel Valdueza, Jake P Ogsimer, Mark L Perez
//Created: Oct-02-2019 | Oct-08-2019

#include <iostream> //library for using cin cout
#include <limits>   //library for handling cin unwanted input
#include <string>   //library for using string

//global variables
double currentNumber = 0.0;
bool enteredARealNumber = false, firstNumValid = false, operaIsInvalid = true;

//forward declarations. Needed because of C++ top down approach.
std::string displayMode(char op);               //changes text depending on operation asked
char convertToChar(std::string opera);          //required because switch only takes in char or number
bool isItANumber();                             //checks if input is a number
double calculation(char operation, double num); //performs the operation depending on what is asked

int main() //entry point of program
{
  //local variables
  double numFollowUp;
  char op;
  std::string operaString, doAgain = "n";

  //welcome note
  std::cout << "Welcome. I will ask for a number and you will\n"
            << "tell me what operation to perform on another number\n"
            << "that I will ask you. We will then do another operation \n"
            << "on the result if you wish to continue.\n\n";

  //wll continue asking for a number if input is not a number
  do
  {
    std::cout << "Enter a number: ";
    std::cin >> currentNumber;

    if (isItANumber())
    {
      while (operaIsInvalid)
      {
        std::cout << "Enter an operation \"+, -, / or *\": ";

        std::cin >> operaString;
        op = convertToChar(operaString);

        if (op == '+' || op == '-' || op == '/' || op == '*')
        {
          do
          {
            firstNumValid = false;
            std::cout << "Enter a number " << displayMode(op) << currentNumber << ": ";
            std::cin >> numFollowUp;
            //verify input is a number
            if (isItANumber())
            {
              std::cout << "\nResult: " << calculation(op, numFollowUp)
                        << "\n\nType \"yes\" to do another opertaion on the result. ";
              std::cin >> doAgain;
              operaIsInvalid = false;
              if (doAgain == "yes")
              {
                std::cout << std::endl;
                operaIsInvalid = true;
              }
            }
            else
            {
              std::cout << "Input is not a number. ";
            }
          } while (firstNumValid == false);
        }
        else
        {
          operaIsInvalid = true;
          std::cout << "Invalid operator. ";
        }
      }
    }
    else
    {
      std::cout << "Input is not a number. ";
    }
  } while (firstNumValid == false);

  std::cout << "\n\n";
  system("pause");
  return 0;
}

char convertToChar(std::string opera)
{
  return opera[0]; //returns first char of word
}

bool isItANumber()
{
  if (std::cin.fail()) //check if input is a number
  {
    std::cin.clear();                                                   //clears cin errors
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //clears cin input
    return false;
  }
  else
  {
    firstNumValid = 1;
    return true;
  }
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

std::string displayMode(char op)
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