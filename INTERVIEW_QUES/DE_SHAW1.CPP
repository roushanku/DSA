 //given an array and max_move u need to find min no x such that on substracting x to each arr[i] -> arr become <=0
 // J.S.R -- *roush*
 #include<iostream>
 #include<bits/stdc++.h>
 using namespace std;
 const int mod = 1000000007;
 #include <ext/pb_ds/assoc_container.hpp>
 #include <ext/pb_ds/tree_policy.hpp>
 using namespace __gnu_pbds;
 typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> pbds; //find_by_order //order_of_key
 int n,m;
 bool IsValid(int arr[],int mid){
    //bool ok = false;
    int ct=0;
    for(int i=0;i<n;i++){
        if(arr[i]<=mid){
            ct++;
        }

        else{
            ct += (arr[i]/mid);
            if(arr[i]%mid != 0) ct++;
        }
    }

    return ct<=m;
 }
 int main(){
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);
 int t;
 cin>>t;
 while(t--){
    
    cin>>n>>m;

    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];

    sort(arr,arr+n);

    int l=0,r=1e9;
    int ans=-1;
    while(l<=r){
        int mid = l + (r-l)/2;
        if(IsValid(arr,mid)){
            ans=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    
    cout<<ans<<"\n";   
 }
 return 0;
 }