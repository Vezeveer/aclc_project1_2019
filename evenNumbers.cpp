#include <iostream>

using std::cin;
using std::cout;

int main()
{
  int x, sum = 0;
  for (int i = 1; i <= 10; i++)
  {
    x = i % 2;
    if (x == 0)
    {
      sum = sum + i;
    }
  }

  cout << "\n\nSum of even numbers between 1-10: " << sum;

  cout << "\n\n\n";
  system("pause");
  return 0;
}