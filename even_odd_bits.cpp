// https://leetcode.com/problems/number-of-even-and-odd-bits/

class Solution {
public:
    vector<int> evenOddBit(int n) {
        int temp = n;
        bool flag=false;
        int even=0, odd=0;
        while(temp!=0){
            int res = temp&1;
            if(res==1 && flag==false){
                even++;
            }
            else if(res==1 && flag==true){
                odd++;
            }
            
            if(flag==false){
                flag=true;
                temp = temp >> 1;
            }
            else{
                flag=false;
                temp = temp >> 1;
            }
        }
        
        return {even, odd};
    }
};
