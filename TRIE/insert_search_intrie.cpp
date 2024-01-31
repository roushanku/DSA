// J.S.R -- *roush*
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> pbds; //find_by_order //order_of_key

struct TrieNode {
    bool word_end;
    TrieNode* child[26];
};

TrieNode* getNode() {
    TrieNode* node = new TrieNode();
    node -> word_end = false;
    for(int i = 0 ; i < 26 ; i++) node -> child[i] = NULL;

    return node;
}

void insert_into_trie(TrieNode* root , string key) {
    TrieNode* node = root;
    for(int i = 0 ; i < key.size() ; i++) {
        if(!node -> child[key[i] - 'a']) node -> child[key[i] - 'a'] = getNode();
        node = node -> child[key[i] - 'a'];
    }
    node -> word_end = true;
}

bool search_into_trie(TrieNode* root, string key) {
    TrieNode* pcrawl = root;
    for(char ch:key) {
        int idx = ch-'a';
        if(pcrawl->child[idx] == NULL)
            return false;
        pcrawl = pcrawl->child[idx];
    }
    
    return (pcrawl != NULL && pcrawl->word_end == true);
}

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
//patience Bro , thoda sa logic soch k try ur own test case
//hadbad m kaafi gadbad kie ho islie aaram s -> You will do best for Youself
//First, solve the problem. Then, write the code.
int t;
cin>>t;
while(t--){
    int n;
    cin>>n;

    
    TrieNode* root = getNode();
    string s;
    
    for(int i = 0 ; i < n ; i++) {
        cin>>s;
        insert_into_trie(root , s);
    }

    string str;
    cin>>str;

    if(search_into_trie(root , str)) cout<<"Found"<<"\n";
    else cout<<"Not Found"<<"'\n";
    
}
return 0;
}