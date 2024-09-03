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

// https://leetcode.com/problems/largest-component-size-by-common-factor/
class disjoint_union {
    public:
        vector <int> parent , rank;

        disjoint_union(int n) {
            parent.resize(n+1);
            rank.resize(n+1 , 0);
            for(int i = 0 ; i <= n ; i++) parent[i] = i;
        }

        int find_par(int node) {
            if(parent[node] == node) return node;
            return parent[node] = find_par(parent[node]);
        }

        void union_by_rank(int u , int v) {
            int u_par = find_par(u) , v_par = find_par(v);

            if(u_par == v_par) return;

            if(rank[u_par] > rank[v_par]) parent[v_par] = u_par;

            else if(rank[v_par] > rank[u_par]) parent[u_par] = v_par;

            else {
                parent[u_par] = v_par;
                rank[v_par]++;
            } 
        }
};
class Solution {
public:
    int largestComponentSize(vector<int>& nums) {
        int mx = *max_element(nums.begin() , nums.end());
        disjoint_union dsu(mx);

        //insertin all pair of factor in DSU
        for(auto num : nums) {
            for(int i = 2 ; i <= sqrt(num) ; i++) {
                if(num%i == 0) {
                    dsu.union_by_rank(i , num);
                    dsu.union_by_rank(num/i , num);
                }
            }
        }

        map <int,int> mp; //it will store all the node in same component
        int ans = 0;
        for(int i = 0 ; i < nums.size() ; i++) {
            mp[dsu.find_par(nums[i])]++;
            ans = max(ans , mp[dsu.find_par(nums[i])]);
        }

        return ans;
    }
};
int main() {
ios_base::sync_with_stdio(0);
cin.tie(0); cout.tie(0);
int tc = 1;
cin >> tc;
for (int t = 1; t <= tc; t++) {
}
}