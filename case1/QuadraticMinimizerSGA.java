package case1;

import java.util.Random;

public class QuadraticMinimizerSGA {
    static Random random = new Random();
    static final int populationSize = 100;
    static final int maxGenerations = 100;
    static final double mutationRate = 0.01;
    static final double crossoverRate = 0.7;
    static final double domainMin = -10.0;
    static final double domainMax = 10.0;

    // Fitness evaluation for f(x) = x^2
    private static double evaluateFitness(double x) {
        return x * x;
    }

    // Crossover (simple averaging for demonstration)
    private static double crossover(double parent1, double parent2) {
        if (random.nextDouble() < crossoverRate) {
            return (parent1 + parent2) / 2.0;
        }
        return random.nextBoolean() ? parent1 : parent2;
    }

    // Mutation (small random change)
    private static double mutate(double x) {
        if (random.nextDouble() < mutationRate) {
            return x + random.nextDouble() * 2 - 1; // Small mutation
        }
        return x;
    }

    public static void run() {
        double[] population = new double[populationSize];
        double[] fitness = new double[populationSize];

        // Initialize population with random individuals
        for (int i = 0; i < populationSize; i++) {
            population[i] = domainMin + random.nextDouble() * (domainMax - domainMin);
        }

        // Evolution loop
        for (int generation = 0; generation < maxGenerations; generation++) {
            // Evaluate fitness
            for (int i = 0; i < populationSize; i++) {
                fitness[i] = evaluateFitness(population[i]);
            }

            // Selection and reproduction (simplified)
            double[] newPopulation = new double[populationSize];
            for (int i = 0; i < populationSize; i += 2) {
                // Select two parents (simplified to random selection)
                int parent1Index = random.nextInt(populationSize);
                int parent2Index = random.nextInt(populationSize);
                double parent1 = population[parent1Index];
                double parent2 = population[parent2Index];

                // Crossover
                double offspring1 = crossover(parent1, parent2);
                double offspring2 = crossover(parent1, parent2);

                // Mutation
                offspring1 = mutate(offspring1);
                offspring2 = mutate(offspring2);

                // Add to new population
                newPopulation[i] = offspring1;
                if (i + 1 < populationSize) {
                    newPopulation[i + 1] = offspring2;
                }
            }

            // Replace old population with new population
            population = newPopulation;
        }

        // Find best solution
        double bestSolution = population[0];
        double bestFitness = evaluateFitness(population[0]);
        for (int i = 1; i < populationSize; i++) {
            double currentFitness = evaluateFitness(population[i]);
            if (currentFitness < bestFitness) {
                bestFitness = currentFitness;
                bestSolution = population[i];
            }
        }

        System.out.println("Best solution: x = " + bestSolution + ", f(x) = " + bestFitness);
    }
}
