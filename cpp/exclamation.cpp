#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <regex>

std::string replace(const std::string &s) {
    std::string result {};
    std::string vowels { "aeiouAEIOU" };

    for (size_t i { 0 }; i < s.size(); ++i) {
        // the "std::find" function from the algorithm searches a vector (a str is a vector) for
        // a specified value. 
        if (std::find(vowels.begin(), vowels.end(), s[i]) != vowels.end()) {
            result += '!';
        } else {
            result += s[i];
        }
    }

    return result;
}

std::string replaceWithRegex(const std::string &s) {
    // the regex library provides a convenient regex operations for quick swaps like this
    return std::regex_replace(s, std::regex("[aeiouAEIOU]"), "!");
}

int main() {
    std::string value = replaceWithRegex("!Hi! Hi!");

    std::cout << "Output: " << value << '\n';

    return 0;
}