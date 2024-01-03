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
    int n;
    cin>>n;

    long long arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];

    priority_queue <long long , vector<long long> , greater<long long>> q;
    // intuition put each ele in priority queue and add them to sum if sum<0 then start removing ele till sum>0

    long long sum=0;
    long long ans=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        q.push(arr[i]);

        if(sum<0){
            while(sum<0){
                sum-=q.top();
                q.pop();
            }
        }
    }

    cout<<q.size()<<"\n";
return 0;
}