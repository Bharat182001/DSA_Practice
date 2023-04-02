// https://leetcode.com/problems/successful-pairs-of-spells-and-potions/description/

// Approach: sort the potions and then find least strength that will pair with current spell strength, then aage ke saare bna lenge pair
// TC: O(nlogm), SC: O(1)

class Solution {
public:
    int bs(int curSpellStr, vector<int> &arr, long long suc, int m) {
        int ansIdx = m;
        int lo=0, hi=m-1;

        while(lo<=hi) {
            int mid = lo + (hi-lo)/2;
            if(1LL * arr[mid] * curSpellStr >= suc) {
                ansIdx = min(ansIdx, mid);
                hi = mid-1;
            }
            else{
                lo = mid+1;
            }
        }

        return ansIdx;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();

        sort(potions.begin(), potions.end());

        vector<int> ans;
        for(int i=0; i<n; i++){
            int reqIdx = bs(spells[i], potions, success, m);
            
            ans.push_back(m-reqIdx);
        }

        return ans;
    }
};
