// J.S.R -- *roush*
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> pbds; //find_by_order //order_of_key
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
// 5 6
//1 2
//4 5
//2 4
//3 4
//3 5
//1 3

int n,m; // no of node and edges
cin>>n>>m;

int adj[n+1][m+1];
for(int i=0;i<n;i++){
    int u,v;
    cin>>u>>v;

    adj[u][v]=1;
    adj[v][u]=1; // for undirected graph
}

// S.C -> O(n*n)
return 0;
}