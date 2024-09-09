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
    int dp[103][3][103];
    int solveForAlice(int level , int person , vector <int> piles , int m) {
        int n = piles.size();
        if(level >= n) return 0;

        int stones = 0;
        int ans;
        if(person == 1) ans = -1e9;
        if(person == 0) ans = 1e9;

        int x = min(n-level , 2*m);

        if(dp[level][person][m] != -1) return dp[level][person][m];

        //game strategy -- do ur best , expect worst from opp.

        for(int i = 1 ; i <= x ; i++) {
            stones += piles[level+i-1];
            if(person == 1) {
                //alice turn will add to our ans -- bcz func is written for alice
                ans = max(ans , stones + solveForAlice(level+i,0,piles,max(m,i)));
            }

            else{
                //will not add stone to ans -- bcz it is bob turn -- thus we will expect worst from him
                ans = min(ans , solveForAlice(level+i,1,piles,max(m,i)));
            }
        }
        return dp[level][person][m] = ans;
    }
    int stoneGameII(vector<int>& piles) {
        memset(dp,-1,sizeof(dp));
        int ans = solveForAlice(0,1,piles,1);
        return ans;
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