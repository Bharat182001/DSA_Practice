// https://practice.geeksforgeeks.org/problems/61567fb59e9f202db5cc2ad320ffeb6d95bf72d7/1

// Approach: Use simple pointers for do required stuff

// TC: O(N), SC: O(1)

class Solution{
    public:
    bool wifiRange(int N, string S, int X){
        // code here
        for(int i=0; i<N; i++) {
            if(S[i]=='1') {
                int temp=X, j=i-1;
                while(j>=0 && temp--) {
                    if(S[j]=='0') S[j--]='p';
                }
                temp=X, j=i+1;
                while(temp-- && j<N) {
                    if(S[j]=='0') S[j++]='p';
                }
            }
        }
        
        for(int i=0; i<N; i++) {
            if(S[i]=='0') return false;
        }
        return true;
    }
};
  
