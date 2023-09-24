#include <cmath>
#include <format>
#include <iostream>
#include <vector>


bool check_prime(const int &num)
{
    if (num == 1)
    {
        return false;
    }

    for (int i = 2, limit = std::sqrt(num); i <= limit; ++i)
    {
        if (num % i == 0)
        {
            return false;
        }
    }

    return true;
}


std::vector<int> num_list(const int &num)
{
    std::vector<int> list {};

    for (int i = 0; i <= num; ++i)
    {
        list.push_back(i);
    }

    return list;
}


std::vector<int> primes(std::vector<int> &nums)
{
    std::vector<int> prime_list {};

    for (int i = 0, size = nums.size(); i < size; ++i)
    {
        if (i < 2)
        {
            continue;
        }

        if (check_prime(nums[i]))
        {
            prime_list.push_back(nums[i]);
        }
    }

    return prime_list;
}


void print_result(std::vector<int> &nums)
{
    for (int i = 0, size = nums.size(); i < size; ++i)
    {
        std::cout << std::format("{} | ", nums[i]);

        if (i % 10 == 0 && i != 0)
        {
            std::cout << std::endl;
        }
    }
}


int main(void)
{
    int input = 0;

    std::cout << "Please enter a number: ";
    std::cin >> input;

    std::vector<int> nums = num_list(input);

    std::vector<int> prime_list = primes(nums);

    print_result(prime_list);

    return 0;
}