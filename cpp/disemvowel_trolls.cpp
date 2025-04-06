# include <iostream>
# include <string>
# include <algorithm>
# include <regex>

std::string disemvowel(const std::string& str) {
    std::string result;
    std::copy_if(str.begin(), str.end(), std::back_inserter(result), 
                [](char c) {
                    return !(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
                             c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
                });
  
    return result;
}

std::string disemvowel_regex(const std::string& str) {
    std::regex vowels("[aeiouAEIOU]");
    return std::regex_replace(str, vowels, "");
}



int main() {
    std::cout << disemvowel_regex("This website is for losers LOL!") << '\n';

    return 0;
}