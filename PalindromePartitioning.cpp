// https://leetcode.com/problems/palindrome-partitioning/

// Approach: We have to go for each possible partition from a particular index, so from index idx, we iterate from len = 1 -> (n-idx), so as to try each possible substring

class Solution {
public:
    vector<vector<string>> ans;

    bool isPalindrome(string &st) {
        int i=0, j=st.length()-1;
        while(i<j) {
            if(st[i++]!=st[j--]) return false;
        }

        return true;
    }
    void solve(int idx, string &s, vector<string> &ds) {
        if(idx==s.length()) {
            ans.push_back(ds);
            return;
        }
        
        for(int len=1; len<=s.length()-idx; len++) {
            string temp = s.substr(idx, len);
            ds.push_back(temp);
            if(isPalindrome(temp)){
                solve(idx+len, s, ds);
            }
            ds.pop_back();
        }
    }
    vector<vector<string>> partition(string s) {
        // DONE MYSELF!
        // Logic: we have to go for each possible partition from a particular index, 
        // so from index idx, we iterate from len = 1 -> (n-idx), so as to try each possible substring
        int n=s.length();

        vector<string> ds;
        solve(0, s, ds);

        return ans;
    }
};
