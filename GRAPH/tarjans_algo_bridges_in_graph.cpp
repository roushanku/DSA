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
    int timer = 1;
    void dfs(int node , int p , vector <int> adj[] , vector <int> &vis , int time[] , int low[] , vector <vector<int>> &bridges) {
        vis[node] = 1;
        time[node] = low[node] = timer;

        timer++;

        for(auto it : adj[node]) {
            if(it == p) continue;

            if(vis[it] == 0) {
                dfs(it , node , adj , vis , time , low , bridges);
                low[node] = min(low[node] , low[it]);

                //bridges detected
                if(low[it] > time[node]) {
                    bridges.push_back({it , node});
                }
            }

            else{
                low[node] = min(low[node] , low[it]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector <int> adj[n];

        for(auto it : connections) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        int time[n];
        int low[n];

        vector <int> vis(n , 0);

        vector <vector<int>> bridges;

        dfs(0 , -1 , adj , vis , time , low , bridges);

        return bridges;
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