#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int lcs(string x,string y,int n,int m){
    if(n==0 || m==0){
        return 0;
    }

    else{
        if(x[n-1]==y[m-1]){
            return 1+lcs(x,y,n-1,m-1);
        }
        else{
            return max(lcs(x,y,n-1,m),lcs(x,y,n,m-1));

        }
    }
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int t;
cin>>t;
while(t--){
int n,m;
cin>>n>>m;

string x,y;
cin>>x>>y;

cout<<lcs(x,y,n,m)<<endl;
}
return 0;
}