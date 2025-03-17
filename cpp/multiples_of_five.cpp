#include <iostream>
#include <vector>
#include <cassert>

int multiplesOfFive(int number)
{
    int sum {0};

    // start at 3 because no multiples below that point
    for (int i {3}; i < number; ++i)
    {
        // no need to exclude 15 because this won't double-count it
        if (i % 3 == 0 || i % 5 == 0)
        {
            sum += i;
        }
    }

    return sum;
}

int main()
{
    int sums = multiplesOfFive(20);

    std::cout << "The sum of multiples of 3 and 5 that are less than 20 are " << sums << '\n';
    assert(sums == 78);


    return 0;
}