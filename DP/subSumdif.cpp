//given an array find min. difference of sum of subset.(min. subset sum diff)
// for non-negative array........

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int sub(int arr[],int n,int sum){
    int t[n+1][sum+1];

    for(int i=0;i<n+1;i++){
        for(int j=0;j<sum+1;j++){
            if(i==0){
                t[i][j]=false;
            }

            if(j==0){
                t[i][j]=true;
            }
        }
    }

    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(arr[i-1]<=j){
                t[i][j]=(t[i-1][j-arr[i-1]]) || (t[i-1][j]);
            }

            else{
                t[i][j]=t[i-1][j];
            }
            
        }
    }

    vector<int> v;
    for(int i=0;i<=sum/2;i++){
        if(t[n][i]==true){
            v.push_back(i);
        }
    }

    int mn=INT_MAX;
    for(int i=0;i<v.size();i++){
        mn=min(mn,(sum-2*v[i]));
    }

    return mn;

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