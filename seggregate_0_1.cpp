// https://practice.geeksforgeeks.org/problems/segregate-0s-and-1s5106/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

// Approach: Use 2 pointer approach

class Solution{   
public:
    void segregate0and1(int arr[], int n) {
        // 2 pointer approach: TC: O(n), SC: O(1)
        int lo=0, hi=n-1;
        
        while(lo<hi){
            if(arr[lo]==0 && arr[hi]==1){
                lo++, hi--;
            }
            else if(arr[lo]==0){
                lo++;
            }
            else if(arr[hi]==1){
                hi--;
            }
            else if(arr[lo]==1 && arr[hi]==0){
                swap(arr[lo], arr[hi]);
                lo++, hi--;
            }
        }
        return;
    }
};
