import matplotlib.pyplot as plt

# Values from the previous outputs
gd_time = 0.01318502426147461  # Replace with actual time output of Gradient Descent
ga_time = 1.3334870338439941  # Replace with actual time output of Genetic Algorithm
gd_memory = 0.02734375  # Replace with actual memory output of Gradient Descent
ga_memory = 20.59375  # Replace with actual memory output of Genetic Algorithm

# Data for comparison
algorithms = ['Gradient Descent', 'Genetic Algorithm']
times = [gd_time, ga_time]
memories = [gd_memory, ga_memory]

# Create subplots
fig, (ax1, ax2) = plt.subplots(1, 2, figsize=(12, 6))

# Time comparison
ax1.bar(algorithms, times, color=['blue', 'green'])
ax1.set_title('Time Comparison')
ax1.set_ylabel('Time (seconds)')

# Memory comparison
ax2.bar(algorithms, memories, color=['blue', 'green'])
ax2.set_title('Memory Comparison')
ax2.set_ylabel('Memory (KB)')

# Show plot
plt.tight_layout()
plt.savefig('comparison_chart.png')
plt.show()
