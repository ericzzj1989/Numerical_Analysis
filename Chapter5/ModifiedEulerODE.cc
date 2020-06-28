/* ModifiedEulerODE.cc Modified Euler Method is used for 
 * approximating the solution of the initial-value problem
 * y' = f(y,t), a <= t <= b, y(a) = y0
 * at (n+1) equally spaced numbers in the interval
 * [a, b]: input a, b, n and initial condition y0
*/
#include <iostream>
#include <cmath>
#define F(y,t) (y + 2 * exp(4 * t))

int main(int argc, char **argv) {
    int n{ 100 };
    double h{ 0.01 }, y0{ -3 }, t0{ 0 };
    auto y = y0;
    auto t = t0;

    std::cout << "t  y(t)" << std::endl;
    std::cout << t << "  " << y << std::endl;

    for (auto i = 1; i <= n; ++i) {         
        auto k1 = h * F(y,t);
        auto k2 = h * F((y + k1),(t + h));
        y += (k1 + k2) / 2.0;
        t += h;
        if (i % 10 == 0) {
            std::cout << t << "  " << y << std::endl;
        }
    }

    return 0;
}