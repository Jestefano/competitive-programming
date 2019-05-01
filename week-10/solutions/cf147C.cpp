#include<bits/stdc++.h>
using namespace std;

#define FOR(i,n,m) for(int i =(n);i<(m);i++)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define nax 1000009
#define sz(v) int(v.size())
#define all(v) v.begin(),v.end()

typedef long long ll;
typedef vector<int> vi;

int main(){
	int a,b,k; cin>>a>>b>>k;
	bool sieve[nax];
	vi primes;

	memset(sieve,0,sizeof sieve);
	for(ll i = 2;i<=b;i++){
		if(sieve[i]) continue;
		if(i>=a)primes.pb(i);
		for(ll j = i*i;j<=b;j+=i){
			sieve[j] = 1;
		}
	}
	if(sz(primes)<k){
		cout<<-1<<endl;
		return 0;
	}

	//Here we already have primes!
	int l = -1, ant=0; 

	//If there is a moment that we
	//cant get k, break!
	FOR(x,a,b+1){
		int pos = lower_bound(all(primes),x)-primes.begin();
		if(sz(primes)-pos>=k){
			ant = b-x;
			l = max(l,primes[pos+k-1]-x);
		}else{
			l = max(ant,l);
			break;
		}
	}

	cout<<l+1<<endl;

	return 0;
}
