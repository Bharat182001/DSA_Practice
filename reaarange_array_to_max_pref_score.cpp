// https://leetcode.com/problems/rearrange-array-to-maximize-prefix-score/description/

// Approach: Just sorting based

class Solution {
public:
    int maxScore(vector<int>& nums) {
        int n=nums.size();
        
        vector<long long> temp;
        for(auto it: nums){
            temp.push_back((long long)it);
        }
        sort(temp.begin(), temp.end(), greater<long long>());
        
        for(int i=1; i<n; i++){
            temp[i] += temp[i-1];
        }
        
        int count=0;
        for(int i=0; i<n; i++){
            if(temp[i]>0) count++;
        }
        
        return count;
    }
};
