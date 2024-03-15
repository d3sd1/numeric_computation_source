public class BasicGradientDescent {

    // Learning rate determines the size of the steps we take
    private static final double learningRate = 0.1;
    // Maximum number of iterations to prevent endless loops
    private static final int maxIterations = 1000;
    // Threshold for the change in function value to determine convergence
    private static final double threshold = 0.0001;

    // Function to compute the gradient of f(x) = x^2
    private static double gradient(double x) {
        return 2 * x;
    }

    // Gradient Descent Algorithm
    public static double gradientDescent(double initialGuess) {
        double x = initialGuess;
        for (int i = 0; i < maxIterations; i++) {
            // Calculate the current gradient
            double grad = gradient(x);

            // Update x by moving in the opposite direction of the gradient
            x = x - learningRate * grad;

            // Check for convergence (if the change is smaller than the threshold, we've converged)
            if (Math.abs(grad) < threshold) {
                System.out.println("Converged in " + i + " iterations.");
                return x;
            }
        }
        System.out.println("Reached the maximum number of iterations without converging.");
        return x;
    }

    public static void run() {
        double initialGuess = -10; // This can be any number
        double minimum = gradientDescent(initialGuess);
        System.out.println("The function has a minimum at x = " + minimum + ", f(x) = " + (minimum * minimum));
    }
}
