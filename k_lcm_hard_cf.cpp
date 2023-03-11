// https://codeforces.com/contest/1497/problem/C2

// Approach: Same as easy version, but all element from 0..(k-3) are 1 and else k-3,k-2,k-1 will be found using easy version for n' = n-(k-3).

#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        
        vector<int> v(k, 1);
        n -= (k-3);
        if(n&1){
            v[k-3]=1, v[k-2]=(n/2), v[k-1]=(n/2);
        }
        else{
            int temp = n/2;
            if(temp&1){
                v[k-3]=2, v[k-2]=(n/2-1), v[k-1]=(n/2-1);
            }
            else{
                v[k-3]=(n/4), v[k-2]=(n/4), v[k-1]=(n/2);
            }
        }
        
        for(auto it: v){
            cout<<it<<" ";
        } 
        cout<<endl;
    }
    return 0;
}
  
  
