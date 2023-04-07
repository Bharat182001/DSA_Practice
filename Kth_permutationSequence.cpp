// https://leetcode.com/problems/permutation-sequence/description/

// Approach: use next_permutation of stl

class Solution {
public:
    string getPermutation(int n, int k) {
        string str="";
        for(int i=1; i<=n; i++){
            str += (i+'0');
        }

        while(k>1) {
            next_permutation(str.begin(), str.end());
            k--;
        }

        return str;
    }
};
