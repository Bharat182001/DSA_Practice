// https://leetcode.com/problems/sum-in-a-matrix/description/

class Solution {
public:
    static bool cmp(int a, int b) {
        return a>b;
    }
    int matrixSum(vector<vector<int>>& nums) {
        int n=nums.size(), m=nums[0].size();
        for(int i=0; i<n; i++) {
            vector<int> it=nums[i];
            sort(it.begin(), it.end(), cmp);
            nums[i]=it;
        }
        
        int score=0;
        for(int j=0; j<nums[0].size(); j++) {
            int maxi=INT_MIN;
            for(int i=0; i<nums.size(); i++) {
                maxi = max(maxi, nums[i][j]);
            }
            score += maxi;
        }
        
        return score;
    }
};
