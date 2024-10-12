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
    int minGroups(vector<vector<int>>& intervals) {
        // think of this as a train arrival and departure problem where we need to find min no of 
        //platforms required for all trains to arrive and depart.

        // now the first train comes and we put this on a platform 1 -> heap[5]
        // the second train comes and checks whether is there any train which leaves before I 
        // come(this is the main reason for keeping min heap) for this we see the top of the heap and if the top < this trains arrival time then no need for new platform else we will need a new one.
        sort(intervals.begin() , intervals.end());

        priority_queue <int, vector<int> , greater<int>> pq;
        for(auto it : intervals) {
            if(!pq.empty() && pq.top() < it[0]) pq.pop();
            pq.push(it[1]);
        }

        return pq.size();
    }
};
void solve() {
// Add your solution here
}
int main() {
ios_base::sync_with_stdio(0);
cin.tie(0); cout.tie(0);
int tc = 1;
cin >> tc;
for (int t = 1; t <= tc; t++) {
solve();
// cout<<"$"<<endl;
}
}