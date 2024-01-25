// J.S.R -- *roush*
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> pbds; //find_by_order //order_of_key


//  * Definition for a binary tree node.
 struct TreeNode {
    int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode() : val(0), left(nullptr), right(nullptr) {}
   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

class Solution {
public:
    int ans = 0;
    void solve(TreeNode* root , map <int,int> &mp) {
        if(root == NULL) return;

        //leaf node
        if(root -> left == NULL && root -> right == NULL) {
            int od = 0 , ev = 0;

            mp[root -> val]++; // coubnt for leaf node

            for(auto &it : mp) {
                if(it.second & 1) od++;
                else ev++;
            }

            //undo fro leaf node
            mp[root -> val]--;
            if(mp[root -> val] == 0) mp.erase(root -> val);

            if(od <= 1) ans++;
            return;
        }


        mp[root -> val]++;

        solve(root -> left , mp);
        solve(root -> right , mp);

        mp[root -> val]--;
        if(mp[root -> val] == 0) mp.erase(root -> val);
    }

    int pseudoPalindromicPaths (TreeNode* root) {
        map <int,int> mp;
        solve(root , mp);

        return ans;
    }
};

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
//patience Bro , thoda sa logic soch k try ur own test case
//hadbad m kaafi gadbad kie ho islie aaram s -> You will do best for Youself
//First, solve the problem. Then, write the code.


return 0;
}