// J.S.R -- *roush*
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> pbds; //find_by_order //order_of_key

int m;
int segment[10000];
int arr[];
//build tree
void BuildTree(int node, int start, int end)
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
        BuildTree(2*node, start, mid);
        // Recurse on the right child
        build(2*node+1, mid+1, end);
        // Internal node will have the sum of both of its children
        segment[node] = segment[2*node] + segment[2*node+1];
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

BuildTree(arr , 1 , 0 , n-1);

while(q--) {
    int id,val;
    cin>>id>>val;

}
return 0;
}