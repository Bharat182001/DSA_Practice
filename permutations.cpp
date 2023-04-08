// https://leetcode.com/problems/permutations/description/

// Approach: Use BackTracking and swapping logic of indexes.

class Solution {
public:
    vector<vector<int>> ans;

    void solve(int idx, vector<int> &arr) {
        if(idx==arr.size()){
            ans.push_back(arr); // O(n) time complexity of this operation
        }

        for(int var=idx; var<arr.size(); var++) {
            swap(arr[var], arr[idx]);
            solve(idx+1, arr); // think why we did call for idx+1
            swap(arr[var], arr[idx]); // backtrack
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        // swap wala logic:

        solve(0, nums);

        return ans;
    }
};
