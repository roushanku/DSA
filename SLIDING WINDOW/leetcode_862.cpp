#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define PI 3.1415926535897932384626433832795l 
const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;
//j.S.R -> Roush
// -------------------------<Reminder -> YOU ARE A CHAMP>------------------------- 
//Question achhe se pad -> Thoda sa apna test soch lo yr
//jayada hadbad na kro -> question solve ho jae to code liho
//तू स्वयं तेज भयकारी है, क्या कर सकती चिनगारी है?
// -------------------------<Everything will be good>------------------------- 
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        //for leetcode 209 -> when neg ele is not prresent when apply simply sliding window
        //our main to maintain monotonic cumulative sum and when curr sum >= k remove from the back
        //so here we are using deque bcz it allow inertiona and deletion from front and back
        deque <pair<long long , long long>> dq;

        long long sum = 0;
        int ans = 1e9;
        int j = 0;
        int n = nums.size();
        //dq.push_back()
        while(j < n) {
            sum += nums[j];

            //take subarr from 0...j
            if(sum >= k) ans = min(ans , j+1);
            int i = 1e9;
            while(!dq.empty() && sum-dq.front().second >= k) {
                i = dq.front().first;
                dq.pop_front();
            }
           
           //here window size will be j-i only dry run for clearity
            if(i != 1e9) ans = min(ans, j-i);
            while(!dq.empty() && sum <= dq.back().second) dq.pop_back();
            dq.push_back({j,sum});
            j++;
        }

        if(ans == 1e9) return -1;
        else return ans;
    }
};
int main() {
ios_base::sync_with_stdio(0);
cin.tie(0); cout.tie(0);
int tc = 1;
cin >> tc;
for (int t = 1; t <= tc; t++) {

}
}