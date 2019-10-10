#include <iostream>

//Currency Conversion by Gudmalin RC IV

using namespace std;

void currFunction()
{
  int pesovalue, choice;
  double currency, ans;
  cout << "\n Choose a currency:";
  cin >> choice;

  if (choice == 1)
  {
    cout << "\nEnter value in peso: ";
    cin >> pesovalue;

    cout << "\nEnter value of Dollar: ";

    cin >> currency;

    ans = pesovalue * currency;

    cout << pesovalue << " Php is " << ans << " in Dollars\n";
  }
  else if (choice == 2)
  {
    cout << "\nEnter value in peso: ";
    cin >> pesovalue;

    cout << "\nEnter value of Euro: ";
    cin >> currency;

    ans = pesovalue * currency;

    cout << pesovalue << " Php is " << ans << " in Euro\n";
  }
  else if (choice == 3)
  {

    cout << "\nEnter value in peso: ";
    cin >> pesovalue;

    cout << "\nEnter value of Pounds: ";
    cin >> currency;

    ans = pesovalue * currency;

    cout << pesovalue << " Php is " << ans << " in Pounds\n";
  }
  else
  {
    cout << "Invalid Input\n";
  }
}

int main()
{
  char choiceyn = 'y';
  do
  {
    currFunction();

    cout << "Do you want to convert again? (Y/N)";
    cin >> choiceyn;

  } while (choiceyn == 'Y' || choiceyn == 'y');

  if (choiceyn != 'n' || choiceyn != 'N')
  {
    cout << "INVALID INPUT!\nCLOSING PROGRAM!\n";
  }
  cout << "*****THANK YOU!*****";

  return 0;
}