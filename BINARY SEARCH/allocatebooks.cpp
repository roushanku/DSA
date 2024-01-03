//https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
// J.S.R -- *roush*
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> pbds; //find_by_order //order_of_key

bool ispossible(int arr[],int N,int mid,int m){
    int ct=1;
    int check=mid;
    int sum=0;
    for(int i=0;i<N;i++){
        if(sum+arr[i]>mid){
            ct++;
            sum=arr[i];
        }
        else sum+=arr[i];
    }
    return (ct<=m);
    }
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int n,k;
cin>>n>>k;

int a[n];
for(int i=0;i<n;i++) cin>>a[i];

int sum=0;
for(int i=0;i<n;i++) sum+=a[i];

int l=0,r=sum;
int ans=-1;

while(l<=r){
    int mid = l + (r-l)/2;
    if(ispossible(a,n,mid,k)) {
        ans=mid; // store ans and move to left
        r=mid-1;
    }
    else l=mid+1; //if not possible move right
}
if(k>n) cout<<-1<<"\n";
else cout<<ans<<"\n";
return 0;
}