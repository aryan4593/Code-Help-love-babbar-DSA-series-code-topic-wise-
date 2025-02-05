#include<iostream>
using namespace std;

int mySqrt(int x) {
    long long int s = 0, e = x;
    long long int ans = -1;

    while (s <= e) {
        long long int mid = s + (e - s) / 2;
        long long int square = mid * mid;
        if (square == x)
            return mid;
        else if (square < x) {
            s = mid + 1;
            ans = mid;
        }
        else
            e = mid - 1;
    }
    return ans;
}

double morePrecised(int n, int precision, double temp) {
    double factor = 1.0;
    for (int i = 0; i < precision; i++) {
        factor *= 0.1;
        while (temp * temp < n){
            temp += factor;
            }
        temp -= factor; // Adjust temp back as it overshoots when loop exits
    }
    return temp;
}

int main() {
    int n;
    std::cout << "Enter the number: ";
    cin >> n;

    int tempSol = mySqrt(n);
    std::cout << "Square root of " << n << " (original): " << tempSol << endl;

    double preciseSol = morePrecised(n, 5, tempSol); // You can adjust precision here
    std::cout << "Square root of " << n << " (more precise): " << preciseSol << endl;

    return 0;
}
