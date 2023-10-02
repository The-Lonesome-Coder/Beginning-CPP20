import <iostream>;
import <string>;

import words;

namespace wrds
{
    using namespace words;
}


int main()
{
    wrds::Words words;

    std::string text;

    const auto separators = " ,.!?\"\n";

    std::cout << "Enter a string terminated by *:" << std::endl;
    std::getline(std::cin, text, '*');

    w::extract_words(words, text, separators);

    if (words.empty())
    {
        std::cout << "No words in text." << std::endl;

        return 1;
    }

    wrds::sort(words);

    w::show_words(words);

    return 0;
}