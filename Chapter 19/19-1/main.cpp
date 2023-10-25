import <functional>;
import <iostream>;
import <string>;
import <vector>;


int main()
{
    std::vector<std::string> strings { "apple", "banana", "cherry", "pineapple", "apricot" };

    std::function<int(char)> count =
                                [&strings](char character)
                                {
                                    int cnt = 0;

                                    for (auto& element : strings)
                                    {
                                        if (element.starts_with(character))
                                        {
                                            ++cnt;
                                        }
                                    }

                                    return cnt;
                                };

    std::cout << count('a') << std::endl;
    std::cout << count('b') << std::endl;
}