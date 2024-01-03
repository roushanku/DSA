//return true or false based on whether subset of give sum exist or not.

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);

int n,s;
cin>>n>>s;

int arr[n];
for(int i=0;i<n;i++){
    cin>>arr[i];
}

int t[n+1][s+1];

for(int i=0;i<n+1;i++){
    for(int j=0;j<s+1;j++){
        if(i==0){
            t[i][j]=false;
        }

        if(j==0){
            t[i][j]=true;
        }
    }
}

for(int i=1;i<n+1;i++){
    for(int j=1;j<s+1;j++){
        if(arr[i-1]<=j){
            t[i][j]=(t[i-1][j-arr[i-1]]) || (t[i-1][j]);
        }

        else{
            t[i][j]=t[i-1][j];
        }
        
    }
}

cout<<t[n][s]<<endl;
return 0;
}