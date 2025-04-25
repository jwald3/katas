#include <cassert>
#include <string>

std::string sliceString (std::string str)
{
    return str.substr(1, str.size() - 2);
}

int main() {
    
    assert(sliceString("tuna") == "un");
    assert(sliceString("rats") == "at");
    assert(sliceString("code") == "od");
    assert(sliceString("ok") == "");
    
    return 0;
}