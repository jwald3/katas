#include <iostream>
#include <string>
#include <map>

int getCount(const std::string& inputStr)
{
    std::map<char, int> letters {};

    for (int i { 0 }; i < static_cast<int>(inputStr.size()); ++i )
    {
        letters[inputStr[i]] += 1;
    }

    int count { 0 };

    count += letters['a'] + letters['e'] + letters['i'] + letters['o'] + letters['u'];

    return count;
}


int main()
{
    int count { getCount("abracadabra")};

    std::cout << "Vowel count: " << count << '\n';
    
    return 0; 
}