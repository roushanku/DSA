// J.S.R -- *roush*
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> pbds; //find_by_order //order_of_key

class Solution {
public:
    struct trieNode {
        int idx;
        trieNode* child[26];
    };

    trieNode* getNode(int j) {
        trieNode* temp = new trieNode();
        temp -> idx = j;

        for(int i = 0 ; i < 26 ; i++) {
            temp -> child[i] = NULL;
        }

        return temp;
    }

    void insertTrie(trieNode* root , int i , vector<string>& wordsContainer) {
        string word = wordsContainer[i];
        int n = word.size();

        for(int j = n-1 ; j >= 0 ; j--) {
            int id = word[j] - 'a';

            if(root -> child[id] == NULL) {
                root -> child[id] = getNode(i);
            }

            root = root -> child[id];

            if(wordsContainer[root -> idx].size() > n) {
                root -> idx = i;
            }
        }
    }

    int searchTrie(trieNode* root , string word) {
        int n = word.size();
        int id = root -> idx;

        for(int i = n-1 ; i >= 0 ; i--) {
            int j = word[i] - 'a';
            root = root -> child[j];

            if(root == NULL) {
                return id;
            }

            id = root -> idx;
        }

        return id;
    }
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        int m = wordsContainer.size();
        int n = wordsQuery.size();

        vector <int> ans(n);
        trieNode* root = getNode(0);

        for(int i = 0 ; i < m ; i++) {
            int id = root -> idx;
            if(wordsContainer[id].size() > wordsContainer[i].size()) {
                root -> idx = i;
            }

            insertTrie(root , i , wordsContainer);
        }

        for(int i = 0 ; i < n ; i++) {
            ans[i] = searchTrie(root , wordsQuery[i]);
        }

        return ans;
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