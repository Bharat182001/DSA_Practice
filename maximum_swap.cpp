// https://leetcode.com/problems/maximum-swap/description/

// Appraoch: convert num to string first, then start traversing from back and keep track of largetEle and largestIdx, also if current digit
// is smaller than largestEle, then update leftIdx to currentIdx and rightIdx to largestIdx, then when for loop ends, check if leftIdx is still -1,
// if so that means our num was in already in order, else just swap leftIdx and rightIdx elements, and then return stoi(string).

class Solution {
public:
    int maximumSwap(int num) {
        // TC:O(st.size()), SC:O(st.size())
        // single traversal from back - keep track of largest element yet and its index 
        string st = to_string(num);

        int maxDig=-1, maxIdx=-1;
        int rightIdx=-1, leftIdx=-1;
        for(int i=st.size()-1; i>=0; i--){
            // current digit contributes to largest element
            if(st[i] > maxDig){
                maxDig=st[i];
                maxIdx=i;
                continue;
            }

            // current digit is less than maximum element
            if(st[i] < maxDig){
                leftIdx=i;
                rightIdx=maxIdx;
            }   

        }
        // num is already in order
        if(leftIdx==-1) return num;

        swap(st[leftIdx], st[rightIdx]);
        return stoi(st);
    }
};
