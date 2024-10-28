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

class BinaryLifting{
    public:
    vector<vector<int>> anc;
    int n;

    BinaryLifting(int n){
        this->n = n;
        anc.assign(n,vector<int>(20,-1));
    }

    void build_anc(vector <int> &parent) {
        for(int i = 0 ; i < n ; i++) anc[i][0] = parent[i];
        for(int j = 1 ; j < 20 ; j++) {
            for(int i = 0 ; i < n ; i++) {
                if(anc[i][j-1] != -1) {
                    anc[i][j] = anc[anc[i][j-1]][j-1];
                }
            }
        }
    }

    int kth_ancestor(int node,int k) {
        for(int i = 0 ; i < 20 ; i++) {
            if(k & (1<<i)) {
                node = anc[node][i];
                if(node == -1) return -1;
            }
        }
        return node;
    }
};
void solve() {
// Add your solution here
    int n,q;
    cin>>n>>q;

    vector <int> parent(n);
    parent[0] = -1;
    for(int i = 1 ; i < n ; i++) {
        cin>>parent[i];
        parent[i]--;
    }

    BinaryLifting bl(n);
    bl.build_anc(parent);

    while(q--) {
        int x,k;
        cin>>x>>k;
        int ans = bl.kth_ancestor(x-1,k);
        if(ans == -1) cout<<"-1\n";
        else cout<<ans+1<<"\n";
    }
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