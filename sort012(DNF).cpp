// https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

// Approach: use DNF ALgo , TC: O(n), SC: O(1)

class Solution {
public:
    void sort012(int a[], int n)
    {
        // DNF ALgo: TC: O(n), SC: O(1)
        // logic: lo=0, mid=0, hi=arr.size()-1
        // loop until mid<hi
        // then if mid==0 swap(arr[lo++], arr[mid++])
        // if mid==1 mid++, if mid==2 swap(arr[mid], arr[hi]) and hi--
        
        int lo=0, mid=0, hi=n-1;
        
        while(mid <= hi){
            if(a[mid] == 0){
                swap(a[lo++], a[mid++]);
            } else if(a[mid] == 1){
                mid++;
            } else if(a[mid] == 2){
                swap(a[mid], a[hi--]);
            }
        }
        return;
    }
};

