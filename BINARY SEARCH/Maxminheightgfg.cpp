//https://practice.geeksforgeeks.org/problems/899540d741547e2d75d1c5c03a4161ab53affd13/1
// J.S.R -- *roush*
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> pbds; //find_by_order //order_of_key

bool IsPossible(int a[],int k,int mid,int n,int w){
    vector <long long> presum(n+1,0);
    long long ct=0;
    for(int i=0;i<n;i++){
        if(i>0){
            presum[i]+=presum[i-1];
        }
        
        if(a[i]+presum[i]<mid){
            long long req = mid-a[i]-presum[i];
            
            ct+=req;
            presum[i]+=req;
            
            if(i+w<n) presum[i+w]-=req;
        }
    }
    if(ct<=k) return true;
    else return false;
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int n,k,w;
cin>>n>>k>>w;

int arr[n];
for(int i=0;i<n;i++) cin>>arr[i];

long long l=0;
            
long long r = 1e14;
long long ans=-1;
while(l<=r){
    int mid = (l+r)/2;
    if(IsPossible(arr,k,mid,n,w)){ // min height to mid height bna skte h ki nhi
        ans=mid;
        l=mid+1; //if yes search for better
    }
    else r=mid-1;
}

cout<<ans<<"\n";

return 0;
}