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
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size() , m = text2.size();
        vector <vector<int>> lcs(n+1,vector<int>(m+1,0));

        for(int i = 0 ; i <= n ; i++) {
            for(int j = 0 ; j <= m ; j++) {
                if(i == 0 || j == 0) lcs[i][j] = 0;
            }
        }

        for(int i = 1 ; i <= n ; i++) {
            for(int j = 1 ; j <= m ; j++) {
                if(text1[i-1] == text2[j-1]) {
                    lcs[i][j] = max(lcs[i][j] , 1 + lcs[i-1][j-1]);
                }
                else lcs[i][j] = max(lcs[i-1][j] , lcs[i][j-1]);
            }
        }

        int ans = lcs[n][m];

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