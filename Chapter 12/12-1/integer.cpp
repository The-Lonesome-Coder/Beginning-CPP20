module integer;


int Integer::getValue() const
{
    return number;
}


void Integer::setValue(const int num)
{
    number = num;
}


void Integer::showValue() const
{
    std::cout << "The value is: " << number << "." << std::endl;
}