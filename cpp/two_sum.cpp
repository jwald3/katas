#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <cassert>

// using a one-pass hash map means I can populate the map as I go and I never need to worry about
// checking against passing the same index twice as a solution
std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::map<int, int> numbers {};

    for (size_t i {0}; i < nums.size(); ++i) {
        int complement = target - nums[i];
        if (numbers.count(complement)) {
            return { numbers[complement], (int)i};
        }
        
        numbers[nums[i]] = i;
    }
    
    return {};
}

int main() {
    std::vector<int> items {2, 7, 11, 15};
    std::vector<int> idx = twoSum(items, 9);

    std::vector<int> expected{0, 1};

    assert(idx == expected);

    return 0;
}