#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

#define POP_SIZE 50
#define MAX_GEN 1000

double fitness(double x, double y) {
    return (1 - x) * (1 - x) + 100 * (y - x * x) * (y - x * x); // Rosenbrock function
}

int main() {
    double population[POP_SIZE][2]; // Each individual has x and y
    srand(time(NULL));

    // Initialize population with random values for x and y
    for (int i = 0; i < POP_SIZE; i++) {
        population[i][0] = ((double)rand() / RAND_MAX) * 4 - 2; // Random x between -2 and 2
        population[i][1] = ((double)rand() / RAND_MAX) * 4 - 2; // Random y between -2 and 2
    }

    for (int gen = 0; gen < MAX_GEN; gen++) {
        // Evaluate fitness
        double best_fit = fitness(population[0][0], population[0][1]);
        int best_index = 0;
        for (int i = 1; i < POP_SIZE; i++) {
            double fit = fitness(population[i][0], population[i][1]);
            if (fit < best_fit) {
                best_fit = fit;
                best_index = i;
            }
        }

        // Reproduction and mutation
        for (int i = 0; i < POP_SIZE; i++) {
            if (i != best_index) {
                population[i][0] = population[best_index][0] + ((double)rand() / RAND_MAX) * 0.1 - 0.05; // Mutation
                population[i][1] = population[best_index][1] + ((double)rand() / RAND_MAX) * 0.1 - 0.05; // Mutation
            }
        }

        if (gen % 100 == 0) {
            printf("Generation %d: Best x = %f, Best y = %f, Fitness = %f\n", gen, population[best_index][0], population[best_index][1], best_fit);
        }
    }
    return 0;
}
