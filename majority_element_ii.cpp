// https://leetcode.com/problems/majority-element-ii/

// Approach: Moore's Voting ALgo: A bit tough to grasp the logic!!

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // Moore's Voting Algorithm (extended)
        // Optimal: TC: O(n), SC: O(1)
        int n = nums.size();

        int num1=INT_MIN, num2=INT_MIN;
        int count1=0, count2=0;

        for(int i=0; i<n; i++){
            if(nums[i] == num1){
                count1++;
            }
            else if(nums[i] == num2){
                count2++;
            }
            else if(count1==0){
                num1 = nums[i];
                count1=1;
            }
            else if(count2==0){
                num2 = nums[i];
                count2=1;
            }
            else{
                count1--;
                count2--;
            }
        }

        // elegible candidates: num1 and num2;
        count1=0, count2=0;
        for(int i=0; i<n; i++){
            if(nums[i]==num1) count1++;
            if(nums[i]==num2) count2++;
        }
        
        vector<int> ans;
        if(count1>n/3) ans.push_back(num1);
        if(count2>n/3) ans.push_back(num2);
        return ans;
    }
};
