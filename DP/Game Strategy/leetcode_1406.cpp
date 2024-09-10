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
    int dp[50002][2];
    //here we are cal max value of (alice-bob) -- based on this we will decide who is winner
    //using optimal game theory -- do ur best , expect worst from ur opp.
    int SolveForAlice(int level , int person , vector <int> &nums) {
        int n = nums.size();
        if(level >= n) return 0;

        if(dp[level][person] != -1) return dp[level][person];

        int sum = 0;
        int ans = person == 1 ? -1e9 : 1e9;

        if(person == 1) {
            for(int i = 1 ; i <= 3 ; i++) {
                if(level+i-1 < n) {
                    sum += nums[level+i-1];
                    ans = max(ans , sum + SolveForAlice(level+i , 0 , nums));
                }
            }
        }

        else {
            sum = 0;
            for(int i = 1 ; i <= 3 ; i++) {
                if(level+i-1 < n) {
                    sum -= nums[level+i-1];
                    ans = min(ans , sum + SolveForAlice(level+i , 1 , nums));
                }
            }
            // return bob;
        }

        return dp[level][person] = ans;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        memset(dp , -1 , sizeof(dp));
        int ans = SolveForAlice(0,1,stoneValue);
    
        if(ans > 0) return "Alice";
        else if(ans < 0) return "Bob";
        return "Tie";
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