import integer;

import <iostream>;


int main(void)
{
    Integer num1 {10};
    Integer num2 {20};
    const Integer num3 {30};
    Integer num4 {num3};

    num1.showValue();

    num2.setValue(50);
    num2.showValue();

    num3.showValue();

    num4.showValue();

    std::cout << num4.compare(num3) << std::endl;

    return 0;
}