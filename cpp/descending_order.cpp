#include <iostream>
#include <string>
#include <cinttypes>
#include <sstream>

uint64_t descendingOrder(uint64_t a)
{
    std::ostringstream stringValue;
    stringValue << a;
    std::string str { stringValue.str() };

    int strLen { static_cast<int>(str.length()) };
    bool swapped { false };

    for (int i {0}; i < strLen - 1; ++i) 
    {
        swapped = false;
        
            for (int j {0}; j < strLen - i - 1; ++j)
            {
                    if (str[j] < str[j+1])
                    {
                        char val = str[j];
                        str[j] = str[j+1];
                        str[j+1] = val;

                        swapped = true;
                    }
            }

        if (!swapped)
        {
            break;
        }
    }
    
    uint64_t casted = std::stoul(str, 0, 10);

    return casted;
}