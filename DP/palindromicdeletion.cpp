//https://www.includehelp.com/icp/minimum-number-of-deletions-to-make-a-string-palindrome.aspx
//concept---->>>> req. palindrmic string will be LPS. So, no of deletion req = n-len(LPS).
//LPS(s) = LCS(s,reverse(s))

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int ro(string s){
    string x;
    int n=s.size();
    for(int i=n-1;i>=0;i--){
        x.push_back(s[i]);
    }

    int t[n+1][n+1];
    for(int i=0;i<n+1;i++){
        for(int j=0;j<n+1;j++){
            if(i==0 || j==0){
                t[i][j]=0;
            }
        }
    }

    for(int i=1;i<n+1;i++){
        for(int j=1;j<n+1;j++){
            if(s[i-1]==x[j-1]){
                t[i][j]=1+t[i-1][j-1];
            }
            else{
                t[i][j]=max(t[i-1][j],t[i][j-1]);
            }
        }
    }

    return(n-t[n][n]);
}

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int t;
cin>>t;
while(t--){
int n;
cin>>n;

string s;
cin>>s;

cout<<ro(s)<<endl;
}
return 0;
}