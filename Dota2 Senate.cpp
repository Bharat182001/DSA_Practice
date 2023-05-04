// https://leetcode.com/problems/dota2-senate/description/

// Approach: Used Brute force (use examples like "DDRRR" and "DRRDRDRDRDDRDRDR" to understand problem properly)

class Solution {
public:
    string predictPartyVictory(string senate) {
        int n=senate.size();

        int i=0;
        while(1) {
            if(i==n) i=0;
            if(senate[i]=='R') {
                for(int j=i+1; ; j++) {
                    if(j==n) j=0;
                    if(i==j) return "Radiant";
                    if(senate[j]=='D') {
                        senate[j]='B';
                        break;
                    }
                }
            }
            else if(senate[i]=='D'){
                for(int j=i+1; ; j++) {
                    if(j==n) j=0;
                    if(j==i) return "Dire";
                    if(senate[j]=='R') {
                        senate[j]='B';
                        break;
                    }
                }
            }
            i++;
        }

        return "None";
    }
};
