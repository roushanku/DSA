// J.S.R -- *roush*
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> pbds; //find_by_order //order_of_key

int rob(vector<int>& nums) {
    int n = nums.size();
    vector <int> dp(n,0);
    dp[0] = nums[0];
    if(n > 1) dp[1] = max(nums[1] , nums[0]);

    for(int i = 2 ; i < n ; i++) {
        dp[i] = max(dp[i-1] , nums[i]+dp[i-2]);
    }

    int ans = dp[n-1];
    return ans;
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
//patience Bro , thoda sa logic soch k try ur own test case
//hadbad m kaafi gadbad kie ho islie aaram s -> You will do best for Youself
//First, solve the problem. Then, write the code.

    vector <int> nums = {1,2,3,5,6};

    int ans = rob(nums);
return 0;
}