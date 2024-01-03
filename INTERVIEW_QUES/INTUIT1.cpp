//https://www.geeksforgeeks.org/count-substrings-with-number-of-0s-and-1s-in-ratio-of-x-y/
// J.S.R -- *roush*
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> pbds; //find_by_order //order_of_key
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int t;
cin>>t;
while(t--){
    int x,y;
    cin>>x>>y;

    //let no of '0' = a and '1'=b -> a/b = x/y => a(-y)+bx=0 -> no of subarr with sum=0

    string s;
    cin>>s;

    int n = s.size();
    vector <int> v;
    for(int i=0;i<s.size();i++){
        if(s[i]=='0'){
            v.push_back(-y);
        }
        else v.push_back(x);
    }

    // int pre[n] = {0};
    // pre[0]=v[0];
    // for(int i=1;i<n;i++){
    //     pre[i] = pre[i-1]+v[i];
    // }

    unordered_map <int,int> mp;
    int sum=0;
    int ct=0;
    for(int i=0;i<n;i++){
        sum+=v[i];

        if(sum==0) ct++;

        if(mp.find(sum) != mp.end()){
            ct+=mp[sum];
            
        }
        mp[sum]++;
    }

    cout<<ct<<"\n";

}
return 0;
}