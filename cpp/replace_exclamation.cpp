#include <algorithm>
#include <string>

std::string removeExclamationMarks(std::string str) {
    // std::remove shifts all characters that are not '!' to the front of the
    // string and returns an iterator pointing to the end of the non-'!' characters
    str.erase(
        std::remove(
            str.begin(), str.end(),
            '!')
        ,
        str.end());  // erase takes the pointer from the remove operation and erases up until the end of the string.

    // for example, starting from "Hello!! World!":
    //   after remove(): front of str == "Hello World", iterator points just past 'd',
    //     the “removed” '!'s make up the tail we'll erase from the "remove" pointer to the normal end of the string. 
    //   after erase(): str == "Hello World"

    return str;
}