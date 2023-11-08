#include <iostream>
#include <stack>
#include <string>


int main()
{
    std::string words[]{ "The", "quick", "brown", "fox", "jumps" };
    std::stack<std::string> wordStack;

    for (const auto& word : words)
    {
        wordStack.push(word);
    }

    std::stack<std::string> newStack{ wordStack };

    // Display the words in reverse order
    while (!newStack.empty())
    {
        std::cout << newStack.top() << ' ';
        newStack.pop();
    }
    std::cout << std::endl;

    // Reverse wordStack onto newStack
    while (!wordStack.empty())
    {
        newStack.push(wordStack.top());
        wordStack.pop();
    }


    // Display the words in original order
    while (!newStack.empty())
    {
        std::cout << newStack.top() << ' ';
        newStack.pop();
    }

    std::cout << std::endl;

    std::cout << std::endl << "Enter a line of text:" << std::endl;
    std::string text;
    std::getline(std::cin, text);

    std::stack<char> characters;

    for (size_t i{}; i < text.length(); ++i)
    {
        characters.push(text[i]);
    }

    while (!characters.empty())
    {
        std::cout << characters.top();
        characters.pop();
    }
    std::cout << std::endl;
}