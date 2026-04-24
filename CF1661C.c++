#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

ll solve_for_target(ll target, int n, const vector<ll>& h) {
    ll ones_needed = 0;
    ll twos_needed = 0;

    for (int i = 0; i < n; i++) {
        ll diff = target - h[i];
        twos_needed += diff / 2;
        ones_needed += diff % 2;
    }

    ll low = 0, high = 1e18, ans = 1e18;
    while (low <= high) {
        ll mid = low + (high - low) / 2;
        ll available_ones = (mid + 1) / 2;
        ll available_twos = mid / 2;

        if (available_ones < ones_needed) {
            low = mid + 1;
        } else {
           
            ll current_twos_needed = twos_needed;
            ll extra_ones = available_ones - ones_needed;
  
            if (ones_needed + twos_needed * 2 <= available_ones + available_twos * 2) {
             
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
    }
    return ans;
}

void solve() {
    int n;
    cin >> n;
    vector<ll> h(n);
    ll max_h = 0;
    for (int i = 0; i < n; i++) {
        cin >> h[i];
        max_h = max(max_h, h[i]);
    }

    cout << min(solve_for_target(max_h, n, h), solve_for_target(max_h + 1, n, h)) << "\n";
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
