//https://codeforces.com/blog/entry/73558
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

vector <int> days(n,0);
for(int i=0;i<n;i++){
    int no_worker;
    cin>>no_worker;
    int mask=0;
    for(int j = 0 ; j < no_worker ; j++){
        
        int day;
        cin>>day;

        mask = (mask | (1<<day)); //setting the ith bit for ith day
    }
    days[i]=mask;

}
int ans=-1e9;
for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
        int common = days[i] & days[j]; 
        int ct = __builtin_popcount(common); // couting no of set bit
        ans=max(ans,ct);
    }
}

cout<<ans<<"\n";
return 0;
}