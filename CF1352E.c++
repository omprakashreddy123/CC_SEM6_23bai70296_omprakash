#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> counts(n + 1, 0);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        counts[a[i]]++; 
    }

    vector<bool> is_special(n + 1, false);
    for (int i = 0; i < n; i++) {
        int current_sum = a[i];
        for (int j = i + 1; j < n; j++) {
            current_sum += a[j];
            if (current_sum > n) break;
            
            is_special[current_sum] = true;
        }
    }

    int total_special = 0;
    for (int i = 1; i <= n; i++) {
        if (is_special[i]) {
            total_special += counts[i];
        }
    }

    cout << total_special << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
