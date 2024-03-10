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
    //divide and conquer
    long long solve(int l , int r , vector <int> &nums , int diff) {
        if(l == r) return 0;

        int mid = l + (r-l) / 2; //divide the array into two parts

        //answer from two parts (s.t i and j lie on same parts)
        long long ans = solve(l , mid , nums , diff) + solve(mid+1 , r , nums , diff);

        int l1 = l , r1 = mid , l2 = mid+1 , r2 = r;

        //sorting left and right parts
        sort(nums.begin()+l1 , nums.begin()+r1+1);
        sort(nums.begin()+l2 , nums.begin()+r2+1);

        //calculating answer s.t i lies on left part and j lie on right part
        //we need to find no of ele on left arr leass than equal to  nums[i] + diff for all ele in right arr
        for(int i = l2 ; i <= r2 ; i++) {
            int k = nums[i] + diff;
            int upper = upper_bound(nums.begin()+l1 , nums.begin()+r1+1 , k) - nums.begin();

            if(upper <= r1+1) ans += (upper - l1); //if index lie on left arr then add to ans
        }
        return ans;
    }
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        
        int n = nums1.size();
        vector <int> nums(n);
        for(int i = 0 ; i < n ; i++) nums[i] = (nums1[i] - nums2[i]);

        long long ans = solve(0 , n-1 , nums , diff);
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