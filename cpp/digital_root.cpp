#include <iostream>
#include <string>

// the method needs to be recursive because I need to reduce down to a single digit value
int digital_root(int n)
{
    // base case
    if (n < 10) {
        return n;
    } 
  
    std::string digits = std::to_string(n);
    int sum { 0 };  
  
    for (auto c: digits) {
        // makeshift int cast
        sum += c - '0';
    }
  
    // recursive call 
    return digital_root(sum);
}

int main() {
    int digitalRoot = digital_root(132189);

    std::cout << digitalRoot << '\n';

    return 0;
}