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

int segTree[800001];

void buildTree(int id , int l , int r , vector <int> &arr) {
    if(l == r) {
        segTree[id] = arr[l];
        return;
    }

    int mid = l + (r-l) / 2;
    buildTree(2*id+1 , l , mid , arr);
    buildTree(2*id+2 , mid+1 , r , arr);

    segTree[id] = min(segTree[2*id+1] , segTree[2*id+2]);
}

void update(int id , int l , int r , int index , int val) {
    if(l == r) {
        segTree[id] = val;
        return;
    }

    int mid = l + (r-l) / 2;

    if(index <= mid) update(2*id+1 , l , mid , index , val);
    else update(2*id+2 , mid+1 , r , index , val);

    segTree[id] = min(segTree[2*id+1] , segTree[2*id+2]);
}

int query(int id , int l , int r , int start , int end) {
    if(l > end || r < start) return 1e9;

    if(l >= start && r <= end) return segTree[id];

    int mid = l + (r-l) / 2;

    return min(query(2*id+1 , l , mid , start , end) , query(2*id+2 , mid+1 , r , start , end));
}
void solve() {
// Add your solution here
    int n,q;
    cin>>n>>q;

    vector <int> arr(n);
    for(int i = 0 ; i < n ; i++) cin>>arr[i];

    buildTree(0 , 0 , n-1 , arr);

    while(q--) {
        int ch;
        cin>>ch;

        if(ch == 1) {
            int k,u;
            cin>>k>>u;

            k--;

            update(0 , 0 , n-1 , k , u);
        }

        else {
            int a,b;
            cin>>a>>b;
            a--;b--;
            int ans = query(0 , 0 , n-1 , a , b);
            cout<<ans<<"\n";
        }
    }
}
int main() {
ios_base::sync_with_stdio(0);
cin.tie(0); cout.tie(0);
solve();
}