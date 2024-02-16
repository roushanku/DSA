// J.S.R -- *roush*
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> pbds; //find_by_order //order_of_key


// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
public:
    map <Node* , Node*> mp;

    void dfs(Node* node , Node* clone_node) {
        //iterate in all neighbour
        for(auto it : node -> neighbors) {
            //checking in map
            if(mp.find(it) == mp.end()) {
                Node* clone = new Node(it -> val);
                mp[it] = clone;
                clone_node -> neighbors.push_back(clone);
                dfs(it , clone);
            }

            else{
                clone_node -> neighbors.push_back(mp[it]);
            }
        }

        
    }

    //thought is clear -> go to neighbour of everynode cjeck if it already created or not
    //if createrd -> just push in vector
    //else create new node and start dfs fromt this node also(keep created node in map so dont create it 
    //again in future).


    Node* cloneGraph(Node* node) {
        if(node == NULL) return node;

        mp.clear();

        //first create the first node
        Node* clone_node = new Node(node -> val);
        mp[node] = clone_node;

        //start dfs
        dfs(node , clone_node);

        return clone_node;
    }
};
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
//patience Bro , thoda sa logic soch k try ur own test case
//hadbad m kaafi gadbad kie ho islie aaram s -> You will do best for Youself
//First, solve the problem. Then, write the code.
int t;
cin>>t;
while(t--){
           
}
return 0;
}