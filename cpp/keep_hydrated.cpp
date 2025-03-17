#include <iostream>
#include <cmath>
#include <cassert>

int hydrated(double time)
{
    // returning as an int does the floor round by default. no need to explicitly cast here
    return time / 2;
}

int main()
{
    assert(hydrated(11.8) == 5);
    assert(hydrated(6.7) == 3);
    assert(hydrated(3) == 1);
    
    return 0;
}