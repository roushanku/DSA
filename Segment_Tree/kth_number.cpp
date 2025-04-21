#include <iostream>
#include<bits/stdc++.h>
using namespace std;
 
class segmentTree{
    vector<vector<int>> tree;
    public:
        segmentTree(int n) {
            tree.resize(4*n+10);
        }
        
        void build(int i , int l , int r , vector <int> &arr) {
            if(l == r) {
                tree[i] = {arr[l]};
                return;
            }
            
            int mid = l + (r-l) / 2;
            
            build(2*i+1,l,mid,arr);
            build(2*i+2,mid+1,r,arr);
            
            tree[i] = Merge(tree[2*i+1] , tree[2*i+2]);
        }
        
        vector <int> Merge(vector <int> &left , vector <int> &right) {
            vector <int> v;
            int i = 0 , j = 0;
            int n = left.size() , m = right.size();
            
            while(i < n && j < m) {
                if(left[i] <= right[j]) {
                    v.push_back(left[i]);
                    i++;
                }
                else {
                    v.push_back(right[j]);
                    j++;
                }
            }
            
            while(i < n) {
                v.push_back(left[i]);
                i++;
            }
            
            while(j < m) {
                v.push_back(right[j]);
                j++;
            }
            
            return v;
        }
        
        int query(int i , int l , int r , int ql , int qr , int k) {
            if(l > qr || r < ql) return 0;
            
            if(l >= ql && r <= qr) {
                int id = upper_bound(tree[i].begin() , tree[i].end() , k) - tree[i].begin();
                
                return tree[i].size()-id;
            }
            
            int mid = l + (r-l) / 2;
            
            return query(2*i+1,l,mid,ql,qr,k) + query(2*i+2,mid+1,r,ql,qr,k);
        }
};
 
int main()
{
    // https://www.spoj.com/problems/MKTHNUM/
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n,q;
    cin>>n>>q;
    
    vector <int> arr(n);
    for(int i = 0 ; i < n ; i++) cin>>arr[i];
    
    segmentTree st(n);
    st.build(0,0,n-1,arr);

    int mn = *min_element(arr.begin() , arr.end());
    int mx = *max_element(arr.begin() , arr.end());
    
    
    while(q--) {
        int i,j,k;
        cin>>i>>j>>k;
        
        i--;j--;
        
        int l = mn , r = mx;

        int ans = -1;

        while(l <= r) {
            int mid = l + (r-l) / 2;
            int larger_ele = st.query(0,0,n-1,i,j,mid);
            int smaller_ele = (j-i+1) - larger_ele;

            if(smaller_ele >= k) {
                ans = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }

        cout<<ans<<"\n";
    }
 
    return 0;
} 