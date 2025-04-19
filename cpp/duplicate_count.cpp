#include <iostream>
#include <cassert>
#include <string>
#include <unordered_map>
#include <algorithm>

std::size_t duplicateCount(const std::string& in) {
    std::unordered_map<char, int> letters {};

    for (auto ch : in) {
        char lower = std::tolower(ch);
        letters[lower]++;
    }

    // return how many keys have values > 1
    auto ct = std::count_if(
        letters.begin(), letters.end(),
        [](const std::pair<const int, int>& kv) {
            return kv.second > 1;
        }
    );

    return ct;
}

int main() {
    assert(duplicateCount("asdfghjkl54") == 0 && "No duplicates in \"asdfghjkl54\"");
    assert(duplicateCount("abcdeaa") == 1 && "One duplicate in \"abcdeaa\"");
    assert(duplicateCount("abcdeaB") == 2 && "One duplicate in \"abcdeaB\"");

    return 0;
}