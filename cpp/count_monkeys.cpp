#include <vector>
#include <numeric>

std::vector<int> MonkeyCount(int n) {
  std::vector<int> numbers(n);
  
  std::iota(numbers.begin(), numbers.end(), 1);
  
  return numbers;
}