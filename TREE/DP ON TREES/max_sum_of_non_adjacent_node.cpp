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
    Node* left;
    Node* right;
};

map <Node* , int> dp1 , dp2;
    //dp1 -> on taking the node , dp2 -> not taking node
    void solve(Node* root) {
        if(root == NULL) return;
        if(root -> left == NULL && root -> right == NULL) {
            dp1[root] = root -> data;
            dp2[root] = 0;
            return;
        }
        
        dp1[root] = root -> data;
        
        solve(root -> left);
        
      
        if(root -> left) {
            
            dp1[root] += (dp2[root -> left]);
            dp2[root] += max({dp1[root -> left] , dp2[root -> left]});
        }
        
        solve(root -> right);
        
        if(root -> right) {
            
            dp1[root] += (dp2[root -> right]);
            dp2[root] += max({dp1[root -> right] , dp2[root -> right]});
        }
    }
    //Function to return the maximum sum of non-adjacent nodes.
    int getMaxSum(Node *root) 
    {
        // Add your code here
        solve(root);
        int ans = max({dp1[root] , dp2[root]});
        
        return ans;
    }
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