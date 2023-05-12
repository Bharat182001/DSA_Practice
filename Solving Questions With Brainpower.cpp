// https://leetcode.com/problems/solving-questions-with-brainpower/description/

// Approach: Use recursive approach to solve, then MEMO , then Tabulation (pick, notPick type problem)

// Recursive+MEMO
class Solution {
public:
    TC: O(n), SC: O(n)+StackSpace
    long long solve(long long idx, vector<vector<int>> &arr, vector<long long> &dp) {
        if(idx>=arr.size()) return 0;

        if(dp[idx] != -1) return dp[idx];

        //take
        long long take=0, notTake=0;
        long long newIdx=idx+(1LL)*arr[idx][1]+1*1LL;
        take = 1LL*arr[idx][0] + solve(newIdx, arr, dp);

        //notTake
        notTake=solve(idx+1*1LL, arr, dp);

        return dp[idx] = max(take, notTake);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
        vector<long long> dp(n+1, -1);
        return solve(0LL, questions, dp);
    }
};

// Tabulation
class Solution {
public:
    // TC: O(N), sc: O(n)
    long long mostPoints(vector<vector<int>>& questions) {
        // Tabulation
        int n=questions.size();
        vector<long long> dp(n+1, 0);

        dp[n-1] = questions[n-1][0];

        for(int idx=n-2; idx>=0; idx--) {
            //take
            long long take=0, notTake=0;
            long long newIdx=idx+(1LL)*questions[idx][1]+1*1LL;
            take = 1LL*questions[idx][0];
            if(newIdx < n) take += dp[newIdx];

            //notTake
            if(idx+1*1LL < n) notTake = dp[idx+1*1LL];

            dp[idx] = max(take, notTake);
        }

        return dp[0];
    }
};
