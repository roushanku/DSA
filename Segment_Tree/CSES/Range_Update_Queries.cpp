#include <bits/stdc++.h>
using namespace std;

long long segTree[800001];
long long lazy[800001];

void buildTree(int id, int l, int r, vector<int> &arr) {
    if (l == r) {
        segTree[id] = arr[l];
        return;
    }

    int mid = l + (r - l) / 2;

    buildTree(2 * id + 1, l, mid, arr);
    buildTree(2 * id + 2, mid + 1, r, arr);

    segTree[id] = segTree[2 * id + 1] + segTree[2 * id + 2];
}

void update(int id, int l, int r, int start, int end, int val) {
    // Apply pending lazy updates, if any
    if (lazy[id] != 0) {
        segTree[id] += (r - l + 1) * lazy[id];

        if (l != r) {
            lazy[2 * id + 1] += lazy[id];
            lazy[2 * id + 2] += lazy[id];
        }
        lazy[id] = 0;
    }

    // No overlap
    if (r < start || l > end) return;

    // Complete overlap
    if (l >= start && r <= end) {
        segTree[id] += (r - l + 1) * val;

        if (l != r) {
            lazy[2 * id + 1] += val;
            lazy[2 * id + 2] += val;
        }
        return;
    }

    // Partial overlap
    int mid = l + (r - l) / 2;
    update(2 * id + 1, l, mid, start, end, val);
    update(2 * id + 2, mid + 1, r, start, end, val);

    segTree[id] = segTree[2 * id + 1] + segTree[2 * id + 2];
}

long long query(int id, int l, int r, int start, int end) {
    // Apply pending lazy updates, if any
    if (lazy[id] != 0) {
        segTree[id] += (r - l + 1) * lazy[id];

        if (l != r) {
            lazy[2 * id + 1] += lazy[id];
            lazy[2 * id + 2] += lazy[id];
        }
        lazy[id] = 0;
    }

    // No overlap
    if (l > end || r < start) return 0;

    // Complete overlap
    if (l >= start && r <= end) return segTree[id];

    // Partial overlap
    int mid = l + (r - l) / 2;
    return query(2 * id + 1, l, mid, start, end) + query(2 * id + 2, mid + 1, r, start, end);
}

void solve() {
    // Add your solution here
    int n, q;
    cin >> n >> q;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    buildTree(0, 0, n - 1, arr);
    memset(lazy, 0, sizeof(lazy));

    while (q--) {
        int ch;
        cin >> ch;

        if (ch == 1) {  // Update
            int a, b, u;
            cin >> a >> b >> u;
            a--;
            b--;

            update(0, 0, n - 1, a, b, u);
        } else {  // Query
            int k;
            cin >> k;
            k--;

            long long ans = query(0, 0, n - 1, k, k);
            cout << ans << "\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
