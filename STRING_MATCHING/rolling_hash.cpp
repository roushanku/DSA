#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define PI 3.1415926535897932384626433832795l 
const int N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;
//j.S.R -> Roush
// -------------------------<Reminder -> YOU ARE A CHAMP>------------------------- 
//Question achhe se pad -> Thoda sa apna test soch lo yr
//jayada hadbad na kro -> question solve ho jae to code liho
//तू स्वयं तेज भयकारी है, क्या कर सकती चिनगारी है?
// -------------------------<Everything will be good>------------------------- 

class RollHash{
    public:
    int pw[N];
    int inv[N];
    int hash_val[N];

    int MOD;

    RollHash(int mod){
        MOD = mod;
    }

    int add(int a , int b) {
        int res = (a+b) % MOD;
        if(res < 0) res += MOD;

        return res;
    }

    int mult(int a , int b) {
        int res = (1LL*a*b) % MOD;
        if(res < 0) res += MOD;

        return res;
    }

    int  power(int a, int b){
        long long result = 1;
        while (b) {
            if (b & 1)
                result = mult(result, a);
            a = mult(a, a);
            b >>= 1;
        }
        return (int) result;
    }

    void precalc(int base){
        pw[0] = 1;
        for(int i = 1 ; i < N ; i++) pw[i] = mult(pw[i-1] , base);

        int inv_pw = power(base , MOD-2); //euler totient theorem

        inv[0] = 1;
        for(int i = 1 ; i < N ; i++) inv[i] = mult(inv[i-1] , inv_pw);
    }

    void build_hash(string &s){
        int n = s.size();
        hash_val[0] = add(0, mult(pw[0], s[0] - 'a' + 1));
        for(int i = 1 ; i < n ; i++){
            hash_val[i] = add(hash_val[i-1], mult(pw[i], s[i] - 'a' + 1));
        }
    }
    int getHash(int l , int r){
        int res = add(hash_val[r] , (l == 0) ? 0 : -hash_val[l-1]);
        res = mult(res , inv[l]);
        return res;
    }
};
void solve() {
// Add your solution here
    string s;
    RollHash r1(1e9+7),r2(1e9+9); //2 different prime numbers for mod

    r1.precalc(31); //pre calculation of powers of base and inverse of base
    r2.precalc(31);

    r1.build_hash(s); //building hash of string
    r2.build_hash(s); //building hash of string
}
int main() {
ios_base::sync_with_stdio(0);
cin.tie(0); cout.tie(0);
int tc = 1;
cin >> tc;
for (int t = 1; t <= tc; t++) {
    solve();
    // cout<<"$"<<endl;
    }
}