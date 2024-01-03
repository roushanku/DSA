//print shortest common supersequence.
// variation of print LCS..

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string scs(string x,string y){
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

    string ans=" ";
    int i=a;
    int j=b;
    while(i>0 && j>0){
        if(x[i-1]==y[j-1]){
            ans.push_back(x[i-1]);
            i--;
            j--;
        }
        else{
            if(t[i-1][j]>t[i][j-1]){
                ans.push_back(x[i-1]);
                i--;
            }
            else{
                ans.push_back(y[j-1]);
                j--;
            }
        }
    }

    while(i>0){
        ans.push_back(x[i-1]);
        i--;
    }

    while(j>0){
        ans.push_back(y[j-1]);
        j--;
    }

    reverse(ans.begin(),ans.end());
    return ans;

}

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int t;
cin>>t;
while(t--){
    string x,y;
    cin>>x>>y;

    cout<<scs(x,y)<<endl;
}
return 0;
}