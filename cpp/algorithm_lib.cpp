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

bool containsSubsequence(const std::vector<int>& haystack,
                         const std::vector<int>& needle) {
    return std::search(haystack.begin(), haystack.end(), needle.begin(),
                       needle.end()) != haystack.end();
}

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
    if (v.empty()) return v;
    n %= static_cast<int>(
        v.size());  // crop the number or rotations to be 0 <= n < len(v)
    std::rotate(v.begin(), v.begin() + n, v.end());
    return v;
}

bool isSortedAsc(const std::vector<int>& v) {
    return std::is_sorted(v.begin(), v.end());
}

std::vector<int> iotaSequence(int start, int n) {
    std::vector<int> v(n);  // creates a vector of n zeros so you have a
                            // properly-sized vector you can alter item-wise
    std::iota(v.begin(), v.end(), start);

    return v;
}

std::pair<std::vector<int>, std::vector<int>> partitionOddsEvens(
    const std::vector<int>& v) {
    std::vector<int> odds{}, evens{};

    std::partition_copy(
        v.begin(), v.end(),
        std::back_inserter(odds),   // first is the "true" case
        std::back_inserter(evens),  // second is what fails to be true
        [](int i) { return i % 2 != 0; });

    return std::pair<std::vector<int>, std::vector<int>>(odds, evens);
}

bool binarySearch(const std::vector<int>& v, int value) {
    return std::binary_search(v.begin(), v.end(), value);
}

int countVowels(const std::string& s) {
    // need to make "re" accessible across all lambda calls and all
    // `countVowels` calls
    static const std::regex re("[aeiouAEIOU]");

    auto n = std::count_if(s.begin(), s.end(), [&](char c) {
        return std::regex_match(
            std::string(1,
                        c),  // need to set a string size, cannot use c directly
            re);
    });

    return static_cast<int>(n);
}

std::vector<int> zipSum(const std::vector<int>& a, const std::vector<int>& b) {
    std::vector<int> result (a.size());

    std::transform(a.begin(), a.end(), b.begin(), result.begin(), std::plus<int>());

    return result;
}

std::vector<int> clampValues(std::vector<int> v, int low, int high) {
    // you have to make sure the destination container is properly sized before writing to it
    std::vector<int> v2(v.size());
    
    std::transform(v.begin(), v.end(), v2.begin(), [&](int a) {
        return std::clamp(a, low, high);
    });

    return v2;
}

// char firstDuplicateChar(const std::string& s);
// std::string concatenate(const std::vector<std::string>& v,
//                         const std::string& sep);
// std::vector<int> rotateRight(std::vector<int> v, int n);
// bool isPangram(const std::string& s);
// int alphabetPositionSum(const std::string& s);
// std::vector<std::string> filterLongStrings(const std::vector<std::string>& v,
//                                            std::size_t minLen);
// std::pair<int, int> secondMinMax(std::vector<int> v);

int countUppercase(const std::string& s) {
    auto n = std::count_if(s.begin(), s.end(), [](unsigned char c) {
        return std::isupper(c); // using a built-in method is wiser than using char literals like 'A' and 'Z'
    });

    // count_if returns a system-specific numeric type. casting to an int ensures the return type will match the function signature
    return static_cast<int>(n);
}