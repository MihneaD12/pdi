#include <iostream>

using namespace std;

const int N = 100000;
int arr[N + 1], dp[N + 1];

/**
 * Calculates the greatest common divisor
 * @param nr1 , nr2 The numbers used to calculate the gcd
 */
int gcd(int nr1, int nr2) {
    if (nr2 != 0) {
        return gcd(nr2, nr1 % nr2);
    }
    return nr1;
}

bool valid(int nr1, int nr2) {
    return gcd(nr1, nr2) != 1;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    dp[n] = 1;

    for (int i = n - 1; i >= 1; i--) {
        int current_max_length = 0;
        for (int j = i + 1; j <= n; j++) {
            if (valid(arr[i], arr[j]) && dp[j] > current_max_length) {
                current_max_length = dp[j];
            }
        }
        dp[i] = current_max_length + 1;
    }

    int max_length = 0;
    for (int i = 1; i <= n; i++) {
        if (dp[i] > max_length) {
            max_length = dp[i];
        }
    }

    cout << max_length;
    return 0;
}
