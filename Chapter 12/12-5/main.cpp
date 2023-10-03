import <iostream>;
import integer;


int main()
{
    std::cout << "Create i with the value 0." << std::endl;
    Integer i;
    i.showValue();

    Integer::printCount();

    if (i.getValue() == 0)
    {
        std::cout << "Create j from object i." << std::endl;

        Integer j {i};
        j.showValue();

        Integer::printCount();
    }

    Integer::printCount();

    Integer array[] {1, 2, 3};

    Integer::printCount();   // 4 objects

    Integer::printCount();   // 4 objects again
}