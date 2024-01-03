//recursive approach..

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int mcm(int arr[],int i,int j){
    if(i>=j){
        return 0;
    }
    int temp=0;
    int mn=INT_MAX;
    // two scheme r possiple for breaking the partition:
    //1 . k=i -> k=j-1 --> (i,k) & (k+1,j)
    //2. k=i+1, k=j -> (i,k-1) & (k,j)
    for(int k=i;k<j;k++){
        temp=(mcm(arr,i,k)+mcm(arr,k+1,j)+(arr[i-1]*arr[k]*arr[j])); // using firts choice of breaking the partition
        mn=min(temp,mn);
    }

    return mn;
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

cout<<mcm(arr,1,n-1)<<endl;
}
return 0;
}