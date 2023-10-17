import <format>;
import <functional>;
import <iostream>;
import <random>;
import <string>;

import curveball;
import custom.exception;


// Throw exception randomly - about 25% of the time
auto createUniformPseudoRandomNumberGenerator(double min, double max)
{
    std::random_device seeder;          // True random number generator to obtain a seed (slow)
    std::default_random_engine generator { seeder() };      // Efficient pseudo-random generator
    std::uniform_real_distribution distribution { min, max }; // Generate in [min, max) interval

    return std::bind(distribution, generator);             //... and in the darkness bind them!
}


// Throw a Curveball exception 25% of the time
void throwCurveballSometimes()
{
    static auto random = createUniformPseudoRandomNumberGenerator(0, 100);

    if (random() < 25)
        throw Curveball {};
}


int readEvenNumber()
{
    int number = 0;

    std::cin >> number;

    if (std::cin.fail())
    {
        std::cin.clear();
        std::string line;
        std::getline(std::cin, line);

        throw NotANumber { line };
    }

    throwCurveballSometimes();

    if (number < 0)
    {
        throw NegativeNumber { number };
    }

    if (number % 2 == 1)
    {
        throw OddNumber { number };
    }

    return number;
}


void askEvenNumber()
{
    while (true)
    {
        try
        {
            std::cout << "Please enter an even number: ";
            const int read = readEvenNumber();
            std::cout << std::format("Well done. {} is a beautiful even number. Thank you!\n", read);
            break;
        }
        catch (const NotANumber& nan)
        {
            std::cerr << nan.what() << std::endl;
            return;
        }
        catch (const std::out_of_range& range)
        {
            std::cerr << range.what() << std::endl;
        }
        catch (const std::exception& exception)
        {
            std::cerr << exception.what() << std::endl;
            throw;
        }
    }
}


int main()
{
    try
    {
        askEvenNumber();
    }
    catch (...)
    {
        std::cerr << "Some error has happened." << std::endl;
    }
}