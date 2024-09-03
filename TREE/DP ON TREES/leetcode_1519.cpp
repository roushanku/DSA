#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define PI 3.1415926535897932384626433832795l 
const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;
//j.S.R -> Roush
// -------------------------<Reminder -> YOU ARE A CHAMP>------------------------- 
//Question achhe se pad -> Thoda sa apna test soch lo yr
//jayada hadbad na kro -> question solve ho jae to code liho
//तू स्वयं तेज भयकारी है, क्या कर सकती चिनगारी है?
// -------------------------<Everything will be good>------------------------- 

// https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label/
class Solution {
public:
    map <int,vector<int>> adj;
    vector <int> ans;
    vector <int> solve(int node , int p , string &labels) {

        vector <int> v(26 , 0);
        v[labels[node]-'a'] = 1;

        for(auto child : adj[node]) {
            if(child == p) continue;

            vector <int> temp = solve(child , node , labels);
            for(int i = 0 ; i < 26 ; i++) v[i] += temp[i];
        }
        
        ans[node] = v[labels[node]-'a'];

        return v;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        for(auto it : edges) {
            int u = it[0] , v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        ans.resize(n);
        vector <int> v = solve(0 , -1 , labels);
        return ans;
    }
};
int main() {
ios_base::sync_with_stdio(0);
cin.tie(0); cout.tie(0);
}