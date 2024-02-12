// J.S.R -- *roush*
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> pbds; //find_by_order //order_of_key

//imp note -> no of ele having freq (n/k) will be maximum (k-1) 
//for majority ele 1 -> check only for onr ele
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        long long ct1 = 0 , m1 = -1e10 , ct2 = 0 , m2 = -1e10;

        for(int i = 0 ; i < nums.size() ; i++) {
            if(nums[i] == m1) ct1++;

            else if(nums[i] == m2) ct2++;

            else if(ct1 == 0) {
                ct1 = 1;
                m1 = nums[i];
            } 

            else if(ct2 == 0) {
                ct2 = 1;
                m2 = nums[i];
            }

            else{
                ct1--;
                ct2--;
            }
        }

        vector <int> ans;
        int n = nums.size();
        int c1 = 0;
        for(int i = 0 ; i < nums.size() ; i++) {
            if(nums[i] == m1) c1++;
        }

        if(c1 > (n/3)) ans.push_back(m1);

        int c2 = 0;

        for(int i = 0 ; i < n ; i++) {
            if(nums[i] == m2) c2++;
        }

        if(c2 > (n/3)) ans.push_back(m2);

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