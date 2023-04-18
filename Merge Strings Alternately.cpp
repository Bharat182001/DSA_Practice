// https://leetcode.com/problems/merge-strings-alternately/description/

// Approach: Using 2 pointers or 1 pointer only

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n=word1.length(), m=word2.length();
        int i=0;
        string ans="";
        while(i<max(n, m)) {
            if(i<n) ans += word1[i];
            if(i<m) ans += word2[i];
            i++;
        }

        return ans;
    }
};
