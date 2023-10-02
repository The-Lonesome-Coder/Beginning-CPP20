import <iostream>;
import <string>;

import words;


int main()
{
    words::Words words;

    std::string text;

    const auto separators = " ,.!?\"\n";

    std::cout << "Enter a string terminated by *:" << std::endl;
    std::getline(std::cin, text, '*');

    words::extract_words(words, text, separators);

    if (words.empty())
    {
        std::cout << "No words in text." << std::endl;

        return 1;
    }

    words::sort(words);

    words::show_words(words);

    return 0;
}