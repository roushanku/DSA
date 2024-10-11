#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define PI 3.1415926535897932384626433832795l 
const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

// Segment tree to store maximum available rooms in a range
int segTree[800001];

void buildTree(int id, int l, int r, vector<int> &hotel) {
    if (l == r) {
        segTree[id] = hotel[l];  // Leaf node stores the capacity of the hotel
        return;
    }

    int mid = l + (r - l) / 2;

    buildTree(2 * id + 1, l, mid, hotel);
    buildTree(2 * id + 2, mid + 1, r, hotel);

    segTree[id] = max(segTree[2 * id + 1], segTree[2 * id + 2]);
}

// Update the segment tree after a booking is made
void update(int id, int l, int r, int index, int val) {
    if (l == r) {
        // Update the number of rooms at the hotel after booking
        segTree[id] -= val;
        return;
    }

    int mid = l + (r - l) / 2;
    if (index <= mid) update(2 * id + 1, l, mid, index, val);
    else update(2 * id + 2, mid + 1, r, index, val);

    // Recompute the maximum in the current range
    segTree[id] = max(segTree[2 * id + 1], segTree[2 * id + 2]);
}

// Query the first hotel with enough rooms
int query(int id, int l, int r, int req) {
    if (segTree[id] < req) return -1;  // Not enough rooms in this range

    if (l == r) return l;  // Found the hotel with enough rooms

    int mid = l + (r - l) / 2;

    if (segTree[2 * id + 1] >= req) return query(2 * id + 1, l, mid, req);
    else return query(2 * id + 2, mid + 1, r, req);
}

void solve() {
    // Number of hotels and number of groups
    int n, m;
    cin >> n >> m;

    vector<int> hotel(n);
    for (int i = 0; i < n; i++) cin >> hotel[i];

    // Build the segment tree for hotel capacities
    buildTree(0, 0, n - 1, hotel);

    while (m--) {
        int group;
        cin >> group;

        // Query the first hotel with enough rooms
        int ans = query(0, 0, n - 1, group);
        cout << (ans + 1) << " ";  // Print 1-based index of the hotel

        if (ans != -1) {
            // Update the segment tree after the booking
            update(0, 0, n - 1, ans, group);
        }
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
}
