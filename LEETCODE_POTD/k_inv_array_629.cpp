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
    const int mod = 1e9 + 7;
    // int dp[1002][1002];
    // int solve(int n , int k) {
    //     if(n == 0) return 0;

    //     if(k == 0) return 1;

    //     int ans = 0;

    //     if(dp[n][k] != -1) return dp[n][k];
        
    //     //for an array of ele n -> you an have max inv of n-1..
    //     for(int inv = 0 ; inv <= min(k , n-1) ; inv++) {
    //         ans += solve(n-1 , k-inv);
    //         ans %= mod;
    //     } 

    //     return dp[n][k] = ans;
    // }
    int kInversePairs(int n, int k) {
        // memset(dp , -1 , sizeof(dp));
        // int ans = solve(n , k);
        // return ans;

        //dekho kaise memo se bottom up bnate h -> T.C = (n*n*k)

        int dp[n+1][k+1];
        //dp[i][j] - total no arr of size i with j inv

        // for(int i = 0 ; i <= n ; i++) {
        //     for(int j = 0 ; j <= k ; j++) {
        //         if(i == 0) dp[i][j] = 0;
        //     }
        // } 

        // for(int i = 0 ; i <= n ; i++) {
        //     for(int j = 0 ; j <= k ; j++) {
        //         if(j == 0) dp[i][j] = 1;
        //     }
        // }


        // for(int i = 1 ; i <= n ; i++) {
        //     for(int j = 1 ; j <= k ; j++) {
        //         int ans = 0;
        //         for(int inv = 0 ; inv <= min(i-1 , j) ; inv++) {
        //             ans = (ans % mod + dp[i-1][j-inv] % mod) % mod;
        //         }
        //         dp[i][j] = ans;
        //     }
        // }

        // int ans = dp[n][k];
        // return ans;


        //optimized bottom up -> observe the pattern in dp table after priting

        for(int i = 0 ; i <= n ; i++) {
            for(int j = 0 ; j <= k ; j++) {
                if(i == 0) dp[i][j] = 0;
            }
        } 

        for(int i = 0 ; i <= n ; i++) {
            for(int j = 0 ; j <= k ; j++) {
                if(j == 0) dp[i][j] = 1;
            }
        }

        for(int i = 1 ; i <= n ; i++) {
            long long cumusum = 1;
            for(int j = 1 ; j <= k ; j++) {
                cumusum += dp[i-1][j];

                if(j >= i) cumusum -= dp[i-1][j-i];
                dp[i][j] = cumusum % mod;
            }
        }

        int ans = dp[n][k];

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