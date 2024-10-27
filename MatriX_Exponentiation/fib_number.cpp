#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define PI 3.1415926535897932384626433832795l 
const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

void multiply(vector<vector<long long>>& A, vector<vector<long long>>& B) {
    int n = A.size();
    vector<vector<long long>> C(n, vector<long long>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                C[i][j] = (C[i][j] + A[i][k] * B[k][j] % MOD) % MOD;
            }
        }
    }
    A = C;
}

vector<vector<long long>> power(vector<vector<long long>>& M, int expo) {
    int n = M.size();
    vector<vector<long long>> ans = { {1, 0}, {0, 1} };

    while (expo) {
        if (expo & 1)
            multiply(ans, M);
        multiply(M, M);
        expo >>= 1;
    }
    return ans;
}

int nthFibonacci(int n) {
    if (n == 0 || n == 1)
        return 1;

    vector<vector<long long>> M = { {1, 1}, {1, 0} };
    vector<vector<long long> > F = { { 1, 0 }, { 0, 0 } };
    vector<vector<long long>> res = power(M, n - 1);

    multiply(res, F);
    return res[0][0];
}

void solve() {
    int n;
    cin >> n;
    cout << nthFibonacci(n) << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}
