#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

// Function to generate small primes using the classic Sieve of Eratosthenes
void simpleSieve(int limit, vector<int>& primes) {
    bool isPrime[limit + 1];
    memset(isPrime, true, sizeof(isPrime));

    for (int p = 2; p * p <= limit; ++p) {
        if (isPrime[p]) {
            for (int i = p * p; i <= limit; i += p) {
                isPrime[i] = false;
            }
        }
    }

    for (int p = 2; p <= limit; ++p) {
        if (isPrime[p]) {
            primes.push_back(p);
        }
    }
}

// Function to perform the segmented sieve
void segmentedSieve(int L, int R) {
    // Generate small primes up to sqrt(R)
    int limit = floor(sqrt(R)) + 1;     //flore means gif
    vector<int> primes;
    simpleSieve(limit, primes);

    // Create a boolean array to mark primes in the range [L, R]
    int n = R - L + 1;
    bool isPrime[n];
    memset(isPrime, true, sizeof(isPrime));

    // Use the small primes to mark non-primes in the range [L, R]
    for (int i = 0; i < primes.size(); ++i) {
        int p = primes[i];

        // Find the first multiple of p in the range [L, R]
        int start = max(p * p, (L + p - 1) / p * p);
        if (start > R) {
            continue;
        }

        for (int j = start; j <= R; j += p) {
            isPrime[j - L] = false;
        }
    }

    // Print the primes in the range [L, R]
    for (int i = 0; i < n; ++i) {
        if (isPrime[i] && (i + L) >= 2) {
            cout << (i + L) << " ";
        }
    }
    cout << endl;
}

int main() {
    int L = 10, R = 50;
    cout << "Primes in range [" << L << ", " << R << "] are: ";
    segmentedSieve(L, R);
    return 0;
}
