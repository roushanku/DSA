//https://www.geeksforgeeks.org/minimum-number-deletions-insertions-transform-one-string-another/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
pair<int,int> ro(string x,string y){
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
    pair<int,int> p;
    p.first=a-t[a][b];
    p.second=b-t[a][b];
    return p;
}

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int t;
cin>>t;
while(t--){
string x,y;
cin>>x>>y;

cout<<ro(x,y).first<<" "<<ro(x,y).second<<endl;
}
return 0;
}