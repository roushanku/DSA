//bottom-up dp || memoization(optimized)...
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int static dp[1001][1001];//------>>> constraint..

int solve(int e,int f){
    if(f==0 || f==1){
        return f;
    }
    if(e==0){
        return f;
    }

    if(dp[e][f]!=-1){
        return dp[e][f];
    }

    int ans=INT_MAX;
    int b,nb;
    for(int k=1;k<=f;k++){
        //int temp=1+max(solve(e-1,k-1),solve(e,f-k)); ---->>> not optimized below code are optimized memoization..
        if(dp[e-1][k-1]!=-1){
            b=dp[e-1][k-1];
        }
        if(dp[e-1][k-1]==-1){
            b=solve(e-1,k-1);
            dp[e-1][k-1]=b;
        }
        if(dp[e][f-k]!=-1){
            nb=dp[e][f-k];
        }
        if(dp[e][f-k]==-1){
            nb=solve(e,f-k);                   //------>> error????????
            dp[e][f-k]=nb;
        }
        int temp=1+max(b,nb);
        ans=min(ans,temp);
    }
    //return ans.---->>>> before optimization.
    return dp[e][f]=ans;
}


int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int t;
cin>>t;
while(t--){
int e,f;
cin>>e>>f;

memset(dp,-1,sizeof(dp));
cout<<solve(e,f)<<endl;
}
return 0;
}