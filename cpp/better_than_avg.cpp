#include <vector>
#include <iostream>
#include <numeric>

bool betterThanAverage(std::vector<int> classPoints, int yourPoints)
{
    // the numeric package includes the "accumulate" function which works like the JS reduce method to take the items
    // of a collection and sum them iteratively. 
    // if this function is not available, a simple for loop would work just as well 
    return std::accumulate(classPoints.cbegin(), classPoints.cend(), 0) < classPoints.size() * yourPoints;
}

int main()
{
    bool result { betterThanAverage({100, 40, 34, 57, 29, 72, 57, 88}, 75) };   // should equate to true (1);

    std::cout << "Better than average? " << result << '\n';
    
    return 0;
}