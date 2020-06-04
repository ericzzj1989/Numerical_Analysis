/* HermiteInterpolationAlgorithm.cc To generate the coefficients for
 * Hermite Interpolating Polynomial H on the distinct numbers
 * x0, x1, x2, ... with f0, f1, f2, ... and f'0, f'1, f'2, ...
 * based on the Newton backward divided-difference Algorithm
 * and output the divided_difference table for Hn(x).
*/
#include <iostream>
#include <fstream>
using std::ifstream;

int main(int argc, char **argv) {
    int n;
    std::cin >> n;

    double x[30] = { 0 };
    double f[30] = { 0 };
    double ff[30] = { 0 };
    double z[59] = { 0 };
    double q[59][59] = { 0 };
    ifstream infile;
    infile.open("data_Hermite.txt");
    for (auto m = 0; m <= n; ++m) {
        for (auto k = 0; k < 3; ++k) {
            if (k == 0) {
                infile >> x[m];
                // std::cout << x[m] << std::endl;
            } else if (k == 1) {
                infile >> f[m];
                // std::cout << f[m][0] << std::endl;
            } else if (k == 2) {
                infile >> ff[m];
            }
        }
    }

    std::cout << "i    z(i)    f(i)    f(i-1,i)    f(i-2,i-1,i)..." << std::endl;

    for (auto i = 0; i <= n; ++i) {
        z[2 * i] = x[i];
        z[2 * i + 1] = x[i];
        q[2 * i][0] = f[i];
        q[2 * i + 1][0] = f[i];
        q[2 * i + 1][1] = ff[i];

        if (i != 0) {
            q[2 * i][1] = (q[2 * i][0] - q[2 * i - 1][0]) / (z[2 * i] - z[2 * i - 1]);
        }

        if (i == 0) {
            std::cout << i << "    " << z[i] << "    " << q[i][0] << std::endl;
        } else if (i == 1) {
            std::cout << i << "    " << z[i] << "    " << q[i][0]  << "    " <<  q[i][1] << std::endl;
        }
    }

    for (auto i = 2; i <= (2 * n + 1); ++i) {
        std::cout << i << "    " << z[i] << "    " << q[i][0]  << "    " <<  q[i][1];
        for (auto j = 2; j <= i; ++j) {
            q[i][j] = (q[i][j - 1] - q[i - 1][j - 1]) / (z[i] - z[i - j]);
            std::cout << "    " << q[i][j];
        }
        std::cout << std::endl;
    }
    
    
    return 0;
}