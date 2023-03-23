// https://practice.geeksforgeeks.org/problems/sum-of-elements-between-k1th-and-k2th-smallest-elements3133/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

Approach: Use maxHeap


long long sumBetweenTwoKth( long long A[], long long N, long long K1, long long K2)
    {
        // maxHeap, TC: O(NlogK2)
        priority_queue<long long> maxHp;
        for(long long i=0; i<N; i++){
            maxHp.push(A[i]);
            
            if(maxHp.size() > K2) maxHp.pop();
        }
        
        //pop the k2th smallest element
        maxHp.pop();
        
        long long ans=0;
        while(maxHp.size() > K1){
            ans += maxHp.top();
            maxHp.pop();
        }
        
        return ans;
    }
