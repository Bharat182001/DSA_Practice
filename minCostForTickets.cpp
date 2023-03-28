// https://leetcode.com/problems/minimum-cost-for-tickets/description/

// Approach: ------------------ (Code was Copied)

class Solution {
public:
    // Copied Code:
    int solve(vector<int>& days, vector<int>& costs, int i, int n, vector<int> &dp){

        if(i>=n) return 0;

        if(dp[i]!=-1) return dp[i];

        int i1 = upper_bound(days.begin(), days.end(), days[i]+1-1) - days.begin();
        int i7 = upper_bound(days.begin(), days.end(), days[i]+7-1) - days.begin();
        int i30 = upper_bound(days.begin(), days.end(), days[i]+30-1) - days.begin();

        int c1 = costs[0] + solve(days, costs, i1, n, dp);
        int c7 = costs[1] + solve(days, costs, i7, n, dp);
        int c30 = costs[2] + solve(days, costs, i30, n, dp);

        return dp[i] = min(c1, min(c30, c7));
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        vector<int> dp(days.size()+1, -1);

        return solve(days, costs, 0, days.size(), dp);
    }
};

