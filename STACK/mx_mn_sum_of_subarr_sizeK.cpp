//https://www.codingninjas.com/studio/problems/sum-of-minimum-and-maximum-elements-of-all-subarrays-of-size-k_1171047?leftPanelTab=0
// J.S.R -- *roush*
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> pbds; //find_by_order //order_of_key
vector <int> MAX(vector<int> &arr,int k) {
    vector <int> ans;
	int n = arr.size();
	deque <int> dq;
	int i=0,j=0;
	while(j<n){
		
		while(!dq.empty() && arr[j]>=arr[dq.back()]) dq.pop_back();
		
			dq.push_back(j);
		
		if(j-i+1==k){
			ans.push_back(arr[dq.front()]);
			if(dq.front()==i) dq.pop_front();
			i++;
			
		}
		j++;
	}
    return ans;
}

vector <int> MIN(vector<int> &arr,int k) {
    vector <int> mn;
	deque <int> dqu;
    int n = arr.size();
	int i=0,j=0;

	while(j<n){
		while(!dqu.empty() && arr[j]<=arr[dqu.back()]) dqu.pop_back();

		dqu.push_back(j);

		if(j-i+1 == k){
			mn.push_back(arr[dqu.front()]);

			if(dqu.front()==i) dqu.pop_front();
			i++;
		}

		j++;
	}
    return mn;
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);

int n,k;
cin>>n>>k;

vector <int> arr;
for(int i = 0 ; i < n ; i++) {
    int x;
    cin>>x;

    arr.push_back(x);
}
long long sum = 0;
vector <int> MX = MAX(arr,k);
for(auto it:MX) {
    cout<<it<<" ";
    sum += it;
}
cout<<"\n";

vector <int> MN = MIN(arr,k);
for(auto it:MN) {
    cout<<it<<" ";
    sum += it;
}
cout<<sum;
cout<<"\n";
return 0;
}