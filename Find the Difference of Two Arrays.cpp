// https://leetcode.com/problems/find-the-difference-of-two-arrays/description/

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st1, st2;
        for(auto it: nums1) st1.insert(it);
        for(auto it: nums2) st2.insert(it);

        vector<vector<int>> ans;
        vector<int> temp1, temp2;

        for(int i=0; i<nums1.size(); i++) {
            if(st2.count(nums1[i]) == 0) {
                temp1.push_back(nums1[i]);
                st2.insert(nums1[i]);
            }
        }
        for(int i=0; i<nums2.size(); i++) {
            if(st1.count(nums2[i]) == 0) {
                temp2.push_back(nums2[i]);
                st1.insert(nums2[i]);
            }
        }

        ans.push_back(temp1);
        ans.push_back(temp2);
        return ans;
    }
};

// Editorial Wala: TC: O(n+m), SC: O(max(m, n))
class Solution {
public:
    // Returns the elements in the first arg nums1 that don't exist in the second arg nums2.
    vector<int> getElementsOnlyInFirstList(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> onlyInNums1;
        
        // Store nums2 elements in an unordered set. 
        unordered_set<int> existsInNums2;
        for (int num : nums2) {
            existsInNums2.insert(num);
        }
        
        // Iterate over each element in the list nums1.
        for (int num : nums1) {
            if (existsInNums2.find(num) == existsInNums2.end()) {
                onlyInNums1.insert(num);
            }
        }
        
        // Convert to vector.
        return vector<int> (onlyInNums1.begin(), onlyInNums1.end());
    }
    
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        return {getElementsOnlyInFirstList(nums1, nums2), getElementsOnlyInFirstList(nums2, nums1)};
    }
};
