#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int static t[100][1000];

int dp(int arr[],int val[],int w,int n){
    if(n==0 || w==0){
        return 0;
    }

    if(t[n][w] != -1){                                    //recursive+memorization solution.
        return t[n][w];
    }

    if(arr[n-1]>w){
        return t[n][w]=dp(arr,val,w,n-1);
    }

    else if(arr[n-1]<=w){
        return t[n][w]= max(val[n-1]+dp(arr,val,w-arr[n-1],n-1),dp(arr,val,w,n-1));
    }
}

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);

memset(t,-1,sizeof(t));

int n,w;
cin>>n>>w;

int arr[n];
int val[n];

for(int i=0;i<n;i++){
    cin>>arr[i];
}

for(int i=0;i<n;i++){
    cin>>val[i];
}

cout<<dp(arr,val,w,n);

return 0;
}