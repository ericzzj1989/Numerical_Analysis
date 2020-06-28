/* SecondOrderRungeKutta.cc Second Order Runge-Kutta Method is used 
 * for solving odinary differential equation of y' = f(y,t) with
 * initial condition of y(t0) = y0.
*/
#include <iostream>
#include <cmath>
#define F(y, t) (-y + t * t + 1)

int main(int argc, char **argv) {
    auto n{ 100 };
    auto a{ 0.0 }, b{ 1.0 };
    auto h = (b - a) / n;
    auto y{ 1.0 };
    auto t = a;

    std::cout << "t  y(t)" << std::endl;
    std::cout << t << "  " << y << std::endl;

    for (auto i = 1; i <= n; ++i) {
        auto k1 = h * F(y, t);
        auto k2 = h * F((y + k1), (t + h));
        y += (k1 + k2) / 2.0;
        t = t + h;
        if (i % 10 == 0) {
            std::cout << t << "  " << y << std::endl;
        }
    }
    return 0;
}