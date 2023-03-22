// https://practice.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1

// Approach: use minHeap

long long minCost(long long arr[], long long n) {
        // use minHeap to store all elements of array and then
        // fetch top 2 and pop them and again insert them.
        
        // minHeap
        priority_queue< long long, vector<long long>, greater<long long> > pq;
        for(int i=0; i<n; i++){
            pq.push(arr[i]);
        }
        
        long long cost=0;
        while(pq.size() != 1){
            long long firstRope = pq.top();
            pq.pop();
            long long secondRope = 0;
            //maybe only single rope is left, so no second rope in that case
            if(!pq.empty()){
                secondRope = pq.top();
                pq.pop();
            }
            
            cost += (firstRope + secondRope);
            pq.push(firstRope + secondRope);
        }
        
        return cost;
    }
