#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

// Function to estimate the integral of x^2 from 0 to 4 using Monte Carlo method
double estimateIntegral(int numSamples) {
    double sum = 0.0;

    for (int i = 0; i < numSamples; ++i) {
        double x = static_cast<double>(rand()) / RAND_MAX * 4.0; // Random number between 0 and 4
        sum += x * x;
    }

    return (4.0 / numSamples) * sum;
}

int main() {
    int numSamples = 20; // Number of random samples

    double integralEstimate = estimateIntegral(numSamples);
    cout << "Estimated value of the integral: " << integralEstimate << endl;

    return 0;
}
