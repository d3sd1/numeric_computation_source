#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define POP_SIZE 100
#define MAX_GEN 200
#define GENOME_LENGTH 2
#define MUTATION_RATE 0.01
#define CROSSOVER_RATE 0.7
#define PI 3.14159265358979323846

typedef struct {
    double gene[GENOME_LENGTH];
    double fitness;
} Individual;

Individual population[POP_SIZE];
Individual new_population[POP_SIZE];

double rastrigin(Individual ind) {
    double sum = 10 * GENOME_LENGTH;
    for (int i = 0; i < GENOME_LENGTH; i++) {
        sum += ind.gene[i] * ind.gene[i] - 10 * cos(2 * PI * ind.gene[i]);
    }
    return sum;
}

void initialize_population() {
    for (int i = 0; i < POP_SIZE; i++) {
        for (int j = 0; j < GENOME_LENGTH; j++) {
            population[i].gene[j] = ((double)rand() / (double)(RAND_MAX)) * 10.24 - 5.12; // Range [-5.12, 5.12]
        }
        population[i].fitness = rastrigin(population[i]);
    }
}

void evaluate() {
    for (int i = 0; i < POP_SIZE; i++) {
        population[i].fitness = rastrigin(population[i]);
    }
}

int select_parent() {
    double total_fitness = 0;
    for (int i = 0; i < POP_SIZE; i++) {
        total_fitness += population[i].fitness;
    }
    double slice = (double)rand() / (double)(RAND_MAX) * total_fitness;
    double fitness_so_far = 0;
    for (int i = 0; i < POP_SIZE; i++) {
        fitness_so_far += population[i].fitness;
        if (fitness_so_far >= slice) {
            return i;
        }
    }
    return 0;
}

void crossover(Individual parent1, Individual parent2, Individual *child1, Individual *child2) {
    if ((double)rand() / (double)(RAND_MAX) < CROSSOVER_RATE) {
        int crossover_point = rand() % GENOME_LENGTH;
        for (int i = 0; i < crossover_point; i++) {
            child1->gene[i] = parent1.gene[i];
            child2->gene[i] = parent2.gene[i];
        }
        for (int i = crossover_point; i < GENOME_LENGTH; i++) {
            child1->gene[i] = parent2.gene[i];
            child2->gene[i] = parent1.gene[i];
        }
    } else {
        *child1 = parent1;
        *child2 = parent2;
    }
}

void mutate(Individual *ind) {
    for (int i = 0; i < GENOME_LENGTH; i++) {
        if ((double)rand() / (double)(RAND_MAX) < MUTATION_RATE) {
            ind->gene[i] += ((double)rand() / (double)(RAND_MAX) * 2 - 1); // Small mutation
        }
    }
}

void generate_new_population() {
    for (int i = 0; i < POP_SIZE; i += 2) {
        int parent1_index = select_parent();
        int parent2_index = select_parent();
        crossover(population[parent1_index], population[parent2_index], &new_population[i], &new_population[i + 1]);
        mutate(&new_population[i]);
        mutate(&new_population[i + 1]);
        new_population[i].fitness = rastrigin(new_population[i]);
        new_population[i + 1].fitness = rastrigin(new_population[i + 1]);
    }
    for (int i = 0; i < POP_SIZE; i++) {
        population[i] = new_population[i];
    }
}

int main() {
    srand(time(NULL));
    initialize_population();
    for (int gen = 0; gen < MAX_GEN; gen++) {
        evaluate();
        generate_new_population();
        printf("Generation %d: Best Fitness = %f\n", gen, population[0].fitness);
    }
    return 0;
}
