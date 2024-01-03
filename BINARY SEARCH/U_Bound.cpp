// J.S.R -- *roush*
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> pbds; //find_by_order //order_of_key

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);

int n,x;
cin>>n>>x;

int arr[n];
for(int i=0;i<n;i++) cin>>arr[i];

int l=0,r=n-1;
while(l<=r){
    int mid = l + (r-l)/2;
    if(x>=arr[mid]) l = mid+1;
    else r = mid-1;
}

if(l<n && arr[l]<=x) l++;

cout<<l<<"\n";
return 0;
}