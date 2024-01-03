//https://www.codingninjas.com/studio/problems/painter-s-partition-problem_1089557?leftPanelTab=1
// J.S.R -- *roush*
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> pbds; //find_by_order //order_of_key

//similar to allocate books
int findLargestMinDistance(vector<int> &arr, int k)
{
    //    Write your code here.
    int sum = 0;
    int n = arr.size();
    int l = -1e9;
    for(int i = 0 ; i < n ; i++) {
        sum += arr[i];
        l = max(l,arr[i]);
    }

    int r = sum;
    int ans = 0;
    while(l<=r){
        int mid = l + (r-l)/2;

        int ct = 1;
        int temp=0;
        for(int i = 0 ; i < n ; i++){
            if(temp + arr[i] > mid){
                ct++;
                temp=arr[i];
            }
            else temp += arr[i];
        }

        if(ct <= k) {
            ans=mid;
            r=mid-1;
            
        }
        else l=mid+1;
    }

    return ans;
}

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int n,k;
cin>>n>>k;

vector <int> arr;
for(int i=0;i<n;i++) {
    int x;
    cin>>x;
    arr.push_back(x);
}

cout<< findLargestMinDistance(arr,k)<<"\n";
return 0;
}