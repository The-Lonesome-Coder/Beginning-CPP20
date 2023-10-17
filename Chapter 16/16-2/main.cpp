import <functional>;
import <iostream>;
import <random>;

import curveball;


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


int main(void)
{
    size_t number = 1000;                             // Number of loop iterations
    size_t exceptionCount = 0;                         // Count of exceptions thrown

    for (size_t i {}; i < number; ++i)
    {
        try
        {
            throwCurveballSometimes();
        }
        catch (const Curveball& ex)
        {
            std::cout << ex.what() << std::endl;
            ++exceptionCount;
            throw TooManyExceptions {};  // Un-handled exception lead to program crash
        }
    }

    std::cout << "Curveball exception thrown " << exceptionCount << " times out of " << number << ".\n";
}