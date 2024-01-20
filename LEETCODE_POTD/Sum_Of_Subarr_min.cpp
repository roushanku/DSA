// J.S.R -- *roush*
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> pbds; //find_by_order //order_of_key

    vector <int> NSE(vector <int> &nums) {
        int n = nums.size();
        stack <int> st;
        vector <int> ans;

        for(int i = n-1 ; i >= 0 ; i--) {
            if(st.empty()) ans.push_back(n);

            else if(!st.empty() && nums[st.top()] <= nums[i]) {
                ans.push_back(st.top());
            }

            else if(!st.empty() && nums[st.top()] > nums[i]) { // yha pr equal to nhi lgaya bcz NGE m lgya ah
                while(!st.empty() && nums[st.top()] > nums[i]) {
                    st.pop();
                }

                if(st.empty()) ans.push_back(n);

                else if(!st.empty() && nums[st.top()] <= nums[i]) {
                    ans.push_back(st.top());
                }
            }
            st.push(i);
        }

        reverse(ans.begin() , ans.end());
        return ans;
    }

    vector <int> PSE(vector <int> &nums) {
        int n = nums.size();
        vector <int> ans;
        stack <int> st;

        for(int i = 0 ; i < n ; i++) {
            if(st.empty()) ans.push_back(-1);

            else if(!st.empty() && nums[st.top()] < nums[i]) {
                ans.push_back(st.top());
            }

            else if(!st.empty() && nums[st.top()] >= nums[i]) { //equal to lgaya to avoid dupicate claculation -> you can in next smaller ot prev smaller in any one case
                while(!st.empty() && nums[st.top()] >= nums[i]) {
                    st.pop();
                }

                if(st.empty()) ans.push_back(-1);

                else if(!st.empty() && nums[st.top()] < nums[i]) {
                    ans.push_back(st.top());
                }
            }
            st.push(i);
        }

        return ans;
    }
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
//patience Bro , thoda sa logic soch k try ur own test case
//hadbad m kaafi gadbad kie ho islie aaram s -> You will do best for Youself
//First, solve the problem. Then, write the code.

vector <int> arr = {1,2,3,4,5};

vector <int> vns = NSE(arr);
vector <int> vps = PSE(arr);

long long ans = 0;
int n = arr.size();
int mod = 1e9 + 7;

for(int i = 0 ; i < n ; i++) {
    long long l = i - vps[i];
    long long r = vns[i] - i;

    long long totalWays = (l * r);

    ans += (1LL * totalWays * arr[i]);
    ans %= mod;
}

cout<< ans <<"\n";


return 0;
}
