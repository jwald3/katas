#include <string>
#include <iostream>

std::string createPhoneNumber(const int arr[10])
{
    // a template built with a single, consistent value to replace
    std::string temp = "(xxx) xxx-xxxx";

    // the pointer to the array index (rather than the template index)
    // need this for ensuring each "x" gets replaced
    int i = 0;

    // don't need a int i = 0... loop because index is unimportant here
    for (auto &x : temp)
    {
        if (x == 'x')
        {
            x = arr[i++] + '0';
        }
    }

    return temp;
}

int main()
{
    using arr = int[10];

    std::string number = createPhoneNumber(arr{1, 2, 3, 4, 5, 6, 7, 8, 9, 0});

    std::cout << "number: " << number << '\n';

    return 0;
}