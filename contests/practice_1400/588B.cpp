#include<bits/stdc++.h>
using namespace std;
 
#define nax 1000009
#define FOR(i,n,m) for(int i = (n);i<(m);i++)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define sz(v) int(v.size())
 
typedef long long ll;
typedef vector<ll> vi;
 
int main(){
	ll n; cin>>n;
	bool sieve[nax];
	memset(sieve,0,sizeof sieve);
	vi primos;
 
	for(ll i=2;i<nax;i++){
		if(sieve[i]) continue;
		primos.pb(i);
		for( ll j = i*i;j<nax;j+=i){
			sieve[j] = true;
		}
	}
 
	vi div;
	ll ans = 1;
	REP(i,sz(primos)){
		if(n%primos[i]==0){
			ans *=(primos[i]);
			while(n%primos[i]==0){
				n/=primos[i];
			}
		}
	}
	if(n!=1) ans*=n;
 
	cout<<ans;
  /*
  Apply sieve and extract prime factors
  */
 
	return 0;
}
