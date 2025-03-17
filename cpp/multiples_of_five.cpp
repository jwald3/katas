#include <iostream>
#include <vector>

int multiplesOfFive(int number)
{
    if (number <= 0)
    {
        return 0;
    }

    int sum {0};

    int i {0};

    while (i < number)
    {
        if (i % 3 == 0)
        {
            sum += i;
        } 
        else if (i % 5 == 0)
        {
            sum += i;
        }

        i++;
    }

    return sum;
}

int main()
{
    int sums = multiplesOfFive(20);

    std::cout << "The sum of multiples of 3 and 5 that are less than 10 are " << sums << '\n';

    return 0;
}