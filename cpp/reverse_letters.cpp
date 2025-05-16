#include <string>

std::string reverse_letter(const std::string &str)
{
    std::string res = "";
  
    // you can't do size_t (the natural type for str.size()) because `-1` overflows. 
    // cast to int to allow a case where `i >= 0` will eventually be false
    for (int i = int(str.size()) - 1; i >= 0; i--) {
      char c = str[i];
      if (c >= 'a' && c <= 'z') {
        res += c;
      }
    }
  
    return res;
}