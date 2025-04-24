#pragma once
#include <string>
#include <vector>

bool isPalindrome(const std::string& s);
std::vector<int> uniqueElements(std::vector<int> v);
std::vector<int> filterEven(const std::vector<int>& v);
int sum(const std::vector<int>& v);
bool containsSubsequence(const std::vector<int>& haystack,
                         const std::vector<int>& needle);
std::pair<int, int> minMax(const std::vector<int>& v);
std::vector<std::string> toUpperCase(const std::vector<std::string>& v);
std::vector<int> rotateLeft(std::vector<int> v, int n);
bool isSortedAsc(const std::vector<int>& v);
std::vector<int> iotaSequence(int start, int n);
std::pair<std::vector<int>, std::vector<int>> partitionOddsEvens(
    const std::vector<int>& v);
bool binarySearch(const std::vector<int>& v, int value);
int countVowels(const std::string& s);

std::vector<int> zipSum(const std::vector<int>& a, const std::vector<int>& b);
std::vector<int> clampValues(std::vector<int> v, int low, int high);
// char firstDuplicateChar(const std::string& s);
// std::string concatenate(const std::vector<std::string>& v,
//                         const std::string& sep);
// std::vector<int> rotateRight(std::vector<int> v, int n);
// bool isPangram(const std::string& s);
int alphabetPositionSum(const std::string& s);
// std::vector<std::string> filterLongStrings(const std::vector<std::string>& v,
//                                            std::size_t minLen);
// std::pair<int, int> secondMinMax(std::vector<int> v);
int countUppercase(const std::string& s);