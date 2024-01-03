//longest palindromic subsequences....
// concept---->>>>>>>  LPS(s) = LCS(s,reverse(s))
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int lps(string x){
    int a=x.size();
    string y;
    for(int i=a-1;i>=0;i--){
        y.push_back(x[i]);
    }
    int t[a+1][a+1];
    for(int i=0;i<a+1;i++){
        for(int j=0;j<a+1;j++){
            if(i==0 || j==0){
                t[i][j]=0;
            }
        }
    }

    for(int i=1;i<a+1;i++){
        for(int j=1;j<a+1;j++){
            if(x[i-1]=y[j-1]){
                t[i][j]=1+t[i-1][j-1];
            }
            else{
                t[i][j]=max(t[i-1][j],t[i][j-1]);
            }
        }
    }

    return t[a][a];

}

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int t;
cin>>t;
while(t--){
string x;
cin>>x;

cout<<lps(x)<<endl;
}
return 0;
}