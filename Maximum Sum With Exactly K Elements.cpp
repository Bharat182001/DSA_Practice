// https://leetcode.com/problems/maximum-sum-with-exactly-k-elements/description/

class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int maxi = *max_element(begin(nums), end(nums));
        
        int temp = maxi+(k-1);
        int temp2 = maxi-1;
        
        temp = ((temp)*(temp+1))/2;
        temp2 = (temp2 * (temp2+1))/2;
        
        return temp-temp2;
    }
};

