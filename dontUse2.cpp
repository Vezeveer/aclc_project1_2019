#include <iostream>
using namespace std;

int main()
{
  string inputName;
  int inputNum;

  cout << "Enter your name: ";
  cin >> inputName;

  if (inputName == "John")
  {
    cout << "Input your code: ";
    cin >> inputNum;
    if (inputNum == 3654)
    {
      cout << "Welcome aboard.";
      // repeat
    }
    else
    {
      cout << "Wrong code. \n\n";
    }
  }
  else
  {
    cout << "Name does not exist. \n\n";
  }

  system("pause");
  return 0;
}