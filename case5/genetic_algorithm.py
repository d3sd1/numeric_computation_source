import numpy as np
import matplotlib.pyplot as plt
import random

# Coordinates for Madrid and London
madrid = np.array([40.4168, -3.7038])
london = np.array([51.5074, -0.1278])

# Genetic Algorithm parameters
population_size = 100
mutation_rate = 0.01
generations = 1000

# Function to calculate the distance of a route
def route_distance(route):
    return np.linalg.norm(route - london)

# Generate initial population
def initial_population(pop_size):
    return [np.random.uniform(low=30, high=60, size=2) for _ in range(pop_size)]

# Selection function
def selection(population):
    population = sorted(population, key=lambda x: route_distance(x))
    return population[:int(len(population)/2)]

# Crossover function
def crossover(parent1, parent2):
    child = (parent1 + parent2) / 2
    return child

# Mutation function
def mutate(route):
    if np.random.rand() < mutation_rate:
        route += np.random.uniform(low=-1, high=1, size=2)
    return route

# Genetic Algorithm
def genetic_algorithm(start, end, pop_size, generations):
    population = initial_population(pop_size)
    best_route = start
    for generation in range(generations):
        population = selection(population)
        next_population = []
        while len(next_population) < pop_size:
            parent1, parent2 = random.sample(population, 2)
            child1 = mutate(crossover(parent1, parent2))
            child2 = mutate(crossover(parent1, parent2))
            next_population.append(child1)
            next_population.append(child2)
        population = next_population[:pop_size]  # Ensure population size remains constant
        best_route = sorted(population, key=lambda x: route_distance(x))[0]
    return best_route

# Run Genetic Algorithm
best_route = genetic_algorithm(madrid, london, population_size, generations)

# Plotting the convergence
population = initial_population(population_size)
distances = [route_distance(route) for route in population]
plt.plot(distances)
plt.xlabel('Generation')
plt.ylabel('Distance to London')
plt.title('Convergence of Genetic Algorithm')
plt.savefig('convergence_ga.png')
plt.show()

# Plotting the final routes
plt.figure()
plt.plot([madrid[0], london[0]], [madrid[1], london[1]], 'ro-', label='Gradient Descent')
plt.plot([madrid[0], best_route[0]], [madrid[1], best_route[1]], 'bo-', label='Genetic Algorithm')
plt.xlabel('Latitude')
plt.ylabel('Longitude')
plt.legend()
plt.title('Final Routes Found by GD and GA')
plt.savefig('final_routes.png')
plt.show()
