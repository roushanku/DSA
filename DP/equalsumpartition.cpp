//return true or false based on whether we can have two non-empty subset of equal sum.

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool sub(int arr[],int n,int sum){
    if(sum%2){
        return false;
    }

    else{
        int s=sum/2;
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
        }                                   //success.

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


        return (t[n][s]);
    }
}

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);

int n;
cin>>n;

int arr[n];
int sum=0;

for(int i=0;i<n;i++){
    cin>>arr[i];
    sum+=arr[i];
}

cout<<sub(arr,n,sum)<<endl;

return 0;
}