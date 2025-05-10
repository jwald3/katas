#include <stdexcept>

class Guesser {
public:
    Guesser(int number, int lives) : number(number), lives(lives){ }
  
    bool guess(int n) {
        if (lives == 0) {
            throw std::runtime_error("cannot guess more than the limit");
        }
      
        if (n == number) {
            return true;
        } else {
          lives--;
          return false;
        }
    }

private:
    int number, lives;
};