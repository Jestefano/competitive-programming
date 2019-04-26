#include<bits/stdc++.h>
using namespace std;

#define nax 62
#define FOR(i,n,m) for(int i =(n);i<(m);i++)
#define REP(i,n) FOR(i,0,n)
#define pb push_back

typedef unsigned long long ll;
typedef vector<ll> vi;

vi v;
ll mod = 1000000007LL;

ll f(ll x){
	if(x==0) return 0LL;
	if(x==1) return 1LL;
	if(x==2) return 4LL;

	ll par = 0LL, imp = 0LL;
	ll k =1, it = 1;
	while(1){
		if(it%2==1){
			imp=(imp+min(v[it-1],x-k+v[it-1]))%mod;
		}else{
			par=(par+min(v[it-1],x-k+v[it-1]))%mod;
		}
		if(k>x) break;
		k += v[it];
		it++;
	}
	return ((imp*imp)%mod + (par*(par+1))%mod)%mod;
}

int main(){
	v.pb(1LL);
	REP(i,nax){
		v.pb(*v.rbegin()*2);
	}

	ll l, r; cin>>l>>r;

	cout<<(f(r)-f(l-1)+mod)%mod;

	return 0;
}
