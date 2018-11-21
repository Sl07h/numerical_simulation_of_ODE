#include "methods.h"

template<class T>
std::vector<T> solveDE_Euler_Explicit(double a, double b, double h, T ya, std::function<T(double, T)> f) {
    int n = (b-a)/h;

    std::vector<T> result(n+1, 0);
    result[0] = ya;

    double t_n = a;
    for (int i = 1; i < n+1; ++i) {
        T& y_n1 = result[i];
        T& y_n = result[i-1];

        y_n1 = y_n + h*f(t_n, y_n);

		t_n += h;
    }

    result.erase(result.begin());

    return result;
}
