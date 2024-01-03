//find max no. of ways so that total sum is W.(unlimited supply of each given coin)

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int coin(long long arr[],int n,int w){
    int long long t[n+1][w+1];
    for(int i=0;i<n+1;i++){
        for(int j=0;j<w+1;j++){
            if(i==0){
                t[i][j]=0;
            }

            if(j==0){
                t[i][j]=1;
            }
        }
    }

    for(int i=1;i<n+1;i++){
        for(int j=1;j<w+1;j++){
            if(arr[i-1]<=j){
                t[i][j]=(t[i][j-arr[i-1]]+t[i-1][j]);
            }
            else{
                t[i][j]=t[i-1][j];
            }
        }
    }

    return t[n][w];

}

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);

int n,w;
cin>>n>>w;

long long arr[n];
for(int i=0;i<n;i++){
    cin>>arr[i];
    }

cout<<coin(arr,n,w)<<endl;
return 0;
}