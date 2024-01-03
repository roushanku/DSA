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

int n,m;
cin>>n>>m;

vector <int> adj[n+1]; // adj list (array of vector) --> will store all the neighbour of particular node
for(int i=0;i<m;i++){
    int u,v;
    cin>>u>>v;

    adj[u].push_back(v);
    adj[v].push_back(u);
}

//S.C -> O(2*m) -> for undirected graph and O(m) -> for directed graph

return 0;
}