// J.S.R -- *roush*
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> pbds; //find_by_order //order_of_key

class Solution
{
    public:
        // Function to compute the LPS (Longest Proper Prefix which is also Suffix) array
        void computeLPS(string pattern, vector<int>& lps) {
            int M = pattern.length();
            int len = 0; // Length of the previous longest prefix & suffix
        
            lps[0] = 0; // Because there is no proper suffix and prefix of pattern[0..0]
        
            int i = 1;
            while (i < M) {
                if (pattern[i] == pattern[len]) {
                    len++;
                    lps[i] = len;
                    i++;
                } 
                else {
                    if (len != 0) {
                        len = lps[len - 1]; //You can also write, len = len-1;
                    } 
                    else {
                        lps[i] = 0;
                        i++;
                    }
                }
            }
        }
        
        vector <int> search(string pat, string txt) {
            int N = txt.length();
            int M = pat.length();
            vector<int> result;
            
            // Create an LPS array to store the longest proper prefix which is also a suffix
            //lps[i] = the longest proper prefix of pat[0..i] which is also a suffix of pat[0..i]. 
            vector<int> lps(M, 0);
            computeLPS(pat, lps);
        
            int i = 0; // Index for text
            int j = 0; // Index for pattern
        
            while (i < N) {
                if (pat[j] == txt[i]) {
                    i++;
                    j++;
                }
        
                if (j == M) {
                    result.push_back(i-j+1); //Pattern found at index i-j+1 (If you have to return 1 Based indexing, that's why added + 1)
                    j = lps[j - 1];
                } 
                else if (i < N && pat[j] != txt[i]) {
                    if (j != 0) {
                        j = lps[j - 1];
                    } 
                    else {
                        i++;
                    }
                }
            }
            
            return result; //will give all the index from where a substr start equal to pat
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