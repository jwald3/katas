#include <iostream>
#include <vector>
#include <map>

std::vector<int> twosum(std::vector<int> array, int goal)
{
    // define map
    std::map<int, int> numbers {};
    int length { static_cast<int>(array.size())};

    // loop 1
    for (int i {0}; i < length; ++i)
        numbers[array[i]] = i;

    // loop 2
    for (int j {0}; j < length; ++j)
    {
        if (numbers.count(numbers[goal - array[j]]))
            return { j, numbers[goal - array[j]] };
    }

    return {};
}


int main()
{
    std::vector<int> grades {12, 18, 15, 13, 9, 1, 8, 13, 5};
    std::vector<int> match { twosum(grades, 19) };

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