#include <iostream>

using std::cin;
using std::cout;

int main()
{
  int wordCount;
  double total = 15.0;
  cout << "How many words are there? ";
  cin >> wordCount;

  if (wordCount > 20)
  {
    for (int i = 0; wordCount - 20 > i; i++)
    {
      total = total + 0.60;
    }
  }

  cout << "Total cost: " << total << "php\n\n";

  system("pause");
  return 0;
}