// https://leetcode.com/problems/can-place-flowers/

// Approach: Use Greedy approach and make cases using pen and paper if element is 1 or 0 and handle corresponding cases likewise.

Brute: 
class Solution {
public:
    bool isValid(vector<int> &arr){
        for(int i=1; i<arr.size(); i++){
            if(arr[i]==0) continue;
            else if(arr[i]==1 && arr[i-1]==1) return false;
        }
        return true;
    }

    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int siz=flowerbed.size();
        if(isValid(flowerbed)){
            int ans=0;
            for(int i=0; i<siz; ){
                if(flowerbed[i] == 1){
                    i += 2;
                }
                else{
                    if(i+1<siz){
                        if(i>0 && flowerbed[i+1] != 1 && flowerbed[i-1] != 1){
                            ans++;
                            i += 2;
                        }
                        else if(i==0 && flowerbed[i+1] != 1){
                            ans++;
                            i += 2;
                        }
                        else{
                            i += 3;
                        }
                    }
                    else if(i+1 == siz){
                        if(i>0 && flowerbed[i-1] != 1){
                            ans++;
                            i += 2;
                        }
                        else if(i==0){
                            if(flowerbed[i]==0 && n<=1) return true;
                            else return false; 
                        }
                    }
                }
            }

            if(ans >= n) return true;
            else return false;
        }
        return false;
    }
};
  

Optimised : Very GOOD APPROACH!
  
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        // very optimised approach:

        int siz=flowerbed.size();

        int plants=0;
        for(int i=0; i<siz; i++){
            int prev = (i != 0) ? flowerbed[i-1] : 0;
            int next = (i+1 != siz) ? flowerbed[i+1] : 0;

            if(prev == 0 && flowerbed[i] == 0 && next == 0){
                ++plants;
                i++;
            }
        }

        return (plants >= n);
    }
};
