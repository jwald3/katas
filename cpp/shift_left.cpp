#include <iostream>
#include <string>

long long shiftLeft(std::string s, std::string t){
    std::string longer = s.size() > t.size() ? s : t;
    std::string shorter = longer == s ? t : s;
	long long count = 0;

    if (longer == shorter) {
        return 0;
    }

    size_t sizeDiff = longer.size() - shorter.size();
  
    longer.erase(0, static_cast<int>(sizeDiff));
	count = static_cast<long>(sizeDiff);

    if (longer == shorter) {
        return count;
    }

	while (longer.size() > 0) {
		longer.erase(0, 1);
		shorter.erase(0, 1);

		count += 2;
		if (longer == shorter) {
			return count;
		}
	}
    
    return count;
}

int main() {
	long long result = shiftLeft("test", "yes");

	std::cout << "Result is " << result << '\n';
}