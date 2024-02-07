// J.S.R -- *roush*
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> pbds; //find_by_order //order_of_key

struct Node
{
    int data;
    Node* left, * right;
};

class Solution {
    public:
    void convertToGraph(Node* root , map <int , vector<int>> &adj) {
        if(root == NULL) return;
        
        if(root -> left) {
            adj[root->data].push_back(root -> left->data);
            adj[root -> left -> data].push_back(root->data);
        }
        
        if(root -> right) {
            adj[root->data].push_back(root -> right->data);
            adj[root -> right->data].push_back(root->data);
        }
        
        convertToGraph(root -> left , adj);
        convertToGraph(root -> right , adj);
    }
    /* Should return minimum distance between a and b
    in a tree with given root*/
    int findDist(Node* root, int a, int b) {
        // Your code here
        map <int , vector<int>> adj;
        convertToGraph(root , adj);
        
        queue <int> q;
        q.push(a);
        
        int level = 0;
        
        map <int,int> vis;
        vis[a]++;
        
        bool ok = false;
        
        while(!q.empty()) {
            int size = q.size();
            
            while(size--) {
                int node = q.front();
                q.pop();
                
                if(node == b) ok = true;
                
                for(auto it : adj[node]) {
                    if(vis.find(it) == vis.end()) {
                        q.push(it);
                        vis[it]++;
                    }
                }
            }
            if(ok) break;
            level++;
            
        }
        
        return level;
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