#include<bits/stdc++.h>
using namespace std;
 
#define nax 100009
#define FOR(i,n,m) for(int i = (n);i<(m);i++)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define fst first
#define snd second
#define mp make_pair
#define sz(v) int(v.size())
#define all(v) v.begin(),v.end()
 
typedef long long ll;
typedef vector<ll> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
 
int main(){
	ll n,k; cin>>n>>k;
	vi v(n);
	REP(i,n) cin>>v[i];
 
	ll ac =0 ;
	sort(all(v));
	FOR(i,n/2,n) ac+=v[i]; 
 
	int w = 0;
	for(int i = n-1;i>=0;i--){
		ll s = ((n+1)/2 -w)*v[i];
		if(s-ac<=k){
			cout<<v[i]+(k-s+ac)/((n+1)/2 -w);
			break;
		}
		ac-=v[i];
		w++;
	}
 
	return 0;
}
