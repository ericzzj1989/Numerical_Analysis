/* DoubleIntegral.cc
 * Trapezoidol Rule is used for computing the double integral.
*/
#include <iostream>
#include <cmath>
#define F(x,y) (4 * x * y)
#define C(x) (0)
#define D(x) (1 - pow(x, 2))
double x[50], hy[50], y[50][50], g[50];

void gy(const int &n) {
    double sum{ 0.0 };
    for (auto i = 0; i <= n; ++i) {
        for (auto j = 1; j < n; ++j) {
            sum += F(x[i], y[i][j]);
        }
        g[i] = hy[i] / 2.0 * ( F(x[i], y[i][0]) + F(x[i], y[i][n]) + 2 * sum );
        sum = 0.0;
    }

    return;
}

int main(int argc, char **argv) {
    int n;
    double a, b, hx, ts, sum{ 0.0 };
    std::cin >> n >> a >> b;

    hx = (b - a) / n;

    for (auto i = 0; i <= n; ++i) {
        x[i] = a + i * hx;
        hy[i] = (D(x[i]) - C([i])) / n;

        for (auto j = 0; j <= n; ++j) {
            y[i][j] = C(x[i]) + j * hy[i];
        }
    }

    gy(n);

    for (auto i = 1; i < n; ++i) {
        sum += g[i];
    }

    ts = hx / 2.0 * (g[0] + g[n] + 2 * sum);

    std::cout << "T" << n << " = " << ts << std::endl;

    return 0;
}