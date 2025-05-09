#include <iostream>
#include <regex>
#include <string>
#include <array>

// marking this as a static variable means that the program won't need to recompile any time we call it
// marking it as a const ensures more safety and promotes expressiveness
static const std::regex pattern(R"((\d+):(\d+))");

class Match {
   private:
    int X = 0;
    int Y = 0;

   public:
    Match(const std::string& v) {
        std::smatch matches;

        if (std::regex_match(v, matches, pattern)) {
            // the matches include the matched string at idx 0 and then the following indices
            // include the actual captured values (i.e., d+ which would include one or more digits)
            X = std::stoi(matches[1]);
            Y = std::stoi(matches[2]);
        } else {
            std::cerr << "failed to match pattern: " << v << std::endl;
        }
    }

    // the getters are const because nothing's modified in either call
    int getX() const {
        return X;
    }

    int getY() const {
        return Y;
    }
};

int points(const std::array<std::string, 10>& games) { 
    int points = 0;

    // build matches and use the class's features to determine game results
    for (const auto& g: games) {
        auto match = Match{g};
        int x = match.getX();
        int y = match.getY();

        if (x > y) {
            points += 3;
        } else if (x == y) {
            points += 1;
        }
    }

    return points;
}


int main() {
    auto games = std::array<std::string, 10>{"1:0","2:0","3:0","4:0","2:1","3:1","4:1","3:2","4:2","4:3"};

    int results = points(games);

    std::cout << "Points is " << results << '\n';

    return 0;
}