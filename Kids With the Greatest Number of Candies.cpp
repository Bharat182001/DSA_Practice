// https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/

// Asked by AMAZON: Use simple greedy approach

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> ans;
        int n=candies.size();
        int maxi = *max_element(begin(candies), end(candies));

        for(auto it: candies) {
            if(it+extraCandies >= maxi) ans.push_back(true);
            else ans.push_back(false);
        }

        return ans;
    }
};
