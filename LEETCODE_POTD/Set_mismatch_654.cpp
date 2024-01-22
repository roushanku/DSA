// J.S.R -- *roush*
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> pbds; //find_by_order //order_of_key
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
//patience Bro , thoda sa logic soch k try ur own test case
//hadbad m kaafi gadbad kie ho islie aaram s -> You will do best for Youself
//First, solve the problem. Then, write the code.

vector <int> arr = {1,2,2,4};

// method 1 : T.C = O(n*log(n)) , s.c = (1)
// sort(nums.begin() , nums.end());

// int dup;

// int sum = 0;
// for(int i = 0 ; i < nums.size() ; i++) sum += nums[i];

// int n = nums.size();


// for(int i = 1 ; i < n ; i++) {
//     if(nums[i] == nums[i-1]) {
//         dup = nums[i];
//         break;
//     }
// }
// // cout<<dup<<"\n";
// int expected = (n * (n+1)) / 2;
// int diff = abs(expected - sum);

// if(expected > sum) {
    
//     return {dup , dup + diff};
// }   

// else return {dup , dup - diff};

// method 2 : T.C = O(n) , s.c = O(1)

// int dup;
// for (int i = 0; i < arr.size(); i++) {
//         if (arr[abs(arr[i]) - 1] > 0) arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];

//         else {
//             dup = abs(arr[i]);
//         }
            
//     }
 
// int missing;
// for (int i = 0; i < arr.size(); i++) {
//     if (arr[i] > 0) missing = i+1;
// }

// return {dup , missing};
return 0;
}