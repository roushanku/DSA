//https://www.geeksforgeeks.org/palindrome-partitioning-dp-17/
//recursive approach--->>>> four step
// 1. find i,j---->>> i=0,j=n-1 .. 2.base condn--->>> i>=j---->>> return 0.
// if string is palindrom then---->>>> return 0.  3.recursive fucn  4.take min.

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool ispalin(string s,int i,int j){
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

    int ans=INT_MAX;
    for(int k=i;k<j;k++){
        ans=min(ans,palpar(s,i,k)+palpar(s,k+1,j)+1);
    }
    
    return ans;

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

cout<<palpar(s,i,j)<<endl;
}
return 0;
}