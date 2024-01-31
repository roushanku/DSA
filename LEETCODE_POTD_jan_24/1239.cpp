// J.S.R -- *roush*
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> pbds; //find_by_order //order_of_key

// map <pair<int , string> , int> mp;
// bool NoDup(string s , string str) {
//     vector <int> f(26 , 0);

//     for(int i = 0 ; i < str.size() ; i++) f[str[i] - 'a']++;

//     for(int i = 0 ; i < s.size() ; i++) {
//         if(f[s[i]-'a'] > 0) return false;
//         else f[s[i] - 'a']++;
//     }

//     return true;
// }

// int solve(int level , vector <string> &arr , string temp) {
//     int n = arr.size();

//     if(level >= n) return temp.size();

//     int ans = 0;

//     if(mp.find({level ,temp}) != mp.end()) return mp[{level , temp}];

//     if(NoDup(arr[level] , temp)) {
//         ans = max(ans , solve(level+1 , arr , temp + arr[level]));
//     }

//     ans = max(ans , solve(level+1 , arr , temp));

//     return mp[{level , temp}] = ans;
// }



    bool NoDup(string &s , int &num) {
        sort(s.begin() , s.end());

        for(int i = 1 ; i < s.size() ; i++) {
            if(s[i] == s[i-1]) return false;
        }

        for(int i = 0 ; i < s.size() ; i++) {
            int j = s[i] - 'a';
            if((num & (1<<j))) return false;
        }

        return true;
    }
    int solve(int level , vector <string> &arr , int num) {
        int n = arr.size();

        if(level >= n) return 0;

        int ans = 0;

        string s = arr[level];
        int m = s.size();

        int temp = num;

        //note : here either call the not take function, or have to use the backtraking.....
        //bcz this function dont change anything but on taking we r setting the bit so when we return we have to unset the bit
        ans = max(ans , solve(level+1 , arr , num));

        if(NoDup(arr[level] , num)) {
    
            for(int i = 0 ; i < m ; i++) {
                int j = s[i] - 'a';
                num |= (1<<j);
            }
            
            ans = max(ans , m + solve(level+1 , arr , num));

            //if not take is written below then use this
            // Reset num to its original value for backtracking
            // for (int i = 0; i < m; i++) {
            //     int j = s[i] - 'a';
            //     num &= ~(1 << j);
            // }
        }

        return ans;
    }
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
//patience Bro , thoda sa logic soch k try ur own test case
//hadbad m kaafi gadbad kie ho islie aaram s -> You will do best for Youself
//First, solve the problem. Then, write the code.

    vector <string> arr = {"un","iq","ue"};

    //method 1
    // string temp = "";
    // int ans = solve(0 , arr , temp);
    // cout<<ans<<"\n";

    // method 2 using bitmask
    int ans = solve(0 , arr , 0);
    cout<<ans<<"\n";
return 0;
}