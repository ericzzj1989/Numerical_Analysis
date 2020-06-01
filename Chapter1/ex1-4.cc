/* ex1-4.cc: Lagrange Interpolation Algorithm
 * Read in data file of data1/2/3.txt which has n point values
 * and the value of interpolating point xa. Based on Lagrange
 * Interpolation algorithm to compute f(xa) and output its value.
 * (data[i][0], data[i][1]): gievn points and n+1 are number of points
 * and x[i] = data[i][0], f[i] = data[i][1]
 * Ln, k(x) = l = summation of (x - x[i]) / (x[k] - x[i]).
 * P(x) = ff = L(x) * f(x[k])
*/

#include <iostream>
#include <fstream>
using std::ifstream;

int main(int argc, char **argv)
{
    double l, ff, xa;
    int n;
    std::cin >> n;
    std::cin >> xa;

    double data[30][2] = {0};
    ifstream infile;
    infile.open("data3.txt");
    for (int m = 0; m <= n; ++m) {
        for (int j = 0; j < 2; ++j) {
            infile >> data[m][j];
            // std::cout << data[m][j] << std::endl;
        }
    }

    ff = 0.0;
    for (int k = 0; k <= n; ++k) {
        l = 1.0;
        for(int i = 0; i <= n; ++i) {
            if (i != k) {
                l *= (xa - data[i][0]) / (data[k][0] - data[i][0]);
            }
        }
        ff += l * data[k][1];
    }

    std::cout << "The value of P(" << xa << ") = " << ff << std::endl;

    return 0;
}
