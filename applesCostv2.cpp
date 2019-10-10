#include <iostream>

using std::cin;
using std::cout;

double total = 0.0, normalCostPerDozen = 150.0, discountCostPerDozen = 120.0;

double calculateCost(int);

int main()
{
  int apples;

  cout << "Enter how many dozens of apples to buy: ";
  cin >> apples;
  total = calculateCost(apples);

  cout << "Total cost of " << apples << " dozens is: " << total << "\n\n\n";

  system("pause");
  return 0;
}

double calculateCost(int x)
{
  if (x > 2)
    return discountCostPerDozen * x;
  else
    return normalCostPerDozen * x;
}