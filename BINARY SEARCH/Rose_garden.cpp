//https://www.codingninjas.com/studio/problems/rose-garden_2248080?utm_source=youtube&utm_medium=affiliate&utm_campaign=codestudio_Striver_BinarySeries
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

int n,k,m;
cin>>n>>m>>k;

vector <int> arr;
for(int i=0;i<n;i++){
    int x;
    cin>>x;

    arr.push_back(x);
}

int l = 1 , r=1e9;
int ans=0;
while(l<=r){
    int mid = l + (r-l)/2;
    //calculate ct
    int j=0,i=0;
    int ct=0;
    while(j<n && i<n){
        if(arr[j]>mid){
            i=j+1;
        }

        if(j-i+1==k) {
            ct++;
            i=j+1;
        }
        j++;
    }
    //
    if(ct>=m){
        ans=mid;
        r=mid-1;
    }
    else l=mid+1;
}

if(ans==0) cout<< -1 <<"\n";
else cout<< ans <<"\n";
return 0;
}