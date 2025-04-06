#include <unordered_map>
#include <algorithm>
#include <limits>
#include <string>

using Ingredients = std::unordered_map<std::string, int>;

/*
    This is a map comparison problem where the "available" map needs to have AT LEAST the contents of the recipe. I iterated over
    recipe and then looked at "available" because available may have more keys, but I only care about what's in recipe.
*/
int cakes(const Ingredients& recipe, const Ingredients& available) {
    int total { std::numeric_limits<int>::max() };

    // iterate over each item in the recipe
    for (auto item: recipe) {        
        int count { 0 };
        
        // see if the item exists in available - if not, the number of cakes will be 0 because a recipe is missing
        auto it = available.find(item.first);
        
        if (it == available.end()) {
            total = 0;
            break;
        } 
        
        // see how many times the recipe qty could go into the available qty
        count = it->second / item.second;
        
        // the total will be the lesser of the current total and the previous step
        total = std::min(total, count);

        // if the total is 0, break
        if (total == 0) break;
    }

    return total;
}