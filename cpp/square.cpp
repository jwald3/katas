#include <cassert>
#include <cmath>

template <typename T>
T square(const T a) {
    return a * a;
}

int main() {
    // cant directly compare floats, so you have to check with epsilon value for 
    // "close enough" precision
    assert(fabs(square(3.3) - 10.89) < __FLT_EPSILON__);
    assert(square(2) == 4);

    return 0;
}

