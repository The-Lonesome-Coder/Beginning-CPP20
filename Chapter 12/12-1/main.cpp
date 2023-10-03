import integer;


int main(void)
{
    Integer num1 {10};
    Integer num2 {20};
    const Integer num3 {30};

    num1.showValue();

    num2.setValue(50);
    num2.showValue();

    num3.showValue();

    return 0;
}