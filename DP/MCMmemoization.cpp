//memoization..
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int dp[1000][1000];      //constraint <=10000.

int mcm(int arr[],int i,int j){
    if(i>=j){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    dp[i][j]=INT_MAX;
    for(int k=i;k<j;k++){
        dp[i][j]=min(dp[i][j],mcm(arr,i,k)+mcm(arr,k+1,j)+(arr[i-1]*arr[k]*arr[j]));                 
    }

    return dp[i][j];

}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int t;
cin>>t;
while(t--){
int n;
cin>>n;
int arr[n];
for(int i=0;i<n;i++){
    cin>>arr[i];
}
memset(dp,-1,sizeof(dp));

cout<<mcm(arr,1,n-1)<<endl;

}
return 0;
}