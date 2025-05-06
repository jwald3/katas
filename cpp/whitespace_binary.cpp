#include <iostream>
#include <bitset>
#include <cmath>
#include <map>
#include <string>
#include <sstream>

std::string whitespace_number(int n) {
    bool isNegative = n < 0;

    std::map<char, char> conversionMap = {
        {'0', ' '},
        {'1', '\t'}
    };

    std::string binary = std::bitset<64>(abs(n)).to_string();

    int firstSignificantDigit = -1;

    for (int i = 0; i < binary.size(); i++) {
        if (binary[i] == '1') {
            firstSignificantDigit = i;
            break;
        }
    }

    if (firstSignificantDigit == -1) {
        return " \n";
    }

    std::stringstream ss; 

    if (isNegative) {
        ss << '\t';
    } else {
        ss << ' ';
    }

    for (int i = firstSignificantDigit; i < binary.size(); i++) {
        ss << conversionMap[binary[i]];
    }

    ss << '\n';

    return ss.str();
}

int main() {
    int n = 2059877051;
    
    std::string binary = whitespace_number(n);

    std::cout << "the binary is " << binary << '\n';

    return 0;
}