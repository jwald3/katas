#include <iostream>
#include <array>
#include <map>

std::array<int, 10> paint_letterboxes(int start, int end) {
    std::array<int, 10> freq = {};
    
    for (int i = start; i <= end; i++) {
        for (int n = i; n > 0; n /= 10) {
            freq[n % 10]++;
        }
    }

    return freq;
}

int main() {
    std::array<int, 10> freq = paint_letterboxes(125, 132);

    for (int i = 0; i < 10; i++) {
        std::cout << "value: " << i << " count: " << freq[i] << '\n';
    }

    return 0;
}