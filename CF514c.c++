#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

typedef long long ll;

const ll MOD1 = 1e9 + 7;
const ll MOD2 = 1e9 + 9;
const ll BASE1 = 5;
const ll BASE2 = 7;

struct HashPair {
    ll h1, h2;
    bool operator<(const HashPair& other) const {
        if (h1 != other.h1) return h1 < other.h1;
        return h2 < other.h2;
    }
};
ll p1[600005], p2[600005];

void precompute() {
    p1[0] = 1; p2[0] = 1;
    for (int i = 1; i < 600005; i++) {
        p1[i] = (p1[i - 1] * BASE1) % MOD1;
        p2[i] = (p2[i - 1] * BASE2) % MOD2;
    }
}

HashPair get_hash(const string& s) {
    ll r1 = 0, r2 = 0;
    for (int i = 0; i < s.length(); i++) {
        r1 = (r1 + (s[i] - 'a' + 1) * p1[i]) % MOD1;
        r2 = (r2 + (s[i] - 'a' + 1) * p2[i]) % MOD2;
    }
    return {r1, r2};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    precompute();

    int n, m;
    cin >> n >> m;

    set<HashPair> dict_hashes;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        dict_hashes.insert(get_hash(s));
    }

    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        HashPair current = get_hash(s);
        bool found = false;

        for (int j = 0; j < s.length(); j++) {
            for (char c = 'a'; c <= 'c'; c++) {
                if (c == s[j]) continue;

                ll new_h1 = (current.h1 - (s[j] - 'a' + 1) * p1[j]) % MOD1;
                if (new_h1 < 0) new_h1 += MOD1;
                new_h1 = (new_h1 + (c - 'a' + 1) * p1[j]) % MOD1;

                ll new_h2 = (current.h2 - (s[j] - 'a' + 1) * p2[j]) % MOD2;
                if (new_h2 < 0) new_h2 += MOD2;
                new_h2 = (new_h2 + (c - 'a' + 1) * p2[j]) % MOD2;

                if (dict_hashes.count({new_h1, new_h2})) {
                    found = true;
                    break;
                }
            }
            if (found) break;
        }

        if (found) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
