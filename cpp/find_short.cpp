#include <cassert>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <climits>

int find_short(std::string str)
{
    // "istringstream" is input-only streaming
    std::istringstream ss(str);
    std::string word;
    size_t len = str.length();  // the word can never be longer than the string containing it

    while(std::getline(ss, word, ' ')) {
        if (word.length() < len) {
            len = word.length();
        }
    }

    return static_cast<int>(len);
}

int main() {
    
    assert(find_short("bitcoin take over the world maybe who knows perhaps") == 3);
    assert(find_short("turns out random test cases are easier than writing out basic ones") == 3);
    assert(find_short("lets talk about javascript the best language") == 3);
    assert(find_short("i want to travel the world writing code one day") == 1);
    assert(find_short("Lets all go on holiday somewhere very cold") == 2);
    assert(find_short("Let's travel abroad shall we") == 2);
    
    return 0;
}