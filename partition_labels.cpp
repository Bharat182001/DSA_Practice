// https://leetcode.com/problems/partition-labels/description/

// Approach:  create a map of storing indexes of last occurence of each character:
           // then start traversing the string and create 2 pointers (first will be for traversing and second for marking
           // the last occurence, if(firstPtr == secondPtr)-> push_back in answer vector(firstPtr+1), then
           // again start traversing from there onwards).

class Solution {
public:
    vector<int> partitionLabels(string s) {
        // TC: O(n), SC: O(256) => O(1)
        unordered_map<char, int> mp;
        int n=s.length();
        for(int i=n-1; i>=0; i--){
            if(mp.find(s[i]) == mp.end()){
                mp[s[i]] = i;
            }
        }

        vector<int> ans;
        int maxLen=mp[s[0]];
        for(int i=0; i<n-1; i++){
            if(i == maxLen){
                ans.push_back(i+1);
                maxLen = mp[s[i+1]];
            }
            else{
                maxLen = max(maxLen, mp[s[i]]);
            }
        }

        ans.push_back(maxLen+1);

        for(int i=ans.size()-1; i>0; i--) ans[i] -= ans[i-1];

        return ans;
    }
};
