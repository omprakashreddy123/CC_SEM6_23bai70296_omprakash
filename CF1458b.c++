#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    int total_b = 0;
    int max_capacity = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        total_b += b[i];
        max_capacity += a[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(max_capacity + 1, -1));
    dp[0][0] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i; j >= 0; j--) {
            for (int s = 0; s <= max_capacity - a[i]; s++) {
                if (dp[j][s] != -1) {
                    dp[j + 1][s + a[i]] = max(dp[j + 1][s + a[i]], dp[j][s] + b[i]);
                }
            }
        }
    }

    cout << fixed << setprecision(10);
    for (int k = 1; k <= n; k++) {
        double max_water = 0;
        for (int s = 0; s <= max_capacity; s++) {
            if (dp[k][s] != -1) {
                double current_val = min((double)s, (dp[k][s] + total_b) / 2.0);
                max_water = max(max_water, current_val);
            }
        }
        cout << max_water << (k == n ? "" : " ");
    }
    cout << endl;

    return 0;
}
