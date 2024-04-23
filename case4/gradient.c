#include <stdio.h>
#include <math.h>

double rastrigin(double x, double y) {
    return 20 + (x*x - 10*cos(2*M_PI*x)) + (y*y - 10*cos(2*M_PI*y));
}

double grad_x(double x) {
    return 2*x + 20*M_PI*sin(2*M_PI*x);
}

double grad_y(double y) {
    return 2*y + 20*M_PI*sin(2*M_PI*y);
}

int main() {
    double x = -2.0, y = -2.0;  // Initial guess
    double learning_rate = 0.01;
    int max_iterations = 1000;

    for (int i = 0; i < max_iterations; i++) {
        x -= learning_rate * grad_x(x);
        y -= learning_rate * grad_y(y);
        printf("Iteration %d: x = %f, y = %f, f(x, y) = %f\n", i, x, y, rastrigin(x, y));
    }

    return 0;
}
