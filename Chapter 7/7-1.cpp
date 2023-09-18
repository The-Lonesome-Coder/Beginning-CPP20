#include <cctype>
#include <format>
#include <iostream>
#include <string>
#include <vector>


int main(void)
{
    std::vector<std::string> names {};
    std::vector<double> scores {};

    double sum = 0.0;

    while (true)
    {
        std::string name;
        std::cout << "Please enter the name of the student: ";
        std::getline(std::cin, name);

        names.push_back(name);

        double score = 0.0;
        std::cout << "Please enter the score of the student: ";
        std::cin >> score;

        scores.push_back(score);
        sum += score;

        char response {};
        std::cout << "Do you want to enter another student's name and score (y for yes, n for no): ";
        std::cin >> response;

        if (std::tolower(response) == 'n')
        {
            break;
        }

        std::cin.ignore();
    }

    int number = names.size();

    std::cout << std::format("The average score of {} {} is {:.2F}", number,
                                                                    (number > 1 ? "students" : "student"),
                                                                    sum / number)
              << std::endl;

    for (int i = 0; i < number; ++i)
    {
        std::cout << std::format("{} : {:.2F} | ", names[i], scores[i]);

        if (i % 3 == 0 && i != 0)
        {
            std::cout << std::endl;
        }
    }

    return 0;
}