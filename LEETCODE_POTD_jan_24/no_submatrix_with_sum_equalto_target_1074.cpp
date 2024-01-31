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
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n = matrix.size() , m = matrix[0].size();

        vector <vector<int>> row_sum(n , vector<int>(m , 0));

        for(int i = 0 ;  i < n ; i++) {
            int sum = 0;
            for(int j = 0 ; j < m ; j++) {
                sum += matrix[i][j];
                row_sum[i][j] = sum;
            }
        }


        //now we will use the 1d arr concept here -> subarr with sum k

        //we will iter over row wise with start and point in col

        int ans = 0;
        for(int sc = 0 ; sc < m ; sc++){
            for(int ec = sc ; ec < m ; ec++) {
                unordered_map <int,int> mp;
                mp[0] = 1;
                int sum = 0;
                for(int row = 0 ; row < n ; row++) {
                    sum += row_sum[row][ec];
                    if(sc > 0) sum -= row_sum[row][sc-1];
                    if(mp.find(sum - target) != mp.end()) ans += mp[sum-target]; //dekh lo same check kr rhe h
                    mp[sum]++;
                }
                mp.clear();
                mp[0] = 1;
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