#include <iostream>

// this can also be represented as n^3
long long rowSumOddNumbers(unsigned n) {
    int startingValue { 1 };
    
    if (n == 1) 
    {
        return 1;
    }

    for ( int i { 0 }; i < n; ++i)
    {
        startingValue = (startingValue + (i * 2));
    }

    int sum { 0 };

    for ( int i { 0 }; i < n; ++i) 
    {
        sum += startingValue + ( i * 2);
    }

    return sum;
}


int main()
{
    long long sum { rowSumOddNumbers(3) };

    std::cout << "The sum is: " << sum << '\n';

    return 0;
}