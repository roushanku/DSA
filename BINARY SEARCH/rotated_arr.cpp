//https://www.codingninjas.com/studio/problems/search-in-rotated-sorted-array_1082554?utm_source=youtube&utm_medium=affiliate&utm_campaign=codestudio_Striver_BinarySeries&leftPanelTab=0
// J.S.R -- *roush*
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> pbds; //find_by_order //order_of_key
//approach -> 1
// int search(vector<int>& arr, int n, int k)
// {
//     // Write your code here.
//     // Return the position of K in ARR else return -1.
//     if(n==1 && arr[0]==k) return 0;
//     int l=0,r=n-1;
//     int ans = -1;
//     while(l<=r){
//         int mid = l + (r-l)/2;
//         if(arr[mid]>arr[(mid+1)%n]){
//             ans = mid;
//             break;
//         }
//         else if(arr[mid]<arr[0]) r =mid-1;
//         else if(arr[mid]>=arr[0]) l=mid+1;
//     }

//     if(k<arr[0]){
//         int a=-1;
//         int lo = ans+1,hi=n-1;
//         while(lo<=hi){
//             int mi = lo+(hi-lo)/2;
//             if(arr[mi]==k){
//                 a=mi;
//                 break;
//             } 
//             else if(arr[mi]>k) hi=mi-1;
//             else lo=mi+1;
//         }

//         return a;
//     }

//     else{
//         int b=-1;
//         int le=0,ri=ans;
//         while(le<=ri){
//             int m = le + (ri-le)/2;
//             if(arr[m]==k){
//                 b=m;
//                 break;
//             }
//             else if(arr[m]>k) ri=m-1;
//             else le=m+1;
//         }
//         return b;
//     }
// }

//approach -> 2
int search(vector<int> &arr,int n,int k){
 
    int l = 0,r=n-1;
    while(l<=r){
        int mid = l + (r-l)/2;
        if(arr[mid]==k) return mid;

        if(arr[l]<=arr[mid]){ // right part
            if(arr[l]<=k && k<=arr[mid]) r=mid-1;
            else l=mid+1;
        }

        else{ //left part
            if(arr[mid]<=k && k<=arr[r]){
                l=mid+1;
            }
            else r=mid-1;
        }
    }
    return -1;
}

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int n,k;
cin>>n>>k;

vector <int> arr(n);
for(int i = 0 ; i < n ; i++) cin>>arr[i];

cout<<search(arr,n,k)<<"\n";
return 0;
}