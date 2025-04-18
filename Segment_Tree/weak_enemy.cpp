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

class segmentTree{
    vector <int> tree;

    public:
        segmentTree(int n){
            tree.resize(4*n+10);
        }

        void build(int i , int l , int r) {
            if(l == r){
                tree[i] = 0;
                return;
            }

            int mid = (l + r) / 2;

            build(2*i+1 , l , mid);
            build(2*i+2 , mid+1 , r);

            tree[i] = tree[2*i+1] + tree[2*i+2];
        }

        void pointUpdate(int i , int l , int r , int idx , int val) {
            if(l == r){
                tree[i] = val;
                return;
            }

            int mid = (l + r) / 2;

            if(idx <= mid){
                pointUpdate(2*i+1 , l , mid , idx , val);
            } else {
                pointUpdate(2*i+2 , mid+1 , r , idx , val);
            }

            tree[i] = tree[2*i+1] + tree[2*i+2];
        }

        int rangeQuery(int i , int l , int r , int ql , int qr) {
            if(l > qr || r < ql) return 0;

            if(l >= ql && r <= qr) return tree[i];

            int mid = (l + r) / 2;

            return rangeQuery(2*i+1 , l , mid , ql , qr) + rangeQuery(2*i+2 , mid+1 , r , ql , qr);
        }
};
void solve() {
// Add your solution here
    int n;
    cin>>n;

    vector <int> arr(n);
    for(int i = 0 ; i < n ; i++) cin>>arr[i];

    vector <int> v = arr;

    map <int,int> mp;
    sort(v.begin() , v.end() , greater<int>());

    for(int i = 0 ; i < n ; i++) {
        if(mp.find(v[i]) == mp.end()){
            mp[v[i]] = i;
        }
    }

    segmentTree st(n);
    st.build(0 , 0 , n-1);
    
    vector <int> left(n);
    for(int i = 0 ; i < n ; i++) {
        int id = mp[arr[i]];

        int sum1 = st.rangeQuery(0 , 0 , n-1 , 0 , id-1);

        left[i] = sum1;

        st.pointUpdate(0 , 0 , n-1 , id , 1);
    }

    segmentTree st2(n);
    st2.build(0 , 0 , n-1);
    vector <int> right(n);

    for(int i = n-1 ; i >= 0 ; i--) {
        int id = mp[arr[i]];

        int sum2 = st2.rangeQuery(0 , 0 , n-1 , id+1 , n-1);

        right[i] = sum2;

        st2.pointUpdate(0 , 0 , n-1 , id , 1);
    }

    // for(auto it : left) cout<<it<<" ";
    // cout<<"\n";

    // for(auto it : right) cout<<it<<" ";
    // cout<<"\n";

    ll ans = 0;
    for(int i = 0 ; i < n ; i++) {
        ans += (ll)left[i] * (ll)right[i];
    }
    cout<<ans<<"\n";
}
int main() {
ios_base::sync_with_stdio(0);
cin.tie(0); cout.tie(0);
int tc = 1;
// cin >> tc;
for (int t = 1; t <= tc; t++) {
solve();
// cout<<"$"<<endl;
}
}