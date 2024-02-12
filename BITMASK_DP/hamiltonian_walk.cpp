// J.S.R -- *roush*
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> pbds; //find_by_order //order_of_key

int dp[16][10000];
// T.C = ((n+m)*(2^n))
int solve(int node , int n , int mask , vector <vector<int>> adj) {
    if(mask == (1<<n)-1) {
        if(node == n-1) return 1;
        else return 0;
    }

    int ans = 0;

    if(dp[node][mask] != -1) return dp[node][mask];

    for(auto it : adj[node]) {
        if((1<<it) & mask) continue; //already taken
        ans += solve(it , n , mask |= (1<<it) , adj);
    }

    return dp[node][mask] = ans;
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
//patience Bro , thoda sa logic soch k try ur own test case
//hadbad m kaafi gadbad kie ho islie aaram s -> You will do best for Youself

//First, solve the problem. Then, write the code.
//a city has n nodes and m edges -> 
//find no f path from node 1 to N , s.t every node is visited exactly once

// n <= 20
int n,m;
cin>>n>>m;

vector <vector<int>> adj(n);

for(int i = 0 ; i < m ; i++) {
    int u,v;
    cin>>u>>v;

    adj[u].push_back(v);
}

memset(dp , -1 , sizeof(dp));
int ans = solve(0 , n , 0 , adj);
cout<<ans<<"\n";
return 0;
}