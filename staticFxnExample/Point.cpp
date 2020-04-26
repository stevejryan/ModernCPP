#include <cmath>
#include <iostream>

using namespace std;


class Point {
    public:
        Point(int x, int y) : x_{x}, y_{y} {} // constructor
        static float Distance(const Point& a, const Point& b) {
            float x_diff = a.x_ - b.x_;
            float y_diff = a.y_ - b.y_;
            return sqrt(x_diff * x_diff + y_diff * y_diff);
        }
        
    private:
        int x_ = 0;
        int y_ = 0;
};

int main() {
    Point a(1, 1);
    Point b(2, 2);
    cout << "Distance: " << Point::Distance(a, b) << endl;
}
