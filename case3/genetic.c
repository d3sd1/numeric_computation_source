#include <stdio.h>
#include <math.h>

double f(double x, double y) {
    return pow(x * x + y - 11, 2) + pow(x + y * y - 7, 2);
}

double df_dx(double x, double y) {
    return 2 * (2 * x * (x * x + y - 11) + x + y * y - 7);
}

double df_dy(double x, double y) {
    return 2 * (x * x + y - 11 + 2 * y * (y * y + x - 7));
}

int main() {
    double x = -4; // Starting guess for x
    double y = -4; // Starting guess for y
    double learning_rate = 0.01;
    int max_iter = 1000;
    double x_new, y_new;

    for (int i = 0; i < max_iter; i++) {
        x_new = x - learning_rate * df_dx(x, y);
        y_new = y - learning_rate * df_dy(x, y);
        x = x_new;
        y = y_new;
        printf("Iteration %d: x = %f, y = %f, f(x, y) = %f\n", i, x, y, f(x, y));
    }

    return 0;
}
