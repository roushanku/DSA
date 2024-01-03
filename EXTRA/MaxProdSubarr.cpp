// J.S.R -- *roush*
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> pbds; //find_by_order //order_of_key

long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int t;
cin>>t;
while(t--){
    // int n;
    // cin>>n;

    // int arr[n];
    // for(int i=0;i<n;i++) cin>>arr[i];

    // int prod = 1;
    // int ans = INT_MIN;

    // for(int i=0;i<n;i++){
    //     prod*=arr[i];
    //     ans=max(ans,prod);
    //     if(arr[i]==0) prod=1;
    // }       

    // prod=1;
    // for(int i=n-1;i>=0;i--){
    //     prod*=arr[i];
    //     ans=max(ans,prod);
    //     if(arr[i]==0) prod=1;
    // }

    // cout<<ans<<"\n";
    int n,m;
    cin>>n>>m;

    cout<<binpow(n,m)<<"\n";
}
return 0;
}