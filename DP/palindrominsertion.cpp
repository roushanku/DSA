//no. of insertion req to make a string palinderom.
//concept ---->>>>  same as no of deletion --->>> here we will add the char which are not paticipated in palinderome
// == lenght-len(lps).

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int palin(string s){
    int n=s.size();
    int t[n+1][n+1];
    string x;
    for(int i=n-1;i>=0;i--){
        x.push_back(s[i]);
    }

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
    return (n-t[n][n]);
}

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int t;
cin>>t;
while(t--){
string s;
cin>>s;

cout<<palin(s)<<endl;
}
return 0;
}