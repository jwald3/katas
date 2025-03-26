#include <iostream>
#include <string>
#include <vector>
#include <set>

std::string longest(std::string &s1, std::string &s2)
{
    std::set<char> s(s1.begin(), s1.end());

    for (auto c: s2)
    {
        s.insert(c);
    }

    return std::string(s.begin(), s.end());
}

int main()
{
    std::string s1 { "loopingisfunbutdangerous" };
    std::string s2 { "lessdangerousthancoding" };

    std::string str { longest(s1, s2)};

    std::cout << "The resulting string is " << str << '\n';

    return 0;
}