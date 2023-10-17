export module custom.exception;

import <format>;
import <stdexcept>;
import <string_view>;


export class NotANumber : public std::domain_error
{
    public:
        explicit NotANumber(std::string_view nan)
            : std::domain_error { std::format("Not a number: {}", nan) } {};
};


export class NegativeNumber : public std::domain_error
{
    public:
        explicit NegativeNumber(const int number)
            : std::domain_error { std::format("A negative number was entered: {}", number) } {};
};


export class OddNumber : public std::domain_error
{
    public:
        explicit OddNumber(const int number)
            : std::domain_error { std::format("An odd number was entered: {}", number) } {};
};