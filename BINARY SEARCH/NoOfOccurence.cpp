//https://www.youtube.com/redirect?event=video_description&redir_token=QUFFLUhqbkNkZFczd29mY250b3FfTVQxWUU4bU5GQ0lLd3xBQ3Jtc0tsLXJ5RklVOTdMSEtma3l3YzFCaU5TWnljNUt1UlM1NFhyZDNRNTh0ZmtUNHE1NlBnQk1Ed1lrTjlRQl9TMWxnRlVnS3ZQMHpoLXpMelRBZmoxNC14QnVTeldVOEstVk5RV2tZb1ZLMzZibTZzby0tOA&q=https%3A%2F%2Fbit.ly%2F42ZDqM4&v=hjR1IYVx9lY
// J.S.R -- *roush*
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> pbds; //find_by_order //order_of_key
int count(vector<int>& arr, int n, int x) {
	// Write Your Code Here
	int i = lower_bound(arr.begin(),arr.end(),x) - arr.begin();
	int j = upper_bound(arr.begin(),arr.end(),x) - arr.begin();

	return j-i;
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int n,x;
cin>>n>>x;

vector <int> arr(n);
for(int i=0;i<n;i++) cin>>arr[i];

cout<<count(arr,n,x)<<"\n";
return 0;
}