import <iostream>;

import box;


int main()
{
    Box box {2, 3, 4};

    std::cout << "Box is " << box << std::endl;

    unsigned n {3};

    Box newBox {box * n};

    std::cout << "After multiplying by " << n << " box is " << newBox << std::endl;

    newBox *= n;

    std::cout << "After multiplying by " << n << " again, box is " << newBox << std::endl;
}