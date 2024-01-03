//*roush*
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> pbds; //find_by_order //order_of_key

double multiply(double mid,int n){
    double ans = 1.0;
    for(int i=1;i<=n;i++){
        ans*=mid;
    }
    return ans;
}

double NthRoot(double n,double m){
    double low = 1;
    double high = m;

    double esp = 1e-6;

    while(high-low > esp){
        double mid = (low+high)/2.0;

        if(multiply(mid,n) < m){
            low = mid;
        }
        else{
            high = mid;
        }
    }

    cout<<setprecision(6)<<" "<<high<<"\n"; // print anyone
}

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int t;
cin>>t;
while(t--){
    double n,m;
    cin>>n>>m;

    NthRoot(n,m); //t.c --> O(n*log(m))
}
return 0;
}