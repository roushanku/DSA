//https://www.geeksforgeeks.org/shortest-common-supersequence/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int super(string x,string y){
    int a=x.size();
    int b=y.size();

    int t[a+1][b+1];
    for(int i=0;i<a+1;i++){
        for(int j=0;j<b+1;j++){
            if(i==0 || j==0){
                t[i][j]=0;
            }
        }
    }
    for(int i=1;i<a+1;i++){
        for(int j=1;j<b+1;j++){
            if(x[i-1]==y[j-1]){
                t[i][j]=1+t[i-1][j-1];
            }
            else{
                t[i][j]=max(t[i-1][j],t[i][j-1]);
            }
        }
    }
    return(a+b-t[a][b]);
}

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int t;
cin>>t;
while(t--){
string x,y;
cin>>x>>y;

cout<<super(x,y)<<endl;
}
return 0;
}