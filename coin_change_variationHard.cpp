// Maximum Value of K Coins From Piles

class Solution {
public:
    int solve(int i, vector<vector<int>> &p, int k, vector<vector<int>> &dp) {
        if(i>=p.size() || k<=0) return 0;

        if(dp[i][k] != -1) return dp[i][k];

        int notTaken = solve(i+1, p, k, dp); // skipping that pile and finding answer from other piles

        int cur=0, maxOfTaken=0;
        for(int idx=0; idx<p[i].size() && idx<k; idx++) { // that means usi pile me se ek ek krke lo
            cur += p[i][idx];   
            int temp = solve(i+1, p, k-idx-1, dp); // baaki piles me se after taking one from that pile 
            int coins = cur+temp;
            maxOfTaken = max(maxOfTaken, coins);
        }

        return dp[i][k] = max(notTaken, maxOfTaken);
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n=piles.size();
        vector<vector<int>> dp(n, vector<int> (k+1, -1));
        return solve(0, piles, k, dp);
    }
};
