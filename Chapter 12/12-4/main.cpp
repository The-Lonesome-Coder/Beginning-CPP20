import integer;

import <iostream>;


int main(void)
{
    Integer four {4};
    Integer five {5};
    Integer six {6};
    Integer seven {7};
    Integer eight {8};

    Integer result {four};

    std::cout << result.multiply(five).add(six).multiply(five).add(seven).multiply(five).add(eight).getValue() << std::endl;

    return 0;
}