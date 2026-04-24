#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 100005;

const int MAX_NODES = MAXN * 50;

struct Node {
    int sum;
    int l, r;
} tree[MAX_NODES];

int root[MAXN], node_count = 0;
int a[MAXN], prev_k[MAXN];
vector<int> pos_map[MAXN];

int update(int prev_root, int l, int r, int val) {
    int node = ++node_count;
    tree[node] = tree[prev_root];
    tree[node].sum++;
    if (l == r) return node;
    
    int mid = (l + r) / 2;
    if (val <= mid) 
        tree[node].l = update(tree[prev_root].l, l, mid, val);
    else 
        tree[node].r = update(tree[prev_root].r, mid + 1, r, val);
    return node;
}

int query(int node, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) return tree[node].sum;
    if (l > qr || r < ql || node == 0) return 0;
    
    int mid = (l + r) / 2;
    return query(tree[node].l, l, mid, ql, qr) + 
           query(tree[node].r, mid + 1, r, ql, qr);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    if (!(cin >> n >> k)) return 0;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (pos_map[a[i]].size() >= k) {
            prev_k[i] = pos_map[a[i]][pos_map[a[i]].size() - k];
        } else {
            prev_k[i] = 0;
        }
        pos_map[a[i]].push_back(i);
    }


    root[0] = 0; 
    for (int i = 1; i <= n; i++) {
        root[i] = update(root[i - 1], 0, n, prev_k[i]);
    }

    int q, last_ans = 0;
    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;
        int l = ((x + last_ans) % n) + 1;
        int r = ((y + last_ans) % n) + 1;
        if (l > r) swap(l, r);

        
        last_ans = query(root[r], 0, n, 0, l - 1) - query(root[l - 1], 0, n, 0, l - 1);
        cout << last_ans << "\n";
    }

    return 0;
}
