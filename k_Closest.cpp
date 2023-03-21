// https://leetcode.com/problems/find-k-closest-elements/

// Approach: 
// 1: Simple: using maxHeap and sorting the final answer : TC: O(n), SC: O(1)

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n=arr.size();
        priority_queue<pair<int,int>> maxHp;

        for(int i=0; i<n; i++){
            maxHp.push({abs(x-arr[i]), arr[i]});

            if(maxHp.size()>k){
                maxHp.pop();
            }
        }

        vector<int> ans;
        while(!maxHp.empty()){
            ans.push_back(maxHp.top().second);
            maxHp.pop();
        }

        sort(begin(ans), end(ans));

        return ans;
    }
};


// 2: Optimised: 2-pointer approach : TC: O(n-k), SC: O(1)
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // 2-pointers approach:
        int n=arr.size();
        
        int i=0, j=n-1;
        while((j-i+1)>k){
            if(abs(arr[i]-x) <= abs(arr[j]-x)){
                j--;
            }
            else{
                i++;
            }
        }

        vector<int> ans;
        for(int a=i; a<=j; a++){
            ans.push_back(arr[a]);
        }

        return ans;
    }
};


// 3: Using Binary Search, TC: O(log(n-k) + k)
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {        
        int n = size(arr), R = lower_bound(begin(arr), end(arr) - k, x) - begin(arr), L = R - 1;
        while(k--) 
            if(R >= n || L >= 0 && x - arr[L] <= arr[R] - x) L--;
            else R++;
        return vector<int>(begin(arr) + L + 1, begin(arr) + R);
    }
};
