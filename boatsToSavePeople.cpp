// https://leetcode.com/problems/boats-to-save-people/description/

// Approach: Sort array first and then do the 2 pointers approach, start and end

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n=people.size();
        int ans=0;
        sort(people.begin(), people.end());

        int i=0, j=n-1;
        while(i<=j){
            // that single person's weight should be less than 2 person equivalent weight (but handled by given tc's)
            if((people[i]*2) <= limit && i==j){
                ans++;
                break;
            }
            if(people[i]+people[j]<=limit){
                ans++;
                i++, j--;
            }
            else if(people[i]+people[j]>limit){
                j--, ans++;
            }
        }

        return ans;
    }
};
