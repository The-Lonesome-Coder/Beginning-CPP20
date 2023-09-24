#include <algorithm>
#include <cmath>
#include <format>
#include <iostream>
#include <vector>


void print_result(std::vector<double> &scores)
{
    int size = scores.size();

    // Highest grade
    std::cout << "The five highest grades are: ";

    for (int i = size - 5; i < size; ++i)
    {
        std::cout << scores[i] << ' ';
    }

    std::cout << '\n';


    // Lowest grade
    std::cout << "The five lowest grades are: ";

    for (int i = 0; i < 5; ++i)
    {
        std::cout << scores[i] << ' ';
    }

    std::cout << '\n';


    // Average grade
    double sum = 0.0;

    for (int i = 0; i < size; ++i)
    {
        sum += scores[i];
    }

    double average = sum / size;

    std::cout << "The average grade is: " <<  average << '\n';


    // Median grade
    double median = 0.0;

    if (size % 2 != 0)
    {
        median = scores[size / 2];
    }
    else if (size % 2 == 0)
    {
        median = (scores[size / 2] + scores[(size / 2) + 1]) / 2;
    }

    std::cout << "The median grade is: " << median << '\n';


    // Standard deviation
    double distance_sum = 0.0;

    for (int i = 0; i < size; ++i)
    {
        distance_sum += pow((scores[i] - average), 2);
    }

    double sd = std::sqrt((distance_sum / size));

    std::cout << "The standard deviation is: " << sd << '\n';


    // Variance
    std::cout << "The variance is: " << pow(sd, 2)
              << std::endl;
}


int main(void)
{
    std::vector<double> scores {};

    double score = 0.0;

    while (true)
    {
        std::cout << "Please enter a score, enter a negative number to stop the program: ";
        std::cin >> score;

        if (score < 0.0)
        {
            break;
        }

        if (score > 100.0)
        {
            std::cout << "Score cannot exceed 100.";
            continue;
        }

        scores.push_back(score);
    }

    std::sort(scores.begin(), scores.end());

    print_result(scores);
}