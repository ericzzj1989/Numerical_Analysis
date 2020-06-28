/* ForwardEulerODE.cc Forward Euler Method is used for 
 * solving y' = f(y,t) of first order
 * ordinary differential equation
 * with initial condition y(0) = y0
 * known.
*/
#include <iostream>
#include <cmath>
#define F(y,t) (y + 2 * exp(4 * t))

int main(int argc, char **argv) {
    int n{ 10000 };
    double h{ 0.0001 }, y0{ -3 }, t0{ 0 };
    auto y = y0;
    auto t = t0;

    std::cout << "t  y(t)" << std::endl;
    std::cout << t << "  " << y << std::endl;

    for (auto i = 1; i <= n; ++i) {
        y += h * F(y,t);
        t += h;
        if (i % 1000 == 0) {
            std::cout << t << "  " << y << std::endl;
        }
    }
    return 0;
}