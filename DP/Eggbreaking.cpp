//https://www.geeksforgeeks.org/egg-dropping-puzzle-dp-11/

//MCM pattern variation
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int solve(int e,int f){
    if(f==0 || f==1){
        return f;
    }
    if(e==0){
        return f;
    }

    int ans=INT_MAX;
    for(int k=1;k<=f;k++){
        int op1 = solve(e-1,k-1); // when egg break at kth floor -> threshold floor will be below kth floor with e-1 eggs
        int op2 = solve(e,f-k); // when egg doesnot break -> then we will check the floor above the kth floor with e eggs.
        int temp=1+max(op2,op1);
        ans=min(ans,temp);
    }

    return ans;
}


int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int t;
cin>>t;
while(t--){
int e,f;
cin>>e>>f;

cout<<solve(e,f)<<endl;
}
return 0;
}