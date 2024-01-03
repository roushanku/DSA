// J.S.R -- *roush*
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> pbds; //find_by_order //order_of_key

class Disjointset{
    vector <int> rank, parent , size;

    public:
        Disjointset(int n) {
            rank.resize(n+1,0); // cover both 1 based indexing and 0 based indexing graph
            parent.resize(n+1);
            size.resize(n+1);
            for(int i = 0 ; i <= n ; i++) {
                parent[i] = i;
                size[i] = 1;
            }
        }

        int findUparent(int node) {
            if(node == parent[node]) return node;;

            return parent[node] = findUparent(parent[node]);
        }

        void unionbyRank(int u , int v) {
            int ulp_u = findUparent(u);
            int ulp_v = findUparent(v);

            if(ulp_u == ulp_v) return;

            if(rank[ulp_u] < rank[ulp_v]) {
                parent[ulp_u] = ulp_v;
            }

            else if(rank[ulp_u] < rank[ulp_v]) {
                parent[ulp_u] = ulp_v;
            }

            else{
                parent[ulp_v] = ulp_u;
                rank[ulp_u]++;
            }
        }

        void unionbySize(int u , int v) {
            int ulp_u = findUparent(u);
            int ulp_v = findUparent(v);

            if(ulp_u == ulp_v) return;

            if(size[ulp_u] < size[ulp_v]) {
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            }

            else{
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }
        }
};
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);

Disjointset ds(7);

// ds.unionbyRank(1,2);
// ds.unionbyRank(2,3);
// ds.unionbyRank(4,5);
// ds.unionbyRank(6,7);
// ds.unionbyRank(5,6);
// //if 3 and 7 belong to same component
// if(ds.findUparent(3) == ds.findUparent(7)) cout<<"SAME"<<"\n";
// else cout<<"NOT SAME"<<"\n";

// ds.unionbyRank(3,7);

// if(ds.findUparent(3) == ds.findUparent(7)) cout<<"SAME"<<"\n";
// else cout<<"NOT SAME"<<"\n";

ds.unionbySize(1,2);
ds.unionbySize(2,3);
ds.unionbySize(4,5);
ds.unionbySize(6,7);
ds.unionbySize(5,6);
//if 3 and 7 belong to same component
if(ds.findUparent(3) == ds.findUparent(7)) cout<<"SAME"<<"\n";
else cout<<"NOT SAME"<<"\n";

ds.unionbySize(3,7);

if(ds.findUparent(3) == ds.findUparent(7)) cout<<"SAME"<<"\n";
else cout<<"NOT SAME"<<"\n";
return 0;
}