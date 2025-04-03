#include <iostream>
#include <vector>
#include <numeric>

int positive_sum_basic(const std::vector<int> arr) {
    int sum = 0;

	// this is the "basic" way to do it. we aren't modifying the arr value,
	// so it can be const. 
	for (const auto &i : arr) {
		if (i > 0) {
			sum += i;
		}
	}

	return sum;
}

int positive_sum_accumulate(const std::vector<int> arr) {
    int sum = 0;

	// accumulate allows a reduce-style functional approach.
	// the fourth argument allows users to define a lambda function
	// we use iteratively over the collection.
	return std::accumulate(
		arr.begin(), 					// include items starting from the first index
		arr.end(), 						// include items up to the last index
		0, 								// accumulate starting with 0
		[](int a, int b) {
			return a + std::max(0, b);	// add only positive values to the returned value
		}
	);

	return sum;
}

int main() {
    int posSum = positive_sum_accumulate({1, 2, 3, 4, 5});

    std::cout << posSum << '\n';

    return 0;
}