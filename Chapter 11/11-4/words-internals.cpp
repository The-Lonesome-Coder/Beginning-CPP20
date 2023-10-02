module words:internals;

import words;


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


void swap(words::Words& words, size_t first, size_t second)
{
    auto temp = words[first];
    words[first] = words[second];
    words[second] = temp;
}
