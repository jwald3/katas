#include <string>
#include <iostream>

std::string createPhoneNumber(const int arr [10]){
  std::string areaCode = "";
  std::string exchangeCode = "";
  std::string line = "";
  
  
  for (int i { 0 }; i < 10; ++i) {
    if (i < 3) {
      areaCode += ('0' + arr[i]);
    } else if (i < 6) {
      exchangeCode += ('0' + arr[i]);
    } else {
      line += ('0' + arr[i]);
    }
  }
  
  
  return "(" + areaCode + ") " + exchangeCode + "-" + line;
}

int main() {
    using arr = int [10];
    
    std::string number = createPhoneNumber(arr{1, 2, 3, 4, 5, 6, 7, 8, 9, 0});

    std::cout << "number: " << number << '\n';

    return 0;
}