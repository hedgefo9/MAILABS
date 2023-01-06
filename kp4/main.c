#include <stdio.h>
#include <math.h>

long double MachineEps() {
    long double eps = 1.0l;
    while (1.0l + eps > 1.0l) {
        eps *= 0.5l;
    }
    return eps;
}

long double fun5(long double x) {
    return sqrtl(1 - x) - tanl(x);
}

long double fun6(long double x) {
    return -cosl(powl(x, 0.52) + 2);
}

long double absl(long double x) {
    if(x < 0) {
        return -x;
    }
    return x;
}

long double dichotomy_method(long double (*f) (long double), long double a, long double b, long double eps) {
    long double root;
    while (fabsl(a - b) > eps) {
        root = (a + b) / 2.0;
        if (f(root) * f(a) < 0) {
            b = root;
        } else {
            a = root;
        }
    }
    return root;
}

long double iter_method(long double (*f) (long double), long double a, long double b, long double eps) {
    long double x0 = (a + b) / 2.0, x = f(x0), diff = x - x0;
    while (absl(diff) >= eps) {
        x = f(x0);
        diff = x - x0;
        x0 = x;
    }
    return x;
}

long double derive(long double (*f)(long double), long double x0) {
    long double delta = 1e-6;
    return (f(x0 + delta) - f(x0)) / delta;
}

int check_is_iter(long double (*f)(long double), long double a, long double b) {
    long double s = (b - a) / 1e4;
    for (long double x = a; x <= b;) {
        if (derive(f, x) >= 1) {
            return 0;
        }
        x += s;
    }
    return 1;
}

int main() {
    long double eps = MachineEps();

    // вариант 5
    long double a = 0.0, b = 1.0;
    long double root = dichotomy_method(fun5, a, b, eps);
    printf("Method: dichotomy, root is: %.20Lf\n", root);

    printf("\n");
    // вариант 6
    a = 0.5, b = 1.0;
    if (check_is_iter(fun6, a, b)) {
        root = iter_method(fun6, a, b, eps);
        printf("Method: iteration, can be applied, root is: %.20Lf\n", root);
    } else {
        printf("Iteration method cannot be applied\n");
    }
}
