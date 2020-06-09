/* Fixed-Point.cc
 * Fixed-Point method is used for solving nonlinear equation
 * based on Fixed-Point Algorithm g(x) = x with initial
 * approximation x0
 * x0
*/
#include <iostream>
#include <cmath>
#define MAX 50
#define TOL 0.0001
#define g(x) (1 / (pow(5, x)))

int main(int argc, char **argv) {
    int i{ 1 };
    double x0{ 0.45 }, x1;

    while (i <= MAX) {
        x1 = g(x0);
        std::cout << i - 1 << "    " << x0 << std::endl;
        if (fabs(x1 - x0) < TOL) {
            std::cout << i << " iterations!" << std::endl << "The root = " << x0 << std::endl;
            return 0;
        } else {
            ++i;
            x0 = x1;
        }
    }
    std::cout << "Fixed-point failed after " << i << " iterations!" << std::endl;
    return 0;
}