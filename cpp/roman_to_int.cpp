#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

int romanToInt(std::string s) {
    int result{0};
    int length{static_cast<int>(s.size())};

    std::unordered_map<std::string, int> romanNumerals = {
        {"I", 1},   {"V", 5},   {"X", 10},  {"L", 50},
        {"C", 100}, {"D", 500}, {"M", 1000}};

    int i{0};

    while (i < length) {
        if (i + 1 < length && romanNumerals[std::string(1, s[i])] <
                                  romanNumerals[std::string(1, s[i + 1])]) {
            result += romanNumerals[std::string(1, s[i + 1])] -
                      romanNumerals[std::string(1, s[i])];
            i += 2;
        } else {
            result += romanNumerals[std::string(1, s[i])];
            i += 1;
        }
    }

    return result;
}

int main() {
    std::cout << romanToInt("DXCI") << '\n';

    return 0;
}