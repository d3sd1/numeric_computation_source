import matplotlib.pyplot as plt
import numpy as np

# Data setup for execution time simulation
generations = np.arange(0, 200)
gradient_iterations = np.arange(0, 1000)

# Hypothetical execution times assuming exponential decay to simulate processing time per iteration
genetic_execution_times = 0.05 * np.exp(-generations / 50) + 0.01  # Faster initial decay, stabilizes
gradient_execution_times = 0.02 * np.exp(-gradient_iterations / 200) + 0.005  # Slower decay, longer tail

plt.figure(figsize=(10, 5))
plt.plot(generations, genetic_execution_times, label='Genetic Algorithm', color='blue', marker='o')
plt.plot(gradient_iterations[:200], gradient_execution_times[:200], label='Gradient Descent', color='green', marker='s')
plt.title('Execution Time Comparison')
plt.xlabel('Iterations')
plt.ylabel('Execution Time (seconds)')
plt.legend()
plt.grid(True)
plt.show()