// J.S.R -- *roush*
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> pbds; //find_by_order //order_of_key

#include <iostream>
using namespace std;

int segment[100000];
void build(int A[] , int node, int start, int end)
{
    if(start == end)
    {
        // Leaf node will have a single element
        segment[node] = A[start];
    }
    
    else
    {
        int mid = (start + end) / 2;
        // Recurse on the left child
        build(A , 2*node, start, mid);
        // Recurse on the right child
        build(A , 2*node+1, mid+1, end);
        // Internal node will have the sum of both of its children
        segment[node] = min(segment[2*node] , segment[2*node+1]);
    }
}

int query(int node, int start, int end, int l, int r)
{
    if(r < start or end < l)
    {
        // range represented by a node is completely outside the given range
        return 1e9;
    }
    if(l <= start and end <= r)
    {
        // range represented by a node is completely inside the given range
        return segment[node];
    }
    // range represented by a node is partially inside and partially outside the given range
    int mid = (start + end) / 2;
    int p1 = query(2*node, start, mid, l, r);
    int p2 = query(2*node+1, mid+1, end, l, r);
    return (min(p1 , p2));
}

void update(int A[] , int node, int start, int end, int idx, int val)
{
    if(start == end)
    {
        // Leaf node
        A[idx] = min(A[idx] , val);
        segment[node] = min(segment[node] , val);
    }
    else
    {
        int mid = (start + end) / 2;
        if(start <= idx and idx <= mid)
        {
            // If idx is in the left child, recurse on the left child
            update(A , 2*node, start, mid, idx, val);
        }
        else
        {
            // if idx is in the right child, recurse on the right child
            update(A , 2*node+1, mid+1, end, idx, val);
        }
        // Internal node will have the sum of both of its children
        segment[node] = min(segment[2*node] , segment[2*node+1]);
    }
}

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
//patience Bro , thoda sa logic soch k try ur own test case
//hadbad m kaafi gadbad kie ho islie aaram s -> You will do best for Youself
//First, solve the problem. Then, write the code.
    int n,q;
	cin>>n>>q;

	int arr[n];
	for(int i = 0 ; i < n ; i++) cin>>arr[i];

    build(arr , 1 , 0 , n-1);

	while(q--) {
		char a,b,c;
        cin>>a>>b>>c;

		int i = b - 'a' , j = c - '0';

		if(a == 'q') {
            int ans = query(1 , 0 , n-1 , i-1 , j-1);
            cout<<ans<<"\n";
		}

		else {
            update(arr , 1 , 0 , n-1 , i-1 , j);
		}
	}
return 0;
}