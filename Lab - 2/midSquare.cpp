#include <iostream>
#include <vector>

using namespace std;

// Function to extract the middle digit
int extractMiddleDigit(int number) {
    int squared = number * number;
    int middleDigit = (squared / 10) % 10;
    return middleDigit;
}

// Function to generate random numbers using Mid-Square method
vector<int> generateMidSquareRandomNumbers(int seed, int n) {
    vector<int> randomNumbers;
    for (int i = 0; i < n; ++i) {
        seed = extractMiddleDigit(seed);
        randomNumbers.push_back(seed);
    }
    return randomNumbers;
}

int main() {
    int seed = 9;
    int n = 10;

    vector<int> randomNumbers = generateMidSquareRandomNumbers(seed, n);

    cout << "Mid-Square Random Numbers:" << endl;
    for (int num : randomNumbers) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
