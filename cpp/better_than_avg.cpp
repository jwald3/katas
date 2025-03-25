#include <vector>
#include <iostream>

bool betterThanAverage(std::vector<int> classPoints, int yourPoints)
{
    int sum { yourPoints };

    for (int point: classPoints)
    {
        sum += point;
    }

    int average = sum / (static_cast<int>(classPoints.size()) + 1);

    return yourPoints > average;
}

int main()
{
    bool result { betterThanAverage({41, 75, 72, 56, 80, 82, 81, 33}, 50) };

    std::cout << "Better than average? " << result << '\n';

    return 0;
}