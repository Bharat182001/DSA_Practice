// https://codeforces.com/contest/1497/problem/C1

#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        
        vector<int> v(3);
        if(n&1){
            v[0]=1, v[1]=(n/2), v[2]=(n/2);
        }
        else{
            int temp = n/2;
            if(temp&1){
                v[0]=2, v[1]=(n/2-1), v[2]=(n/2-1);
            }
            else{
                v[0]=(n/4), v[1]=(n/4), v[2]=(n/2);
            }
        }
        
        cout<<v[0]<< " " << v[1] << " " <<v[2] << endl; 
    }
    return 0;
}
