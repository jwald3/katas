#include <iostream>
/*
    in the example of 5, 19 = 24:
    x (5)  = 0000 0101
    y (19) = 0001 0011

    Iteration 1:
    x & y          = 0000 0001 (1)
    x = x ^ y      = 0001 0110 (22)
    y = carry << 1 = 0000 0010 (2)

    Iteration 2:
    x & y          = 0000 0010 (2)
    x = x ^ y      = 0001 0100 (20)
    y = carry << 1 = 0000 0100 (4)

    Iteration 3:
    x & y          = 0000 0100 (4)
    x = x ^ y      = 0001 0000 (16)
    y = carry << 1 = 0000 1000 (8)

    Iteration 4:
    x & y          = 0000 0000
    x = x ^ y      = 0001 1000 (24)
    y = carry << 1 = 0000 0000 (0)
*/
int add(int x, int y) {
	while (y != 0) {
        int carry = x & y;  
        x = x ^ y; 
        y = carry << 1;
    }
    return x;
}

int main() {
    std::cout << add(5, 19);

    return 0;
}