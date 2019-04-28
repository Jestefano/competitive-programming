#include<bits/stdc++.h>
using namespace std;

#define nax 100
#define FOR(i,n,m) for(ll i =(n);i<(m);i++)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define sz(v) int(v.size())
#define all(v) v.begin(),v.end()

typedef long long ll;
typedef vector<ll> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	ll n; cin>>n;

	vi d;
	FOR(i,1,n+1){
		if(n%i==0){
			d.pb(i);
		}
	}

	ll s = 1000000000000000000LL;
	REP(i,sz(d)){
		REP(j,sz(d)){
			REP(k,sz(d)){
				if(d[i]*d[j]*d[k]!=n) continue;
				s = min(2*(d[i]*d[j]+d[j]*d[k]+d[k]*d[i]),s);
			}
		}
	}
	
	cout<<s<<endl;

	return 0;
}
