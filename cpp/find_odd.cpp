#include <iostream>
#include <vector>
#include <unordered_map>

int findOdd(const std::vector<int>& numbers) {
    // I don't know the order of the numbers coming in, so I'd rather go with a random order
    std::unordered_map<int, int> numberCount {};

    for (size_t i {0}; i < numbers.size(); ++i) {
        if (numberCount.count(numbers[i])) {
            numberCount[numbers[i]] += 1;
        } else {
            numberCount[numbers[i]] = 1;
        }
    }

    // using const makes it clear that I won't be modifying the pair at any point in the loop
    for (const auto& pair: numberCount) {
        if (pair.second % 2 != 0) {
            return pair.first;
        }
    }

    return -1;
}

int main() {
    int result = findOdd({20,1,-1,2,-2,3,3,5,5,1,2,4,20,4,-1,-2,5});

    std::cout << "Result is " << result << '\n';
}