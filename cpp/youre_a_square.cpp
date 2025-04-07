#include <iostream>

bool is_square(int n) {
    if (n < 0) return false;

    // create a span from 1 to n, it's effectively just a big binary search of all numbers in that range
    int left = 1, right = n;

    while (left <= right) {
        // finds the middle in a way that avoids int overflow 
        long long mid = left + (right - left) / 2;
        long long square = mid * mid;

        if (square == n) return true;
        // if the square from the middle is too small, 
        // all numbers to the left of it will be too small as well
        if (square < n) left = mid + 1;
        // if it's too big, anything larger will also be too big
        else right = mid - 1;
    }

    return false;
}

int main() {
    std::cout << is_square(4) << '\n';

    return 0;
}