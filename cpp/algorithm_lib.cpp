#include "algorithm_lib.h"

#include <algorithm>
#include <cassert>
#include <iostream>
#include <numeric>
#include <regex>
#include <string>
#include <utility>
#include <vector>

std::string to_lower(const std::string& s) {
    std::string tempString = s;
    std::transform(tempString.begin(), tempString.end(), tempString.begin(),
                   [](unsigned char c) { return std::tolower(c); });

    return tempString;
}

bool isPalindrome(const std::string& s) {
    std::string tempString = to_lower(s);
    std::string stringToReverse = to_lower(s);
    std::reverse(stringToReverse.begin(), stringToReverse.end());

    return std::equal(tempString.begin(), tempString.end(),
                      stringToReverse.begin());
}

std::vector<int> uniqueElements(std::vector<int> v) {
    std::sort(v.begin(), v.end());
    // std::unique returns an iterator, not just another vector.
    // it moves any duplicated values to the end and points to the start of that
    // "garbage tail" i.e., [1, 2, 2, 3, 3, 3, 4] -> [1, 2, 3, 4, 3, 3, 4] where
    // the new end starts at idx 4
    auto new_end = std::unique(v.begin(), v.end());
    // remove the duplicates from the original vector.
    v.erase(new_end, v.end());
    return v;
}

std::vector<int> filterEven(const std::vector<int>& v) {
    std::vector<int> evens{};

    std::copy_if(v.begin(), v.end(), std::back_inserter(evens),
                 [](int x) { return x % 2 == 0; });

    return evens;
}

int sum(const std::vector<int>& v) {
    int n = std::accumulate(v.begin(), v.end(), 0);

    return n;
}

// bool containsSubsequence(const std::vector<int>& haystack,
//                          const std::vector<int>& needle);

std::pair<int, int> minMax(const std::vector<int>& v) {
    auto values = std::minmax_element(v.begin(), v.end());
    return std::pair<int, int>(*values.first, *values.second);
}

std::vector<std::string> toUpperCase(const std::vector<std::string>& v) {
    std::vector<std::string> capitalized{};

    for (auto s : v) {
        std::transform(s.begin(), s.end(), s.begin(),
                       [](char c) { return std::toupper(c); });

        capitalized.push_back(s);
    }

    return capitalized;
}

std::vector<int> rotateLeft(std::vector<int> v, int n) {
    std::rotate(v.begin(), v.begin() + n, v.end());
    return std::vector<int>(v.begin(), v.end());
}

bool isSortedAsc(const std::vector<int>& v) {
    return std::is_sorted(v.begin(), v.end());
}

std::vector<int> iotaSequence(int start, int n) {
    std::vector<int> v;
    std::iota(v.begin(), v.end(), n);

    return v;
}

std::pair<std::vector<int>, std::vector<int>> partitionOddsEvens(const std::vector<int>& v) {
    std::vector<int> odds{};
    std::vector<int> evens{};

    std::partition_copy(std::begin(evens), std::end(evens),
                        std::begin(odds), std::end(odds),
                    [](int i) { 
                        return i % 2 == 0; 
                    });

    return std::pair<std::vector<int>, std::vector<int>>(odds, evens);
}

// bool binarySearch(const std::vector<int>& v, int value)

int countVowels(const std::string& s) {
    // need to make "re" accessible across all lambda calls and all
    // `countVowels` calls
    static const std::regex re("[aeiouAEIOU]");

    return std::count_if(s.begin(), s.end(), [&](char c) {
        return std::regex_match(
            std::string(1,
                        c),  // need to set a string size, cannot use c directly
            re);
    });
}