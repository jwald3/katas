#include <string>

std::string reverse_letter(const std::string &str)
{
    std::string res = "";
  
    for (int i = int(str.size()) - 1; i >= 0; i--) {
      char c = str[i];
      if (c >= 'a' && c <= 'z') {
        res += c;
      }
    }
  
    return res;
}