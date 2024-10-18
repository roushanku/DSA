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

vector<int> num;
int a, b, d, k;
int DP[12][12][2];
/// DP[p][c][f] = Number of valid numbers <= b from this state
/// p = current position from left side (zero based)
/// c = number of times we have placed the digit d so far
/// f = the number we are building has already become smaller than b? [0 = no, 1 = yes]

int call(int pos, int cnt, int f){
    if(cnt > k) return 0;

    if(pos == num.size()){
        if(cnt == k) return 1;
        return 0;
    }

    if(DP[pos][cnt][f] != -1) return DP[pos][cnt][f];
    int res = 0;

    int LMT;

    if(f == 0){
        /// Digits we placed so far matches with the prefix of b
        /// So if we place any digit > num[pos] in the current position, then the number will become greater than b
        LMT = num[pos];
    } else {
        /// The number has already become smaller than b. We can place any digit now.
        LMT = 9;
    }

    /// Try to place all the valid digits such that the number doesn't exceed b
    for(int dgt = 0; dgt<=LMT; dgt++){
        int nf = f;
        int ncnt = cnt;
        if(f == 0 && dgt < LMT) nf = 1; /// The number is getting smaller at this position
        if(dgt == d) ncnt++;
        if(ncnt <= k) res += call(pos+1, ncnt, nf);
    }

    return DP[pos][cnt][f] = res;
}

int solve(int b){
    num.clear();
    while(b>0){
        num.push_back(b%10);
        b/=10;
    }
    reverse(num.begin(), num.end());
    /// Stored all the digits of b in num for simplicity

    memset(DP, -1, sizeof(DP));
    int res = call(0, 0, 0);
    return res;
}

// https://codeforces.com/blog/entry/53960

// How many numbers x are there in the range a to b, where the digit d occurs exactly k times in x? 
// There may have several solutions including number theory or combinatorics, but let’s see how we can solve this problem using digit dp.

int main () {

    cin >> a >> b >> d >> k;
    int res = solve(b) - solve(a-1);
    cout << res << endl;

    return 0;
}