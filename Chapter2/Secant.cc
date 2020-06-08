/* Secant.cc
 * Secant method is similar to Newton-Raphson 
 * method used for find solution to f(x) = 0
 * given initial approximations x0 and x1
*/
#include <iostream>
#include <cmath>
#define MAX 50
#define TOL 0.00001
#define f(x) (exp(x) + 1 / pow(2, x) + 2 * cos(x) - 6)

int main(int argc, char **argv) {
    int i{ 2 };
    double x0{ 1.8 }, x1{ 2.0 };
    double x;
    std::cout << "i    xi    f(x)" << std::endl;
    std::cout << 0 << "    " << x0 << "    " << f(x0) << std::endl;
    std::cout << 1 << "    " << x1 << "    " << f(x1) << std::endl;

    while (i <= MAX) {
        x = x1 - f(x1) * (x1 - x0) / (f(x1) - f(x0));
        std::cout << i << "    " << x << "    " << f(x) << std::endl;
        if (fabs(x - x0) < TOL) {
            std::cout << i - 1 << " iterations!" << std::endl << "The root = " << x << "    f(" << x << ") = " << f(x) << std::endl;
            return 0;
        } else {
            ++i;
            x0 = x1;
            x1 = x;
        }
    }
    std::cout << "Secant method failed after " << i - 1 << " iterations!" << std::endl;

    return 0;
}