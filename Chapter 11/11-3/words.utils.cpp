module words.utils;

import <format>;
import <iostream>;


size_t max_word_length(const words::Words& words)
{
    size_t max = 0;

    for (auto pword : words)
    {
        if (max < pword->length())
        {
            max = pword->length();
        }
    }

    return max;
}


void words::utils::extract_words(Words& words, const std::string& text, const std::string& separators)
{
    size_t start = text.find_first_not_of(separators);

    while (start != std::string::npos)
    {
        size_t end = text.find_first_of(separators, start + 1);

        if (end == std::string::npos)
        {
            end = text.length();
        }

        words.push_back(std::make_shared<std::string>(text.substr(start, end - start)));

        start = text.find_first_not_of(separators, end + 1);
    }
}




void words::utils::show_words(const Words& words)
{
    const size_t field_width = max_word_length(words) + 1;
    const size_t words_per_line = 8;

    std::cout << std::format("{:{}}", *words[0], field_width);

    size_t words_in_line = 0;

    for (size_t i = 1, size = words.size(); i < size; ++i)
    {
        if ((*words[i])[0] != (*words[i - 1])[0] || ++words_in_line == words_per_line)
        {
            words_in_line = 0;
            std::cout << std::endl;
        }

        std::cout << std::format("{:{}}", *words[i], field_width);
    }

    std::cout << std::endl;
}
