import numpy as np
import matplotlib.pyplot as plt

# Coordinates for Madrid and London
madrid = np.array([40.4168, -3.7038])
london = np.array([51.5074, -0.1278])

# Learning rate
alpha = 0.01
# Maximum iterations
max_iter = 1000

# Cost function: Euclidean distance
def cost_function(point, destination):
    return np.linalg.norm(point - destination)

# Gradient function
def gradient(point, destination):
    return (point - destination) / np.linalg.norm(point - destination)

# Gradient Descent algorithm
def gradient_descent(start, end, alpha, max_iter):
    path = [start]
    current_point = start
    for _ in range(max_iter):
        grad = gradient(current_point, end)
        next_point = current_point - alpha * grad
        path.append(next_point)
        if np.linalg.norm(next_point - end) < 1e-3:
            break
        current_point = next_point
    return path

# Run Gradient Descent
gd_path = gradient_descent(madrid, london, alpha, max_iter)

# Plotting the convergence
distances = [cost_function(p, london) for p in gd_path]
plt.plot(distances)
plt.xlabel('Iteration')
plt.ylabel('Distance to London')
plt.title('Convergence of Gradient Descent')
plt.savefig('convergence_gd.png')
plt.show()
