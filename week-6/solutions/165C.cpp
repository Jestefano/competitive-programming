#include<bits/stdc++.h>
using namespace std;

#define MAX 100
#define FOR(i,n,m) for(ll i = (n);i<(m);i++)
#define REP(i,n) FOR(i,0,n)
#define mp make_pair

typedef long long ll;

int main(){
	string s; ll n;
	ll cant = 0;
	map<ll,ll> m;
	m[0] =1;

	cin>>n; cin>>s;


//The main idea is to use accumulated sums 
	ll ult_val = 0;
	REP(i,s.size()){
		if(s[i]=='0'){
			m[ult_val]++;
		}else{
			ult_val++;
			m[ult_val]++;
		}
	}

	if(n!=0){
		for(auto it = m.begin();it!=m.end();it++){
			if(it->first >=n){
				auto aux = m.lower_bound((it->first) - n);
				if((aux->first) == (it->first - n));
					cant+=(it->second) * (aux->second);
			}
		}
	}else{
		for(auto it = m.begin();it!=m.end();it++){
			cant += (it->second) * (it->second-1) /2;
		}
	}
	
	cout<<cant;

	return 0;
}
