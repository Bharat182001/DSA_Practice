// https://leetcode.com/problems/sort-array-by-parity/description/

// Approach: take 2 pointers i at 0 and j at n-1 , as we need to put even at start and odd at end, so 
//           take actions according to i and j, even or odd cases.

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        // 2 Pointer approach, TC: O(n), SC: O(1)
        int n=nums.size();
        vector<int> temp = nums;

        int i=0, j=n-1;
        while(i<j){
            if(temp[i]&1){ // nums[i] is odd
                if(temp[j]&1){ // nums[j] is odd
                    j--;
                }
                else{
                    swap(temp[i++], temp[j--]);
                }
            }
            else{ // nums[i] is even
                if(temp[j]&1){
                    i++, j--;
                }
                else{
                    i++;
                }
            }
        }

        return temp;
    }
};
