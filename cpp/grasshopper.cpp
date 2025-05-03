#include <cassert>
#include <numeric>
#include <vector>

int summation(int num){
    std::vector<int> v(num);

    std::iota(v.begin(), v.end(), 1);

    return std::accumulate(v.begin(), v.end(), 0);
}

int main() {
    assert(summation(2) == 3);
    assert(summation(8) == 36);

    return 0;
}