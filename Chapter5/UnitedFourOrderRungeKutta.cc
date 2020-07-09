/* UnitedFourOrderRungeKutta.cc based on Fourth-Order Runge-Kutta Method 
 * to approximate the solution of the m order
 * system of first-order initial-value problem
 * y1 = f1(y1, y2, ..., ym, t)
 * y2 = f2(y1, y2, ..., ym, t)
 * ...
 * ym = fm(y1, y2, ..., ym, t)
 * a <= t <= b, y1(a) = y01, y2(a) = y02, ..., ym(a) = y0m
 * at (n+1) equally spaced numbers in the interval [a, b].
*/
#include <iostream>
#include <cmath>
#define f1(y1, y2, t) (y2)
#define f2(y1, y2, t) (-4 * (y1) - 4 * (y2) + 4 * cos(t) + 3 * sin(t))

int main(int argc, char **argv) {
    auto n{ 10 }, m{ 2 };
    auto a{ 0.0 }, b{ 1.0 };
    auto h = (b - a) / n;
    auto t = a;
    double k1[10], k2[10], k3[10], k4[10], y[10], y0[10];

    y0[1] = 1.0;
    y0[2] = 0.0;

    for (auto j = 1; j <= m; ++j) {
        y[j] = y0[j];
    }

    std::cout << "t    y1    y2" << std::endl;
    std::cout << t << "    " << y0[1] << "    " << y0[2] << std::endl;

    for (auto i = 1; i <= n; ++i) {
        for (auto j = 1; j <= m; ++j) {
            if (j == 1) {
                k1[j] = h * f1(y[j], y[j+1], t);
            } else if (j == 2) {
                k1[j] = h * f2(y[j-1], y[j], t);
            }
        }
        for (auto j = 1; j <= m; ++j) {
            if (j == 1) {
                k2[j] = h * f1((y[j] + (k1[j] / 2.0)), (y[j+1] + (k1[j+1] / 2.0)), (t + (h / 2)));
            } else if (j == 2) {
                k2[j] = h * f2((y[j-1] + (k1[j-1] / 2.0)), (y[j] + (k1[j] / 2.0)), (t + (h / 2)));
            }
        }
        for (auto j = 1; j <= m; ++j) {
            if (j == 1) {
                k3[j] = h * f1((y[j] + (k2[j] / 2.0)), (y[j+1] + (k2[j+1] / 2.0)), (t + (h / 2)));
            } else if (j == 2) {
                k3[j] = h * f2((y[j-1] + (k2[j-1] / 2.0)), (y[j] + (k2[j] / 2.0)), (t + (h / 2)));
            }
        }
        for (auto j = 1; j <= m; ++j) {
            if (j == 1) {
                k4[j] = h * f1((y[j] + k3[j]), (y[j+1] + k3[j+1]), (t + h));
            } else if (j == 2) {
                k4[j] = h * f2((y[j-1] + k3[j-1]), (y[j] + k3[j]), (t + h));
            }
        }

        for (auto j = 1; j <= m; ++j) {
            y[j] += (k1[j] + 2 * k2[j] + 2 * k3[j] + k4[j]) / 6;
        }

        t += h;

        std::cout << t << "    " << y[1] << "    " << y[2] << std::endl;
    }
    return 0;
}