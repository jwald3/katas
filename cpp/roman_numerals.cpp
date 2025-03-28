#include <string>
#include <vector>
#include <tuple>
#include <iostream>

std::string solution(int number)
{
    std::vector<std::tuple<int, std::string>> symbols = {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
        {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"},
        {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
    };

    std::string result = "";

    for (auto i : symbols) {
        int value = std::get<0>(i);
        std::string str = std::get<1>(i); 

        while (number >= value) {
            result += str;

            number -= value;
        }
    }

    return result;
}

int main()
{
    int n{1875};

    std::cout << "The value is " << solution(n) << '\n';

    return 0;
}