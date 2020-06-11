/* SimpsonRule.cc
 * Simpson's Rule is used for computing definite integral 
 * with domain [a, b] with n even-grids. n must be even;
*/
#include <iostream>
#include <cmath>
#define PI 3.1415926
#define f(x) pow((1 + pow(x, 3)), 2.0 / 3)

int main(int argc, char **argv) {
    auto sum1{ 0.0 }, sum2{ 0.0 };
    int n;
    double a, b, x, sn, h;
    std::cin >> n >> a >> b;

    h = (b - a) / n;
    x = a;

    for (auto i = 1; i <= n - 1; ++i) {
        x += h;
        if (i % 2) {
            sum1 += f(x);
        } else {
            sum2 += f(x);
        }
    }

    sn = PI * (h / 3.0) * (f(a) + f(b) + 2.0 * sum2 + 4.0 * sum1);
    std::cout << "S = " << sn << std::endl;
    return 0;
}