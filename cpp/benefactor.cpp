#include <vector>
#include <iostream>
#include <cmath>
#include <cassert>

int findNextBenefactor(std::vector<double> array, int target)
{
    int total {0};
    int count {0};

    for (int i {0}; i < array.size(); ++i)
    {
        total += array[i];
        ++count;
    }

    int targetSum { (count + 1) * target };

    if (targetSum < total)
    {
        return -1;
    }
    
    return std::ceil(targetSum - total);
}


int main()
{
    assert(findNextBenefactor({14.0, 30.0, 5.0, 7.0, 9.0, 11.0, 16.0}, 90) == 628);
    assert(findNextBenefactor({14, 30, 5, 7, 9, 11, 15}, 92) == 645);
    assert(findNextBenefactor({14, 30, 5, 7, 9, 11, 15}, 2) == -1);

    return 0;
}