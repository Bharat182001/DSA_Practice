// https://codeforces.com/problemset/problem/1051/B

// Relatively Prime Pairs : Logic: Numbers with difference 1 are always relatively prime.

#include <bits/stdc++.h>
#define ll long long 
using namespace std;
 
int main() {
    ll l, r;
    cin>>l>>r;
    
    vector<pair<ll, ll>> vec;
    for(ll i=l; i<=r; i+=2){
        vec.push_back({i, i+1});
    }
    cout<<"YES\n";
    for(auto it: vec){
        cout<<it.first<<" " <<it.second<<endl;
    }
    return 0;
}
