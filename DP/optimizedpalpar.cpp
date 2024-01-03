
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int static dp[1001][1001]; //------>>> matrix for storing.(contraint size of string).

bool ispalin(string s,int i,int j){//----->>>> for checking if string is palindrom or not...
    while(i<j){
        if(s[i]!=s[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int palpar(string s,int i,int j){
    if(i>=j){
        return 0;
    }
    if(ispalin(s,i,j)){
        return 0;
    }

    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    int ans=INT_MAX;
    int left,right;
    for(int k=i;k<j;k++){
        //ans=min(ans,palpar(s,i,k)+palpar(s,k+1,j)+1);//---->>> optimization took place here we will check for if palpar(s,i,j),palpar(s,k+1,j)
        // is stored or not if not we will find and will stored for further use...
        if(dp[i][k]!=-1){
            left=dp[i][k];
        }
        if(dp[i][k]==-1){
            left=palpar(s,i,k);
        }
        if(dp[k+1][j]!=-1){
            right=dp[k+1][j];
        }
        if(dp[k+1][j]==-1){
            right=palpar(s,k+1,j);
        }
        ans=min(ans,1+left+right);
    }
    
    return dp[i][j]=ans;

}

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int t;
cin>>t;
while(t--){
string s;
cin>>s;

int n=s.size();
int i=0;
int j=n-1;
memset(dp,-1,sizeof(dp));
cout<<palpar(s,i,j)<<endl;
}
return 0;
}