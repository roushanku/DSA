//https://www.codingninjas.com/studio/problems/smallest-divisor-with-the-given-limit_1755882?utm_source=youtube&utm_medium=affiliate&utm_campaign=codestudio_Striver_BinarySeries&leftPanelTab=0
// J.S.R -- *roush*
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> pbds; //find_by_order //order_of_key
bool IsPossible(int mid,vector <int> &arr , int limit){
	long long sum=0;
	for(int i=0;i<arr.size();i++){
		sum += (arr[i]/mid);
		if(arr[i]%mid != 0) sum++;
	}

	return sum<=limit;
}

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);

int n,limit;
cin>>n>>limit;

vector <int> arr;
for(int i=0;i<n;i++){
    int x;
    cin>>x;
    arr.push_back(x);
}

int l=1,r=1e6;
	int ans=0;
	while(l<=r){
		int mid = l + (r-l)/2;
		if(IsPossible(mid,arr,limit)){
			ans=mid;
			r=mid-1;
		}
		else l=mid+1;
	}

cout<< ans <<"\n";
return 0;
}