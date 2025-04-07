# include <iostream>
# include <string>

std::string number_to_string(int num) {
    std::string result { "" };
    bool isNegative { false };

    if (num == 0) {
        return "0";
    } else if (num < 0) {
        isNegative = true;
        num *= -1;
    }

    while (num > 0) {
        int remainder = num % 10;
        char rem = '0' + remainder;

        result.insert(0, 1, rem);

        num -= remainder;
        num /= 10;
    }

    if (isNegative) {
        result.insert(0, 1, '-');
    }

    return result;
}

int main() {

    std::cout << 1002 % 10 << '\n';

    std::cout << number_to_string(-1022) << '\n';


    return 0;
}