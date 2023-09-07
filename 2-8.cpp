#include <iostream>


int main()
{
  unsigned int a = 0, b = 0;

  std::cout << "Enter two positive integers: \n";
  std::cin >> a >> b;

  const unsigned int large {(a * (a / b) + b * (b / a)) / (a / b + b / a)};
  const unsigned int small {(b * (a / b) + a * (b / a)) / (a / b + b / a)};

  std::cout << "The larger integer is " << large << ".\n"
            << "The smaller integer is " << small << '.'
            << std::endl;
}