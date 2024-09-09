#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define PI 3.1415926535897932384626433832795l 
const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;
//j.S.R -> Roush
// -------------------------<Reminder -> YOU ARE A CHAMP>------------------------- 
//Question achhe se pad -> Thoda sa apna test soch lo yr
//jayada hadbad na kro -> question solve ho jae to code liho
//तू स्वयं तेज भयकारी है, क्या कर सकती चिनगारी है?
// -------------------------<Everything will be good>------------------------- 
class Solution {
public:
    int dp[22][22];
    int solve(int l , int r , vector <int> &nums) {
        if(l > r) return 0;

        if(dp[l][r] != -1) return dp[l][r];

        //optimal game strategy -- do your best and expect worst from your opp.

        //expecting worst from opp
        int left = nums[l] + min(solve(l+2 , r , nums) , solve(l+1 , r-1 , nums));
        int right = nums[r] + min(solve(l , r-2 , nums) , solve(l+1 , r-1 , nums));

        return dp[l][r] = max(left , right); //taking best of our move
    }
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        for(auto it : nums) total += it;

        memset(dp , -1 , sizeof(dp));
        int alice = solve(0 , n-1 , nums);

        return alice >= total-alice;
    }
};
int main() {
ios_base::sync_with_stdio(0);
cin.tie(0); cout.tie(0);
int tc = 1;
cin >> tc;
for (int t = 1; t <= tc; t++) {

}
}