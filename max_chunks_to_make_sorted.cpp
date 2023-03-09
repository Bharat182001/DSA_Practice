// https://leetcode.com/problems/max-chunks-to-make-sorted/description/

// Nice Problem!
// Given: All elements are unique.
// Logic: we can make a new chunk at i if all elements 0 to i-1 are left to i and i+1....n-1 are right to i, i.e sum(0 to i) == sum(arr[0] to arr[i])

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        // Logic: we can make a new chunk at i if all elements 0 to i-1 are left to i and i+1....n-1 are right to i
        int n=arr.size();

        int chunks=0;
        int arrSum=0, actualSum=0;
        for(int i=0; i<n; i++){
            actualSum += i;
            arrSum += arr[i];

            if(actualSum == arrSum) chunks++;
        }
        
        return chunks;
    }
};
