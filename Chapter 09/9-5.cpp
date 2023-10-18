#include <iostream>
#include <span>


double average10(std::span<double, 10> data)
{
    double sum = 0;

    for (auto val : data)
    {
        sum += val;
    }

    return sum / (data.size());
}


int main()
{
    double values[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0};

    std::cout << "Average = " << average10(values) << std::endl;

    return 0;
}