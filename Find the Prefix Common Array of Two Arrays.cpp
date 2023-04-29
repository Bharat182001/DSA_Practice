// https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays/description/

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> ans;
        
        int n = A.size();
        unordered_set<int> st, st2;
        
        for(int i=0; i<n; i++) {
            st.insert(A[i]);
            st2.insert(B[i]);
            int count=0;
            for(int i=1; i<=n; i++) {
                if(st.count(i)==1 && st2.count(i)==1) {
                    count++;
                }
            }
            ans.push_back(count);
        }
        
        return ans;
    }
};
