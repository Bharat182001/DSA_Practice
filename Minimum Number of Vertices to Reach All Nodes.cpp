// https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/description/

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        // take those whose indegree are zero, so as to reach them also and we eventually would visit others from them

        // TC: O(n), SC: O(n)
        vector<int> indg(n, 0);
        for(auto &it: edges) {
            int u=it[0], v=it[1];
            indg[v]++;
        }

        vector<int> ans;
        for(int i=0; i<n; i++) {
            if(indg[i]==0) ans.push_back(i);
        }
        
        return ans;
    }
};
