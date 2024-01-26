// J.S.R -- *roush*
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> pbds; //find_by_order //order_of_key

class Solution {
public:
    vector <pair<int,int>> rc = {{0,1} , {1,0} , {0,-1} , {-1,0}};

    map <vector<int> , int> dp;
    const int mod = 1e9 + 7;
    int solve(int r , int c , int ct , int n , int m , int maxMove) {
        if(ct > maxMove) return 0;

        if(r < 0 || r >= n || c < 0 || c >= m) {
            return 1;
        }

        if(dp.find({r,c,ct}) != dp.end()) return dp[{r , c , ct}];

        long long ans = 0;
        for(int i = 0 ; i < 4 ; i++) {
            int nrow = r + rc[i].first;
            int ncol = c + rc[i].second;

            ans += solve(nrow , ncol , ct+1 , n , m , maxMove);
            ans %= mod;
        }

        return dp[{r , c , ct}] = ans;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        long long ans = solve(startRow , startColumn , 0 , m , n , maxMove);
        return ans;
    }
};
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
//patience Bro , thoda sa logic soch k try ur own test case
//hadbad m kaafi gadbad kie ho islie aaram s -> You will do best for Youself
//First, solve the problem. Then, write the code.
int t;
cin>>t;
while(t--){
           
}
return 0;
}