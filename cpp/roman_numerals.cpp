#include <string>
#include <vector>
#include <tuple>
#include <iostream>
#include <map>

std::string solution(int number)
{
    // by default, the map will be sorted in ascending order. std::greater<int>
    // would ensure the map uses descending (by key) ordering.
    std::map<int, std::string> symbols = {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
        {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"},
        {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
    };

    std::string result = "";

    // `crbegin` and `crend` ensure that the loop goes in descending order.
    // if it only used `begin` and `end`, it would not be a greedy algorithm because 
    // it wouldn't start at the highest value first. 
    // if I used std::greater<int> as the optional third parameter in the map, it could 
    // be `begin` and `end` instead.
    for (auto i = symbols.crbegin(); i != symbols.crend();) {
        if (number >= i->first) {
            number -= i->first;
            result += i->second;
        } else {
            i++;
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