//https://www.geeksforgeeks.org/sum-of-maximum-elements-of-all-possible-sub-arrays-of-an-array/
// J.S.R -- *roush*
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> pbds; //find_by_order //order_of_key
    long long findMaxSum(vector <int> arr, int n)
{
    // Arrays for maintaining left and right count
   // int CL[n] = { 0 }, CR[n] = { 0 };
   vector <long long> CL(n,0) , CR(n,0);

    // Stack for storing the indexes
    stack<long long> q;
 
    // Calculate left count for every index
    for (int i = 0; i < n; i++) {
        while (q.size() != 0 && arr[q.top()] <= arr[i]) {
            CL[i] += CL[q.top()] + 1;
            q.pop();
        }
        q.push(i);
    }
 
    // Clear the stack
    while (q.size() != 0)
        q.pop();
 
    // Calculate right count for every index
    for (int i = n - 1; i >= 0; i--) {
        while (q.size() != 0 && arr[q.top()] < arr[i]) {
            CR[i] += CR[q.top()] + 1;
            q.pop();
        }
        q.push(i);
    }
 
    // Clear the stack
    while (q.size() != 0)
        q.pop();
 
    // To store the required sum
    long long ans = 0;
 
    // Calculate the final sum
    for (int i = 0; i < n; i++)
        ans += (CL[i] + 1) * (CR[i] + 1) * arr[i];
 
    return ans;
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);

int n;
cin>>n;

vector <int> arr(n);
for(int i=0;i<n;i++) cin>>arr[i];

int ans = findMaxSum(arr , n);

cout<<ans<<"\n";
return 0;
}