#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int dp[203][203][3];
int exp(string s,int i,int j,int istrue){
    if(i>j){
        return 0;
    }
    if(i==j){
        if(istrue==1){
            return s[i]=='T';
        }
        else{
            return s[i]=='F';
        }
    }

    int ans=0;
    if(dp[i][j][istrue] != -1) return dp[i][j][istrue];
    for(int k=i+1;k<j;k=k+2){
        int lt,lf,rt,rf;
        lt=exp(s,i,k-1,true);
        lf=exp(s,i,k-1,false);
        rt=exp(s,k+1,j,true);
        rf=exp(s,k+1,j,false);

        if(s[k]=='|'){
            if(istrue==true){
                ans+=(lt*rt)+(lt*rf)+(lf*rt);
            }
            else{
                ans+=(lf*rf);
            }
        }

        else if(s[i]=='&'){
            if(istrue==true){
                ans+=(lt*rt);
            }
            else{
                ans+=(lf*rt)+(lf*rf)+(lt*rf);
            }
        }

        else if(s[i]=='^'){
            if(istrue==true){
                ans+=(lt*rf)+(lf*rt);
            }
            else{
                ans+=(lt*rt)+(lf*rf);
            }
        }
    }

    return dp[i][j][istrue] = ans;

}


int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int t;
cin>>t;
while(t--){
string symbol;
cin>>symbol;

string op;
cin>>op;

string s;
int j=0;
for(int i=0;i<symbol.size();i++){
    s.push_back(symbol[i]);
    if(j<symbol.size()){
        s.push_back(op[j++]);
    }
}
//cout<<s<<endl;
int n=s.size();
memset(dp,-1,sizeof(dp));
cout<<exp(s,0,n-1,1)<<endl;

}
return 0;
}