/* Newton-Raphson.cc
 * Newton-Raphson method is used for solving the
 * nonlinear equation f(x) = 0 with initial approximation
 * x0
*/
#include <iostream>
#include <cmath>
#define MAX 50
#define TOL 0.001
#define PI 3.14159
#define f(x) (cos(x) - x)
#define ff(x) (-sin(x) - 1)

int main(int argc, char **argv) {
    double x0{ 1.0 }, x;
    int i;

    for (i = 1; i <= MAX; ++i) {
        x = x0 - f(x0) / ff(x0);
        std::cout << i - 1 << "    " << x0 << std::endl;
        if (fabs(x - x0) < TOL) {
            std::cout << i << " iterations!" << std::endl << "The root = " << x << "    f(" << x << ") = " << f(x) << std::endl;
            return 0;
        } else {
            x0 = x;
        }
    }
    std::cout << "Newton-Raphson method failed after " << i << " iterations!" << std::endl;
    return 0;
}