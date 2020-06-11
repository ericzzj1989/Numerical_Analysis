/* TrapezoidolRule.cc
 * Trapezoidol Rule is used for computing definite integral 
 * with domain [a, b] with n even-grids.
*/
#include <iostream>
#include <cmath>
#define PI 3.1415926
#define f(x) (1.0 / exp(x * x / 2))

int main(int argc, char **argv) {
    auto sum{ 0.0 };
    int n;
    double a, b, x, tn, h;
    std::cin >> n >> a >> b;

    h = (b - a) / n;
    x = a;

    for (auto i = 1; i <= n - 1; ++i) {
        x += h;
        sum += f(x);
    }

    tn = (1.0 / sqrt(2 * PI)) * (h / 2) * (f(a) + f(b) + 2 * sum);
    std::cout << "T = " << tn << std::endl;
    return 0;
}