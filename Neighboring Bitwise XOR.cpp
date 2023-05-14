// https://leetcode.com/problems/neighboring-bitwise-xor/description/

class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        // Logic: original array would be formed as 
        // derived = [a0, a1, a2, a3]
        // original would be = [0, a0, a0^a1, a0^a1^a2]
        // now original[3]^original[0] == derived[3], then return true 

        int n=derived.size();
        int xr=0;
        for(int i=0; i<n-1; i++) {
            xr ^= derived[i];
        }

        return (xr^0 == derived[n-1]);
    }
};
