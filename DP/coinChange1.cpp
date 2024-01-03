//find min. no. of coins req.....
//https://leetcode.com/problems/coin-change/----->>> accepted.

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int rou(int coin[],int n,int sum){
    int t[n+1][sum+1];
    for(int i=0;i<n+1;i++){
        for(int j=0;j<sum+1;j++){
            if(j==0){
                t[i][j]=0;
            }
            if(i==0){
                t[i][j]=1e5;
            }
        }
    }

    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(coin[i-1]<=j){
                t[i][j]=min(t[i-1][j],1+t[i][j-coin[i-1]]);
            }
            else{
                t[i][j]=t[i-1][j];
            }
        }
    }

    return t[n][sum]>1e4 ? -1:t[n][sum];
}

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int n,sum;
cin>>n>>sum;

int coin[n];
for(int i=0;i<n;i++){
    cin>>coin[i];
}

cout<<rou(coin,n,sum)<<endl;
return 0;
}