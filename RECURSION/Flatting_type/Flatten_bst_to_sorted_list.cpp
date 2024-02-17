// J.S.R -- *roush*
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> pbds; //find_by_order //order_of_key

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node *flattenBST(Node *root)
    {
        // code here
        
        if(root == NULL) return NULL; //base case
        
        Node* head = flattenBST(root -> left); //flatten left subtree
        
        root -> left = NULL; //add root to left flattten part
        
        root -> right = flattenBST(root -> right); //flatten right subtree
        
        if(head != NULL) { //if left subtree is not null 
            Node* temp = head;
            while(temp && temp -> right) {
                temp = temp -> right;
            }
            temp -> right = root;
        }
        
        else head = root;
        
        return head;
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