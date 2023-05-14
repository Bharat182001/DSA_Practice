// https://leetcode.com/problems/number-of-senior-citizens/description/

class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count=0;
        for(auto it: details) {
            string s="";
            s+=it[11];
            s+=it[12];
            int age=stoi(s);
            if(age>60) count++;
        }
        
        return count;
    }
};
