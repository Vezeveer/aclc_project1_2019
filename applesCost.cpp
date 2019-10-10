#include <iostream>

using std::cin;
using std::cout;

double total = 0.0, normalCost = 12.5, discountCost = 10.0;

double calculateCost(int);

int main()
{
  int apples;

  cout << "Enter number of apples bought: ";
  cin >> apples;
  total = calculateCost(apples);

  cout << "Total cost is: " << total << "\n\n\n";

  system("pause");
  return 0;
}

double calculateCost(int x)
{
  if (x > 24)
    return discountCost * x;
  else
    return normalCost * x;
}