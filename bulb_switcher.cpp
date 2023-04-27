// https://leetcode.com/problems/bulb-switcher/

class Solution {
public:
    bool isPerfectSq(int num) {
        return ( floor(sqrt(num))*floor(sqrt(num)) == num);
    }
    int bulbSwitch(int n) {
        if(n==0) return 0;

        int countPfSq=0;
        for(int i=1; i<=n; i++) {
            if(isPerfectSq(i)) countPfSq++;
        }

        return countPfSq;
    }
};
