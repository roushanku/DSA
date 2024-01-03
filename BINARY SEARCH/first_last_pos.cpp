//https://www.codingninjas.com/studio/problems/first-and-last-position-of-an-element-in-sorted-array_1082549?utm_source=youtube&utm_medium=affiliate&utm_campaign=codestudio_Striver_BinarySeries&leftPanelTab=1
// J.S.R -- *roush*
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> pbds; //find_by_order //order_of_key

pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    // Write your code here
    bool ok = true;
    
    int i = lower_bound(arr.begin(),arr.end(),k) - arr.begin();

    int j = upper_bound(arr.begin(),arr.end(),k) - arr.begin();

    if(i==n || arr[i]!=k) ok=false; // to check ele is not present

    if(ok){
        return {i,j-1};
    }
    else return {-1,-1};
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int n,k;
cin>>n>>k;

vector <int> arr(n);
for(int i=0;i<n;i++) cin>>arr[i];

cout<<firstAndLastPosition(arr,n,k).first<<" "<<firstAndLastPosition(arr,n,k).second<<"\n";
return 0;
}