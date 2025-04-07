#include <iostream>
#include <cmath>

struct Point {
    int x;
    int y;
};

struct Triangle {
    Point a;
    Point b;
    Point c;
};

double triangle_perimeter(const Triangle& t){
    double abDist = std::sqrt(std::pow((t.a.x - t.b.x), 2) + (std::pow((t.a.y - t.b.y), 2)));
    double bcDist = std::sqrt(std::pow((t.b.x - t.c.x), 2) + (std::pow((t.b.y - t.c.y), 2)));
    double caDist = std::sqrt(std::pow((t.c.x - t.a.x), 2) + (std::pow((t.c.y - t.a.y), 2)));
    
    return abDist + bcDist + caDist;
}

int main() {
    Triangle triangle { Point{10, 10}, Point{40, 10}, Point{10, 50}};

    std::cout << "The perimeter is " << triangle_perimeter(triangle) << '\n';

    return 0;
}