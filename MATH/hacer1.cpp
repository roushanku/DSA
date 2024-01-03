//https://www.hackerearth.com/practice/math/number-theory/basic-number-theory-2/practice-problems/algorithm/hacker-with-prime-bebe28ac/
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
const int N = 2e6+10;
int hp[N];
int Canremove[N]; //remove[i]=1 if i can be remove from the arr else 0
int mp[N];
int n,q;
vector <int> distprime(int x){
	vector <int> ans;
	while(x>1){
		int pf=hp[x];
		while(x % pf == 0) x/=pf;
		ans.push_back(pf);
	}
	return ans;
}

int main() {

	for(int i=2;i<N;i++){
		if(hp[i]==0){
			for(int j=i;j<N;j+=i){
				hp[j]=i;
			}
		}
	}

	cin>>n>>q;

	int arr[n];
	for(int i=0;i<n;i++) {
		cin>>arr[i];
		mp[arr[i]]=1;
	}

	//variation in sieve -> instead of moving to multiple we will move to power
	for(int i=2;i<N;i++){
		if(mp[i]){
			for(int j=i;j<N;j*=i){
				Canremove[j]=1;
			}
		}
	}

	while(q--){
		int x;
		cin>>x;

		vector <int> v = distprime(x);
		
		
		bool ok = false;
		for(int i=0;i<v.size();i++){
			for(int j=i;j<v.size();j++){
				int prod = v[i]*v[j];
				if(i==j && x%prod !=0 )continue;
				int toremove = x/prod;
				if(Canremove[toremove]==1 || toremove==1){
					ok=true;
					break;
				}
			}
			if(ok) break;
		}

		if(ok) cout<<"YES"<<"\n";
		else cout<<"NO"<<"\n";
	}
}