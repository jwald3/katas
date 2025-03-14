#include <iostream>
#include <vector>
#include <map>

std::vector<int> twosum(std::vector<int> numbers, int target)
{
    // define map
    std::map<int, int> numMap {};
    int length { static_cast<int>(numbers.size())};

    // loop 1
    for (int i {0}; i < length; i++)
        numMap[numbers[i]] = i;

    // loop 2
    for (int j {0}; j < length; j++)
    {
        int complement = target - numbers[j];

        if (numMap.count(complement) && numMap[complement] != j)
            return { j, numMap[complement] };
    }

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