#include <iostream>
#include <vector>

std::vector<int> minChange(int amount)
{
    // 0 - 1, 1 - 5, 2 - 10, 3 - 25
    std::vector<int> count (4);

    int decrementingAmount { amount };

    if (decrementingAmount >= 25)
    {
        count[3] += (decrementingAmount / 25);
        decrementingAmount -= count[3] * 25;
    }

    if (decrementingAmount >= 10)
    {
        count[2] += (decrementingAmount / 10);
        decrementingAmount -= count[2] * 10;
    }

    if (decrementingAmount >= 5)
    {
        count[1] += (decrementingAmount / 5);
        decrementingAmount -= count[1] * 5;
    }

    if (decrementingAmount > 0)
    {
        count[0] = decrementingAmount;
    }

    return count;
}

int main()
{
    std::vector<int> coins = minChange(93);
    
    int count {0};
    
    for (int i {0}; i < coins.size(); ++i)
    {
        count += coins[i];
    }

    std::cout << "The minimum number of coins to make 93 cents is " << count << '\n';
    std::cout << coins[3] << " quarters, " << coins[2] << " dimes, " << coins[1] << " nickels, and " << coins[0] << " pennies.";

    return 0;
}