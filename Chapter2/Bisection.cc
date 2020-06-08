/* Bisection.cc
 * Bisection method is used for solving the
 * nonlinear equation f(x) = 0, its root is between a and b
*/
#include <iostream>
#include <cmath>
#define MAX 50
#define TOL 0.001
#define f(x) (0.0000115 * pow(x, 2) + 0.000014 * pow(x, 1.5) - 0.01962)

int main(int argc, char **argv) {
    double x, a{ 37 }, b{ 38 }, p, h;
    int i{ 1 };

    std::cout << "i    a(i)    b(i)    p(i)    f(p(i))    h(i)" << std::endl;

    while (i <= MAX) {
        p = (a + b) / 2;
        h = fabs(b - a) / 2;
        std::cout << i << "    " << a << "    " << b << "    " << p << "    " << f(p) << "    " << h << std::endl;

        if (f(p) == 0 || h < TOL) {
            std::cout << i << " iterations!" << std::endl << "The root = " << p << "    f(" << p << ") = " << f(p) << std::endl;
            return 0;
        } else {
            if (f(p) * f(a) > 0) {
                a = p;
                ++i;
            } else if (f(p) * f(b) > 0){
                b = p;
                ++i;
            }
        }
    }
    std::cout << "Bisection method failed after " << i << " iterations!" << std::endl;

    return 0;
}