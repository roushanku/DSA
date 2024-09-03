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

// leetcode link --- https://leetcode.com/problems/similar-string-groups/

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
            int up = find_par(u) , vp = find_par(v);

            if(up == vp) return;

            if(rank[up] > rank[vp]) parent[vp] = up;

            else if(rank[up] < rank[vp]) parent[up] = vp;

            else {
                parent[up] = vp;
                rank[vp]++;
            }
        }
};
class Solution {
public:
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        disjoint_union dsu(n);

        for(int i = 0 ; i < n ; i++) {
            string str = strs[i];
            for(int j = i+1 ; j < n ; j++) {
                string s = strs[j];
                int m = s.size();
                int ct = 0;
                for(int k = 0 ; k < s.size() ; k++) {
                    if(s[k] == str[k]) ct++;
                }

                if(ct+2 >= m) dsu.union_by_rank(i,j); //string with at most 2 distict char are putting in same comp
            }
        }

        map <int,int> mp; //for storing all the node in same comp
        for(int i = 0 ; i < n ; i++) {
            int par = dsu.find_par(i);

            mp[par]++;
        }

        return mp.size();
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