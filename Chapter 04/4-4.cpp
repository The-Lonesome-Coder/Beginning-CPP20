#include <format>
#include <iostream>
#include <string>


int main(void)
{
    constexpr auto reject = "Sorry. Your {} does not meet the requirement.";

    // Start interview
    // Age
    int age = 0;

    std::cout << "Please enter your age: ";
    std::cin >> age;

    if (age < 21 || age > 35)
    {
        std::cout << std::format(reject, "age")
                  << std::endl;

        return 1;
    }

    // Gender
    char gender = 0;

    std::cout << "Please enter your gender ('m' for male, and 'f' for female): ";
    std::cin >> gender;

    if (gender != 'f')
    {
        std::cout << std::format(reject, "gender")
                  << std::endl;

        return 2;
    }

    // Academic Degree
    int degree = 0;

    std::cout << "Please enter your highest degree \n"
              << "(none = 0, associate = 1, bachelor = 2, professional = 3, master = 4, doctorate = 5): ";
    std::cin >> degree;

    if (degree != 2 && degree != 4)
    {
        std::cout << std::format(reject, "highest degree")
                  << std::endl;

        return 3;
    }

    // Marriage status
    bool married = false;

    std::cout << "Are your married (0 for \"NO\", 1 for \"YES\"): ";
    std::cin >> married;

    if (married != 0)
    {
        std::cout << std::format(reject, "marriage status")
                  << std::endl;

        return 4;
    }

    // Language - Hindi
    bool speaksHindi = false;

    std::cout << "Do you speak Hindi (0 for \"NO\", 1 for \"YES\"): ";
    std::cin >> speaksHindi;

    if (speaksHindi != 1)
    {
        std::cout << std::format(reject, "language capability")
                  << std::endl;

        return 5;
    }

    // Language - Urdu
    bool speaksUrdu = false;

    std::cout << "Do you speak Urdu (0 for \"NO\", 1 for \"YES\"): ";
    std::cin >> speaksUrdu;

    if (speaksUrdu != 1)
    {
        std::cout << std::format(reject, "language capability")
                  << std::endl;

        return 6;
    }

    std::cout << "Congratulation. You meet all the requirements. You are hired."
               << std::endl;

    return 0;
}