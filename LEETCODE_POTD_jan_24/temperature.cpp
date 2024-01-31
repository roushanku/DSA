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
    vector <int> NGE(vector <int> &nums) {
        int n = nums.size();
        vector <int> ans;
        stack <int> st;

        for(int i = n-1 ; i >= 0 ; i--) {
            if(st.empty()) ans.push_back(-1);

            else if(!st.empty() && nums[st.top()] > nums[i]) ans.push_back(st.top());

            else if(!st.empty() && nums[st.top()] <= nums[i]) {
                while(!st.empty() && nums[st.top()] <= nums[i]) st.pop();

                if(st.empty()) ans.push_back(-1);

                else if(!st.empty() && nums[st.top()] > nums[i]) ans.push_back(st.top());
            }
            st.push(i);
        }

        reverse(ans.begin() , ans.end());
        return ans;
    }
    vector<int> dailyTemperatures(vector<int>& nums) {
        vector <int> vng = NGE(nums);
        vector <int> ans;

        for(int i = 0 ; i < nums.size() ; i++) {
            if(vng[i] == -1) ans.push_back(0);

            else {
                ans.push_back(vng[i] - i);
            }
        }

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