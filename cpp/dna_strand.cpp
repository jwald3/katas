#include <string>
#include <map>

std::string DNAStrand(const std::string& dna)
{
    std::string result = "";
    std::map<char, char> pairs {
        {'A', 'T'},
        {'T', 'A'},
        {'G', 'C'},
        {'C', 'G'}
    };
  
    for (auto c: dna)
    {
        result += pairs[c];
    }
  
    return result;
}
