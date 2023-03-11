// https://codeforces.com/contest/1497/problem/A

// Approach: use a map for storing the elements with their frequency, then store the consecutive elements first, then remaining repeating elements in ans vector

#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> v(n);
		for(int i=0; i<n; i++){
			cin>>v[i];
		}

		vector<int> ans;
		// first put those elements which are consecutive
		unordered_map<int,int> mp;
		for(int i=0; i<n; i++){
			mp[v[i]]++;
		}

		for(int i=0; i<=100; i++){
			if(mp.find(i) != mp.end()){
				ans.push_back(i);
				mp[i]--;
			}
		}

		for(auto it: mp){
			while(it.second>0){
				ans.push_back(it.first);
				it.second--;
			}
		}

		for(auto it: ans){
			cout<<it << " ";
		}
		cout<<endl;
	}
}
