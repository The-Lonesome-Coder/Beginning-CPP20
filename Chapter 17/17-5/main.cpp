import myArray;

import <string>;
import <vector>;


MyArray<std::string> buildStringArray(const size_t size)
{
    MyArray<std::string> result { size };

    for (size_t i { 0 }; i < size; ++i)
    {
        result[i] = "You should learn from your competitor, but never copy. Copy and you die.";
    }

    return result;
}


int main()
{
    MyArray<std::string> strings { 123 };
    strings = buildStringArray(1'000); // Assign an rvalue to strings

    MyArray<std::string> more_strings { 2'000 };
    strings = std::move(more_strings); // Assign an lvalue to strings
}