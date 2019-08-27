#include<bits/stdc++.h>
using namespace std;

int main(){
	int n; cin>>n;
	vector<int> v;
	
	for(int i = 0;i<(n);i++){
		int x; cin>>x;
		v.push_back(x);
	}
	
	map<int,int> m;
	for(int i=(0);i<(n);i++){
		m[v[i]] = m[v[i]] + 1;
		//Si v[i] no esta en el mapa, m[v[i]] = 0
	}
	
	for(auto it = m.begin();it!=m.end();it++){
		cout<<(it->first)<<" "<<(it->second)<<endl;
	}

	return 0;
}