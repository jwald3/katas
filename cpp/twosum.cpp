#include <iostream>
#include <vector>

int main()
{
    std::vector<int> grades {12, 18, 1, 13, 9, 8, 13, 5};
    std::size_t length { grades.size() };

    for (int i {0}; i < static_cast<int>(length); ++i) 
    {
        for (int j {0}; j < static_cast<int>(length); ++j) 
            if (grades[i] + grades[j] == 19)
            {
                std::cout << grades[i] << " + " << grades[j] << " equal 19\n";
                return 0;
            }
    }

    std::cout << "no pairs add up to 19\n";

    return 0;
}