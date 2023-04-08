// https://leetcode.com/problems/permutation-sequence/description/

// Approach: use next_permutation of stl

class Solution {
public:
    string getPermutation(int n, int k) {
        string str="";
        for(int i=1; i<=n; i++){
            str += (i+'0');
        }

        while(k>1) {
            next_permutation(str.begin(), str.end());
            k--;
        }

        return str;
    }
};

// Approach 2: do by decreaing search set space given and placing the required index number to answer 

class Solution {
public:
    string getPermutation(int n, int k) {
        // TC: O(n*n), SC: O(n)
        k--; // keeping 0-based indexing

        vector<int> temp;
        int fact=1;
        for(int i=1; i<n; i++) { // run till n-1 so as to get fact value as n!/setSize
            fact *= i;
            temp.push_back(i);
        }
        temp.push_back(n);

        string res="";
        while(true) {
            res += (to_string(temp[k/fact]));
            temp.erase(temp.begin() + (k/fact));

            if(temp.size()==0) break;

            k = k%fact;
            fact = fact/temp.size();
        }

        return res;
    }
};
