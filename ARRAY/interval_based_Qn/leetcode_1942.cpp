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
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        priority_queue <pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;

        int dest = times[targetFriend][0];
        int ct = 0;
        priority_queue <int , vector<int> , greater<int>> free;
        int n = times.size();

        sort(times.begin() , times.end());

        for(int i = 0 ; i < n ; i++) {
            int arrival = times[i][0] , dep = times[i][1];

            while(!pq.empty() && pq.top().first <= arrival) {
                free.push(pq.top().second);
                pq.pop();
            }

            if(!free.empty()) {
                int no = free.top();
                free.pop();
                if(arrival == dest) return no;

                pq.push({dep , no});
            }

            else {
                pq.push({dep , ct});
                if(arrival == dest) return ct;
                ct++;
            }
        }

        return -1;
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