#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

// Function to estimate Pi using Monte Carlo method
double estimatePi(int numSamples) {
    int insideCircle = 0;

    for (int i = 0; i < numSamples; ++i) {
        double x = static_cast<double>(rand()) / RAND_MAX;
        double y = static_cast<double>(rand()) / RAND_MAX;

        if (x * x + y * y <= 1.0) {
            ++insideCircle;
        }
    }

    return 4.0 * insideCircle / numSamples;
}

int main() {
    int numSamples = 20; // Number of random samples

    double piEstimate = estimatePi(numSamples);
    cout << "Estimated value of Pi: " << piEstimate << endl;

    return 0;
}
