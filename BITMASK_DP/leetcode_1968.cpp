#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define PI 3.1415926535897932384626433832795l
const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;
// j.S.R -> Roush
//  -------------------------<Reminder -> YOU ARE A CHAMP>-------------------------
// Question achhe se pad -> Thoda sa apna test soch lo yr
// jayada hadbad na kro -> question solve ho jae to code liho
// तू स्वयं तेज भयकारी है, क्या कर सकती चिनगारी है?
//  -------------------------<Everything will be good>-------------------------

// https://leetcode.com/problems/minimum-number-of-work-sessions-to-finish-the-tasks/
class Solution
{
public:
    int dp[16][1 << 14];
    int solve(int mask, int timeSum, vector<int> &tasks, int sessionTime)
    {
        int n = tasks.size();
        if (mask == (1 << n) - 1)
            return 0;

        if (dp[timeSum][mask] != -1)
            return dp[timeSum][mask];

        int ans = 1e9;

        for (int i = 0; i < n; i++)
        {
            if ((mask & (1 << i)) == 0)
            {
                if (timeSum + tasks[i] <= sessionTime)
                {
                    ans = min(ans, solve((mask | (1 << i)), timeSum + tasks[i], tasks, sessionTime));
                }
                else
                    ans = min(ans, 1 + solve((mask | (1 << i)), tasks[i], tasks, sessionTime));
            }
        }

        return dp[timeSum][mask] = ans;
    }
    int minSessions(vector<int> &tasks, int sessionTime)
    {
        memset(dp, -1, sizeof(dp));
        int ans = solve(0, 0, tasks, sessionTime);
        return ans + 1;
    }
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}