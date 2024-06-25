#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <random>

using namespace std;

// Function to generate random numbers between 0 and 1
vector<double> generateRandomNumbers(int n) {
    vector<double> randomNumbers(n);
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(0.0, 1.0);
    
    for (int i = 0; i < n; ++i) {
        randomNumbers[i] = dis(gen);
    }
    
    return randomNumbers;
}

// Function to perform KS Test
double ksTest(const vector<double>& data) {
    int n = data.size();
    vector<double> sortedData = data;
    sort(sortedData.begin(), sortedData.end());
    
    double maxDplus = 0.0;
    double maxDminus = 0.0;
    
    for (int i = 0; i < n; ++i) {
        double F_empirical = static_cast<double>(i + 1) / n;  // Empirical CDF
        double F_theoretical = sortedData[i];  // Theoretical CDF for uniform distribution
        
        double Dplus = abs(F_empirical - F_theoretical);
        double Dminus = abs(F_empirical - (F_theoretical - 1.0 / n));
        
        maxDplus = max(maxDplus, Dplus);
        maxDminus = max(maxDminus, Dminus);
    }
    
    // KS test statistic D
    double D = max(maxDplus, maxDminus);
    return D;
}

// Function to perform Chi-Square Test
double chiSquareTest(const vector<double>& data, int numBins) {
    int n = data.size();
    vector<int> observed(numBins, 0);
    
    // Compute observed frequencies in each bin
    for (int i = 0; i < n; ++i) {
        int bin = int(data[i] * numBins);
        observed[bin]++;
    }
    
    // Compute expected frequencies and Chi-Square statistic
    double chiSquare = 0.0;
    double expected = double(n) / numBins;
    
    for (int i = 0; i < numBins; ++i) {
        chiSquare += pow(observed[i] - expected, 2) / expected;
    }
    
    return chiSquare;
}

int main() {
    const int N = 1000;  // Number of random numbers to generate
    const int numBins = 10;  // Number of bins for Chi-Square test
    
    // Generate random numbers between 0 and 1
    vector<double> randomNumbers = generateRandomNumbers(N);
    
    // Perform KS test
    double D = ksTest(randomNumbers);
    cout << "KS Test statistic D: " << D << endl;
    
    // Compare D with critical value (0.05 significance level, n = 1000)
    double critical_value_ks = 1.36 / sqrt(N);  // Critical value for 0.05 significance level
    cout << "Critical value for KS Test (alpha=0.05): " << critical_value_ks << endl;
    
    if (D < critical_value_ks) {
        cout << "The sample is consistent with a uniform distribution (KS Test)." << endl;
    } else {
        cout << "The sample is not consistent with a uniform distribution (KS Test)." << endl;
    }
    
    // Perform Chi-Square test
    double chiSquare = chiSquareTest(randomNumbers, numBins);
    cout << "Chi-Square Test statistic: " << chiSquare << endl;
    
    
    double critical_value_chi = 16.92;  // Critical value for 0.05 significance level and 9 degrees of freedom
    cout << "Critical value for Chi-Square Test (alpha=0.05): " << critical_value_chi << endl;
    
    if (chiSquare < critical_value_chi) {
        cout << "The sample is consistent with a uniform distribution (Chi-Square Test)." << endl;
    } else {
        cout << "The sample is not consistent with a uniform distribution (Chi-Square Test)." << endl;
    }
    
    return 0;
}
