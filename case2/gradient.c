#include <stdio.h>

double partial_x(double x, double y) {
    return -2 * (1 - x) - 400 * x * (y - x * x); // Partial derivative wrt x
}

double partial_y(double x, double y) {
    return 200 * (y - x * x); // Partial derivative wrt y
}

int main() {
    double x = -1, y = 2; // Initial guess
    double learning_rate = 0.0001;
    int max_iterations = 100000;

    for (int i = 0; i < max_iterations; i++) {
        double grad_x = partial_x(x, y);
        double grad_y = partial_y(x, y);

        x = x - learning_rate * grad_x;
        y = y - learning_rate * grad_y;

        if (i % 10000 == 0) {
            printf("Iteration %d: x = %f, y = %f, f(x, y) = %f\n", i, x, y, (1 - x) * (1 - x) + 100 * (y - x * x) * (y - x * x));
        }
    }
    return 0;
}
