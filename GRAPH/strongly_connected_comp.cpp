#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define PI 3.1415926535897932384626433832795l
const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;
// j.S.R -> Roush
//  -------------------------<Reminder -> YOU ARE A CHAMP>-------------------------
// Question achhe se pad -> Thoda sa apna test soch lo yr
// jayada hadbad na kro -> question solve ho jae to code liho
// तू स्वयं तेज भयकारी है, क्या कर सकती चिनगारी है?
//  -------------------------<Everything will be good>-------------------------
void dfsFill(int node, vector<vector<int>> &adj, vector<int> &vis, stack<int> &st)
{
    vis[node] = 1;

    for (auto child : adj[node])
    {
        if (!vis[child])
            dfsFill(child, adj, vis, st);
    }

    st.push(node);
}

void dfs(int node, vector<vector<int>> &revadj, vector<int> &visited)
{
    visited[node] = 1;

    for (auto child : revadj[node])
    {
        if (visited[child])
            continue;
        dfs(child, revadj, visited);
    }
}
int kosaraju(int V, vector<vector<int>> &adj)
{
    // code here
    // find topo sort -- step 1

    stack<int> st;
    vector<int> vis(V, 0);

    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
            dfsFill(i, adj, vis, st);
    }

    // rev all edge of graph
    vector<vector<int>> revadj(V);

    for (int i = 0; i < V; i++)
    {
        for (int j : adj[i])
            revadj[j].push_back(i);
    }

    // step - 3 -- make dfs and count no of comp u visit
    vector<int> visited(V, 0);
    int ct = 0;
    while (!st.empty())
    {
        int node = st.top();
        st.pop();
        if (visited[node])
        {
            continue;
        }
        dfs(node, revadj, visited);
        ct++;
    }

    return ct;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
    }
}