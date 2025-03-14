#include <iostream>
#include <vector>
#include <map>

std::vector<int> twosum(std::vector<int> numbers, int target)
{
    // define map
    std::map<int, int> numMap {};
    // numbers.size() isn't natively an integer, it's some weird size type. I'll dig into why
    int length { static_cast<int>(numbers.size())};

    // loop 1 - populate that map with the value as the key and the index as the key. I need that index so I can return it later
    for (int i {0}; i < length; i++)
        numMap[numbers[i]] = i;

    // loop 2 - loop back through the list and check if the complement for the current number is a key in the map
    for (int j {0}; j < length; j++)
    {
        int complement = target - numbers[j];

        // count will return a value based on if the key is in the map
        // the complement needs to in the map as a key and it can't be at the same index (if the key is 50% of the goal)
        if (numMap.count(complement) && numMap[complement] != j)
            return { j, numMap[complement] };
    }

    // empty vector if no pairs found
    return {};
}


int main()
{
    std::vector<int> match { twosum({1234, 5678, 9012}, 14690) };

    if (match.size() == 2)
    {
        std::cout << "The indices are " << match[0] << " and " << match[1] << '\n';
    }
    else
    {
        std::cout << "no match was found\n";
    }

    return 0;
}
