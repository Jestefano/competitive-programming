#include<bits/stdc++.h>
using namespace std;
 
#define nax 100010
#define FOR(i,n,m) for(int i =(n);i<(m);i++)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define sz(v) int(v.size())
#define all(v) v.begin(),v.end()
 
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
 
int main(){
	ll n, a; cin>>n>>a;
 
	ll ar1[nax],ar2[nax];
	REP(i,n){
		cin>>ar1[i]>>ar2[i];
	}
 
	vector<pair<double,ii> > v;
	REP(i,n){
		v.pb(mp(ar2[i]*1.0/ar1[i],mp(ar1[i],ar2[i])));
	}
 
	sort(all(v));
    ll numerador, denominador;
    numerador = a + v[0].second.second;
    denominador = v[0].second.first;
    ll ans = (numerador+denominador-1)/denominador;
    for(int i = 1; i < n; ++i){
        numerador += v[i].second.second;
        denominador += v[i].second.first;
        ans = min(ans,(numerador+denominador-1)/denominador);
    }
    cout << ans<<endl;
 
	return 0;
}
