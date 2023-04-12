// https://leetcode.com/problems/simplify-path/

// Approach: Use stack and some logic for .. coming altogether

class Solution {
public:
    string simplifyPath(string path) {
        // logic: 
        int n=path.length();
        stack<string> st;

        int i=0, j=1;
        string temp="";
        while(j<n) {
            if(path[i]=='/'){
                while(j<n && path[j] != '/'){
                    temp += path[j];
                    j++;
                }
                if(temp==".."){
                    if(!st.empty()){
                        st.pop();
                    }
                }
                else if(temp!="" && temp!="."){
                    st.push(temp);
                }
            }
            temp="";
            i=j, j=i+1;
        }

        string ans="";
        if(st.empty()) {
            ans+='/';
            return ans;
        }

        while(!st.empty()) {
            string temp=st.top();
            ans = ('/'+temp+ans);
            st.pop();
        }

        return ans;
    }
};
