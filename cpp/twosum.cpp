#include <iostream>
#include <vector>

bool twosum(std::vector<int> array)
{
    std::size_t length { array.size() };

    for (int i {0}; i < static_cast<int>(length); ++i) 
    {
        for (int j {0}; j < static_cast<int>(length); ++j) 
            if (array[i] + array[j] == 19)
            {
                return true;
            }
    }

    return false;
}


int main()
{
    std::vector<int> grades {12, 18, 15, 13, 9, 8, 13, 5};
    bool match { twosum(grades) };

    if (match)
    {
        std::cout << "a match was found\n";
    }
    else
    {
        std::cout << "no match was found\n";
    }

    return 0;
}