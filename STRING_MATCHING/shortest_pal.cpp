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
int longestPrefixSuffix(string str)
{
        vector<int> A(str.size(), 0);
        int j = 0, i = 1;
      
        while(i < str.size())
        {
            if(str[i] == str[j])
            {
                // Increment j by 1 and assign the value to the prefix array
                A[i] = j+1;
                j++;
                i++;
            }
            else
            {
                if(j==0)
                    i++;
                else
                    // Set j to the previous value in the prefix array
                    j = A[j-1];
                 
            }
        }
 
        // Return the last element of the prefix array
        return A.back();
}
    string shortestPalindrome(string s) {
        // we need to find longest pal substring strting from index 0 = LPS os string s + rev(s)
        //the we will find string last lps len substr and after revesing the find string we will add to the fromt of original atring
        if(s.size() <= 1) return s; 
        string t = s;
        reverse(t.begin() , t.end());

        string str = s + '#' + t;
        //why adding '# bcz consider string "aaaa" so if we dont add "#" the longets lps will be 7 but we want 4
        int lps = longestPrefixSuffix(str);

        string temp = s.substr(lps);
        reverse(temp.begin() , temp.end());
        
        string ans = temp + s;
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