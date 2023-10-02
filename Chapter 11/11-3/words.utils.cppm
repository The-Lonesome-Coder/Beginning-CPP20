export module words.utils;

import <memory>;
import <string>;
import <vector>;


export namespace words
{
    using Words = std::vector<std::shared_ptr<std::string>>;
}


export namespace words::utils
{
    void extract_words(Words& words, const std::string& text, const std::string& separators);
    void show_words(const Words& words);
}