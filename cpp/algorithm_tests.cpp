#include <cassert>
#include "algorithm_lib.h"

int main() {
    // 1. Palindrome
    assert(isPalindrome("RaceCar"));
    assert(isPalindrome("madam"));
    assert(!isPalindrome("Hello"));

    // 2. Unique elements
    assert((uniqueElements({3,1,2,3,2}) == std::vector<int>({1,2,3})));
    assert((uniqueElements({}) == std::vector<int>({})));

    // 3. Filter even
    assert((filterEven({1,2,3,4,5}) == std::vector<int>({2,4})));
    assert((filterEven({}) == std::vector<int>({})));

    // // 4. Sum
    assert(sum({1,2,3,4}) == 10);
    assert(sum({}) == 0);

    // // 5. Subsequence
    // assert(containsSubsequence({1,2,3,4,5}, {2,3,4}));
    // assert(!containsSubsequence({1,2,3}, {3,2}));

    // // 6. Min and Max
    // auto mm1 = minMax({3,1,4,2});
    // assert(mm1.first == 1 && mm1.second == 4);
    // auto mm2 = minMax({5});
    // assert(mm2.first == 5 && mm2.second == 5);

    // // 7. Uppercase
    assert((toUpperCase({"abc","XyZ"})
            == std::vector<std::string>({"ABC","XYZ"})));

    // // 8. Rotate left
    // assert((rotateLeft({1,2,3,4,5}, 2)
    //         == std::vector<int>({3,4,5,1,2})));
    // assert((rotateLeft({}, 3) == std::vector<int>({})));

    // // 9. Sorted check
    // assert(isSortedAsc({1,2,2,3}));
    // assert(!isSortedAsc({1,3,2}));
    // assert(isSortedAsc({}));

    // // 10. Iota sequence
    // assert((iotaSequence(5, 3) == std::vector<int>({5,6,7})));
    // assert((iotaSequence(0, 0) == std::vector<int>({})));

    // // 11. Partition odds/evens
    // auto pe = partitionOddsEvens({1,2,3,4,5});
    // assert(pe.first  == std::vector<int>({1,3,5}));
    // assert(pe.second == std::vector<int>({2,4}));

    // // 12. Binary search
    // assert(binarySearch({1,2,3,4}, 3));
    // assert(!binarySearch({1,2,3,4}, 5));
    // assert(!binarySearch({}, 1));

    // // 13. Count vowels
    // assert(countVowels("hello") == 2);
    // assert(countVowels("rhythm") == 0);
    // assert(countVowels("AEIOUaeiou") == 10);

    return 0;
}