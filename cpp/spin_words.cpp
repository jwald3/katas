#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

std::string spinWords(const std::string &str) {
    std::vector<std::string> words {};

    for (size_t i {0}; i < str.size();) {
        std::string word = "";

        while (str[i] != ' ' && i < str.size()) {
            word += str[i];
            ++i;
        }

        ++i;

        words.push_back(word);
    }

    std::string spunText {};

    for (size_t i {0}; i < words.size(); ++i) {
        if (words[i].size() >= 5) {
            std::reverse(words[i].begin(), words[i].end());
            spunText += words[i];
        } else {
            spunText += words[i];
        }

        if (words.size() - i > 1) {
            spunText += ' ';
        }
    }

    return spunText;
}

int main() {
    std::string spun = spinWords("This is another test");

    std::cout << spun << '\n';
}