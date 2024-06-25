#include <iostream>
#include <vector>

using namespace std;

// Function to generate random numbers using LCG method
vector<int> generateLCGRandomNumbers(int seed, int n, int a, int c, int m) {
    vector<int> randomNumbers;
    int X = seed;
    for (int i = 0; i < n; ++i) {
        X = (a * X + c) % m;
        randomNumbers.push_back(X % 10);
    }
    return randomNumbers;
}

int main() {
    int seed = 5;
    int n = 10;
    int a = 3;
    int c = 3;
    int m = 10;

    vector<int> randomNumbers = generateLCGRandomNumbers(seed, n, a, c, m);

    cout << "LCG Random Numbers:" << endl;
    for (int num : randomNumbers) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
