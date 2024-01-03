//https://practice.geeksforgeeks.org/problems/aggressive-cows/1
// J.S.R -- *roush*
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> pbds; //find_by_order //order_of_key

bool IsPossible(int stalls[],int k,int mid,int n){
    int cowCount=1;
    sort(stalls,stalls+n);
    int lastCow=stalls[0];
    for(int i=0;i<n;i++){
        if(stalls[i]-lastCow >= mid){
            cowCount++;
            if(cowCount==k) return true;
            lastCow=stalls[i];
        }
    }
    return false;
    }
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);

int n,k;
cin>>n>>k;

int stalls[n];
for(int i=0;i<n;i++) cin>>stalls[i];

int mx=0;
    for(int i=0;i<n;i++) mx=max(mx,stalls[i]);
    
    int l=0,r=mx;
    int ans=-1;
    while(l<=r){
        int mid = (l+r)/2;
        if(IsPossible(stalls,k,mid,n)){
            ans=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
return 0;
}