// J.S.R -- *roush*
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> pbds; //find_by_order //order_of_key

struct  Node 
{
    int data;
    Node *left , *right;
};

class Solution {
    public:
    set <Node*> st;
    //apr 1 -> keep track of path and when u reach leaf node 
    //if size of vector is greater than k then there is node with dist k
    //as we will store the address of node in set , duplicat will be handle by set
    //T.C -> O(N)
    //S.C = (h) -> tree of node n -> max leaf node = (n/2)
    void solve(Node* root , int k , vector <Node*> v) {
        if(root == NULL) return;
        
        if(root -> left == NULL && root -> right == NULL) {
            v.push_back(root);
            int n = v.size();
            if(n > k) {
                Node* temp = v[n-k-1];
                st.insert(temp);
            }
            return;
        }
        
        v.push_back(root);
        solve(root -> left , k , v);
        
        solve(root -> right , k , v);
        v.pop_back();
        
    }
    //Function to return count of nodes at a given distance from leaf nodes.
    int printKDistantfromLeaf(Node* root, int k)
    {
    	//Add your code here. 
    	vector <Node*> v;
    	
    	solve(root , k , v);
    	
    	int ans = st.size();
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