#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//variation on unbounded kanpsack -> bcz rod length can have of same lenght -->> 4 ->> 1 + 1 + 1 + 1
int rod(int n,int l,int len[],int val[]){
    int t[n+1][l+1];
    for(int i=0;i<n+1;i++){
        for(int j=0;j<l+1;j++){
            if(i==0 || j==0){
                t[i][j]=0;
            }
        }

    for(int i=1;i<n+1;i++){
        for(int j=1;j<l+1;j++){
            if(len[i-1]<=j){
                t[i][j]=max(val[i-1]+t[i][j-len[i-1]],t[i-1][j]);
            }
            else{
                t[i][j]=t[i-1][j];
            }
        }
    }

    return t[n][l];

    }
}

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);

int n,l;
cin>>n>>l;

int len[n];
int val[n];

for(int i=0;i<n;i++){
    cin>>len[i];
}

for(int i=0;i<n;i++){
    cin>>val[i];
}

cout<<rod(n,l,len,val)<<endl;
return 0;
}