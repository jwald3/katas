#include <string>
#include <vector>
#include <iostream>

std::string highAndLow(const std::string& numbers){
  std::vector<int> nums {}; 

  std::string currentNumber; 
  
  for (size_t i { 0 }; i < numbers.size(); ++i) {
    if (numbers[i] != ' ') {
      currentNumber += numbers[i];
    }
    
    if (numbers[i] == ' ') {
      nums.push_back(std::stoi(currentNumber));
      currentNumber = "";
    }
  }

  if (currentNumber != ""){
	nums.push_back(std::stoi(currentNumber));
  }
  
  int lowest = nums[0]; 
  int highest = nums[0];
  
  for (const auto &num : nums) {
    if (num > highest) {
      highest = num;
    }
    
    if (num < lowest) {
      lowest = num;
    }
  }
  
  return "" + std::to_string(highest) + " " + std::to_string(lowest);
}

int main() { 

	std::cout << highAndLow("8 3 -5 42 -1 0 0 -9 4 7 4 -4") << '\n';

	return 0; 
}