//https://www.codingninjas.com/studio/problems/minimum-rate-to-eat-bananas_7449064?utm_source=youtube&utm_medium=affiliate&utm_campaign=codestudio_Striver_BinarySeries
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

int n,h;
cin>>n>>h;

vector <int> v;
for(int i=0;i<n;i++){
    int x;
    cin>>x;

    v.push_back(x);
}

int l = 1 , r = 1e9;
int ans=0;
while(l<=r){
    int mid = l + (r-l)/2;
    int ct=0;
    for(int i=0;i<v.size();i++){
        ct += (v[i]/mid);
        if(v[i]%mid!=0){
            ct++;
        }
    }
    if(h>=ct){
        ans = mid;
        r=mid-1;
    }
    else l=mid+1;
}

cout<< ans <<"\n";
return 0;
}