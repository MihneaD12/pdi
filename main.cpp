#include <iostream>

using namespace std;

const int N = 100000;
int arr[N + 1], dp[N + 1];

int cmmdc(int a, int b) {
    if (b != 0) {
        return cmmdc(b, a % b);
    }
    return a;
}

bool valid(int nr1, int nr2) {
    if (cmmdc(nr1, nr2) == 1) {
        return false;
    }
    return true;
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
