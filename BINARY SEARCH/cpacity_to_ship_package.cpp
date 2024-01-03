//https://www.codingninjas.com/studio/problems/capacity-to-ship-packages-within-d-days_1229379?utm_source=youtube&utm_medium=affiliate&utm_campaign=codestudio_Striver_BinarySeries&leftPanelTab=0
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

int n,d;
cin>>n>>d;

vector <int> arr;
for(int i=0;i<n;i++){
    int x;
    cin>>x;

    arr.push_back(x);
}

int l=*max_element(arr.begin(),arr.end());
int r = accumulate(arr.begin(),arr.end(),0);

int n = arr.size();
int ans=0;
//same concept as in allocate books
while(l<=r){
    int mid = l + (r-l)/2;

    //calculation of ct
    int sum=0,ct=1;
    for(int i=0;i<n;i++){
        if(sum+arr[i]>mid) {
            ct++;
            sum=arr[i];
        }
        else{
            sum+=arr[i];
        }
    }
    //

    if(ct<=d){
        ans=mid;
        r=mid-1;
    }
    else l=mid+1;
}

cout<< ans <<"\n";
return 0;
}