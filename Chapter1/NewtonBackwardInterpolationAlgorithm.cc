/* NewtonBackwardInterpolationAlgorithm.cc is for developing the divided-difference
 * table for Newton Backward Interpolation polynomial
*/

#include <iostream>
#include <fstream>
using std::ifstream;

int main(int argc, char **argv) {
    int n;
    std::cin >> n;

    double x[40] = {0};
    double f[40][40] = {0};
    ifstream infile;
    infile.open("data_NewtonBackward.txt");
    for (auto m = 0; m <= n; ++m) {
        for (auto k = 0; k < 2; ++k) {
            if (k == 0) {
                infile >> x[m];
                // std::cout << x[m] << std::endl;
            } else {
                infile >> f[m][0];
                // std::cout << f[m][0] << std::endl;
            }
        }
    }

    for (auto j = 1; j <= n; ++j) {
        for (auto i = j; i <= n; ++i) {
            f[i][j] = (f[i][j - 1] - f[i - 1][j - 1]) / (x[i] - x[i - j]);
        }
    }

    std::cout << "i x(i) f(i), f(i-1, i) f(i-2, i-1, i), ......" << std::endl;

    for (auto i = 0; i <= n; ++i) {
        std::cout << i << "    " << x[i];
        for (auto j = 0; j <= i; ++j) {
            std:: cout << "    " << f[i][j];
        }
        std::cout << std::endl;
    }

    return 0;
}
