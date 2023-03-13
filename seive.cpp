// https://practice.geeksforgeeks.org/problems/sieve-of-eratosthenes5242/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

// Approach: Make a boolean vector, which contains all prime numbers less than equal to N, if true that means it is prime

class Solution
{
public:
    vector<int> sieveOfEratosthenes(int N)
    {
        // TC: O(nlog(logn)), SC: O(n)
        vector<bool> v(1e4+1, true);
        
        for(int i=2; i*i<=N; i++){ // i*i tk hi jana better hai, as uske baad j ki value bohot aage nikl jaegi
            if(v[i]==true){
                for(int j=i*i; j<=N; j+=i){ // if j=i*2 lete to 2 se to phle hi mark ho rkha, islie i*(i-1) tk bhi mark ho rha, thus we take i*i
                    v[j]=false;
                }
            }
        }
        
        vector<int> ans;
        for(int i=2; i<=N; i++){
            if(v[i]==true) ans.push_back(i); 
        }
        
        return ans;
    }
};

