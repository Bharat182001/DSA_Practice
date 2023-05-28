// https://leetcode.com/problems/minimum-time-to-complete-trips/description/

// 2187. Minimum Time to Complete Trips
// LOGIC: brute is easy enough, optimised solution needs binary search and lower and upper limits are pretty much the crux of problem.

class Solution {
public:
    bool possibleHai(vector<int> &time, long long givenTime, long long totalTrips){
        long long actualTrips=0;
        for(auto &it: time){
            actualTrips += (givenTime/it);
        }
        return (actualTrips >= totalTrips);
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        // Best Solution, TC: O(nlog(p)), p -> min_ele*totalTrips
        int n=time.size();

        long long l=1;
        long long h=(long long) *min_element(begin(time), end(time)) * totalTrips;

        while(l<h){
            long long mid = l + (h-l)/2;

            if(possibleHai(time, mid, totalTrips)){
                h=mid;
            }
            else{
                l=mid+1;
            }
        }
        return l;
    }
};
