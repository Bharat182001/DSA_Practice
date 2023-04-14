// https://leetcode.com/problems/longest-palindromic-subsequence/

// Approach: Use LCS Approach on given string and reverse of given string (DP)

class Solution {
public:
    int lcs(string &orig, string &rev, int len) {
        vector<vector<int>> dp(len+1, vector<int> (len+1, 0));

        for(int i=1; i<=len; i++) {
            for(int j=1; j<=len; j++) {
                if(orig[i-1] == rev[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }

        return dp[len][len];
    }
    int longestPalindromeSubseq(string s) {
        string orig = s;
        reverse(begin(s), end(s));
        string rev = s;

        return lcs(orig, rev, s.length());
    }
}; 
