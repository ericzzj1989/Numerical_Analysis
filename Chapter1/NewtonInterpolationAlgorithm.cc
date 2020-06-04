/* ex1-9.cc is for developing the divided-difference
 * table for Newton Interpolation polynomial
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
    infile.open("data_Newton.txt");
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
        for (auto i = 0; i <= n - j; ++i) {
            f[i][j] = (f[i + 1][j - 1] - f[i][j - 1]) / (x[i + j] - x[i]);
        }
    }

    std::cout << "i x(i) f(i), f(i, i+1) f(i, i+1, i+2), ......" << std::endl;

    for (auto i = 0; i <= n; ++i) {
        std::cout << i << "    " << x[i];
        for (auto j = 0; j <= n - i; ++j) {
            std:: cout << "    " << f[i][j];
        }
        std::cout << std::endl;
    }

    return 0;
}
