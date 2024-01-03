//count the no. of subset with given diff......

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);

int n,u;
cin>>n>>u;

int arr[n];
int sum=0;
for(int i=0;i<n;i++){
    cin>>arr[i];
    sum+=arr[i];
}                                       //error when negative element is present.

    int a=(u+sum)/2;
    
    int t[n+1][a+1];

    for(int i=0;i<n+1;i++){
        for(int j=0;j<a+1;j++){
            if(i==0){
                t[i][j]=0;
            }

            if(j==0){
                t[i][j]=1;
            }
        }
    }

    for(int i=1;i<n+1;i++){
        for(int j=0;j<a+1;j++){
            if(arr[i-1]<=j){
                t[i][j]=(t[i-1][j-arr[i-1]]) + (t[i-1][j]);
            }

            else{
                t[i][j]=t[i-1][j];
            }
        }
    }
    if(sum<abs(u) || (sum+u)%2){
        cout<<"0"<<endl;
    }
    else{
        cout<<t[n][a]<<endl;
    }
    

return 0;
}