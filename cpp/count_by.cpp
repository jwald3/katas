#include <vector>
#include <algorithm>

std::vector<int> countBy(int step, int count){
    std::vector<int> vec(count);
  
    std::generate(vec.begin(), vec.end(), 
    // puts n and step as variables accessible within the loop
    // step would be inaccessible if not included in the brackets
    //
    // the "mutable" keyword makes it so n can be modified
        [n = 0, step]() mutable {
            // the first n will be 0 + step, so it will always start with a nonzero #
            return n += step;
        }
    );
  
    return vec;
}