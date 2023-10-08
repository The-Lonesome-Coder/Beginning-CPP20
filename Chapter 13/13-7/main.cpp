import <format>;
import <iostream>;

import rational;


int main(void)
{
    Rational num1 {22, 7};
    Rational num2 {21, 5};
    Rational num3 {16, 3};

    if (num1 == num2)
    {
        std::cout << "Equal.\n";
    }
    else if (num1 < num2)
    {
        std::cout << "Smaller.\n";
    }
    else if (num1 > num2)
    {
        std::cout << "Larger.\n";
    }

    if (num1 == 1.6)
    {
        std::cout << "Equal.\n";
    }
    else if (num1 < 1.6)
    {
        std::cout << "Smaller.\n";
    }
    else if (num1 > 1.6)
    {
        std::cout << "Larger.\n";
    }

    Rational num4 = num1 + num2;
    Rational num5 = num1 - num2;
    Rational num6 = num1 * num2;
    Rational num7 = num1 / num2;

    std::cout << num4 << '\n';
    std::cout << num5 << '\n';
    std::cout << num6 << '\n';
    std::cout << num7 << std::endl;

    num2 += num3;
    std::cout << num2 << '\n';

    num2 -= num3;
    std::cout << num2 << '\n';

    num2 *= num3;
    std::cout << num2 << '\n';

    num2 /= num3;
    std::cout << num2 << std::endl;
}