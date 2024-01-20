// https://www.youtube.com/watch?v=HRQB7-D2bi0
// J.S.R -- *roush*

//This will not work for duplicat ele in arr -> [3,1,4,1] -> o/p = 17 but it should be 15
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> pbds; //find_by_order //order_of_key
    const int mod = 1e9 + 7;
    vector <int> NSE(vector <int> &nums) {
        int n = nums.size();
        stack <int> st;
        vector <int> ans;

        for(int i = n-1 ; i >= 0 ; i--) {
            if(st.empty()) ans.push_back(n);

            else if(!st.empty() && nums[st.top()] <= nums[i]) {
                ans.push_back(st.top());
            }

            else if(!st.empty() && nums[st.top()] > nums[i]) {
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

int n;
cin>>n;

vector <int> arr(n);
for(int i=0;i<n;i++) cin>>arr[i];

vector <int> vns = NSE(arr);
vector <int> vps = PSE(arr);

//Calculate the final sum
long long ans = 0;
for(int i = 0 ; i < n ; i++) {
    long long l = i - vps[i];
    long long r = vns[i] - i;

    long long totalWays = (l * r);

    ans += (1LL * totalWays * arr[i]);
    ans %= mod;
}

cout<<ans<<"\n";
return 0;
}