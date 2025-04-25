#include <cassert>
#include <string>

std::string sliceString (std::string str)
{
    // the solution involves assuming that the string has at least 3 characters, so this is the
    // catch to make sure that assumption is valid
    if (str.size() <= 2) {
        return "";
    }

    return str.substr(1, str.size() - 2);
}

int main() {
    
    assert(sliceString("tuna") == "un");
    assert(sliceString("rats") == "at");
    assert(sliceString("code") == "od");
    assert(sliceString("ok") == "");
    
    return 0;
}