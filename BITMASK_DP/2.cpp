// J.S.R -- *roush*
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> pbds; //find_by_order //order_of_key
// T.C = (n*m*2^n)
int dp[16][52];
int solve(int level , int mask , int n , int m , vector <vector<int>> mat) {
    if(level == m) return 0;

    int ans = 0;

    if(dp[level][mask] != -1) return dp[level][mask];

    ans = max(ans , solve(level+1 , mask , n , m , mat));

    for(int j = 0 ; n ; j++) {
        if((1<<j) & mask == 0) {
            ans = max(ans , mat[level][j] + solve(level+1 , mask |= (1<<j) , n , m , mat));
        }
    }

    return dp[level][mask] = ans;
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
//patience Bro , thoda sa logic soch k try ur own test case
//hadbad m kaafi gadbad kie ho islie aaram s -> You will do best for Youself
//First, solve the problem. Then, write the code.

// n <= 15
// m <= 50
//given n rank and m student , ith student on getting jth rank get mat[i][j] .
// find max total score
int n,m;
cin>>n>>m;

vector <vector<int>> mat(n , vector<int>(m));

for(int i  = 0 ; i < n ; i++) {
    for(int j = 0 ; j < m ; j++) {
        cin>>mat[i][j];
    }
}

memset(dp , -1 , sizeof(dp));
int ans = solve(0 , 0 , n , m , mat);
return 0;
}