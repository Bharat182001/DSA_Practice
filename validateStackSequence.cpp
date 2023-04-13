// https://leetcode.com/problems/validate-stack-sequences/description/

// Approach: just use brute force afer using stack data structure

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i=0, j=0;
        int n=pushed.size();

        //Greedy Approach: TC: O(n), SC: O(n)
        stack<int> st;
        for(auto it: pushed) {
            st.push(it);

            while(!st.empty() && j<n && st.top()==popped[j]) {
                st.pop();
                j++;
            }
        }
    
        return j==n;
    }
};
