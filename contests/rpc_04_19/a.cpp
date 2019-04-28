#include<bits/stdc++.h>
using namespace std;

#define nax 100
#define FOR(i,n,m) for(int i =(n);i<(m);i++)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define sz(v) int(v.size())
#define all(v) v.begin(),v.end()

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	ll n,x;
	vi v;
	cin>>n>>x;
	REP(i,n){
		ll w; cin>>w;
		v.pb(w);
	}

	if(n<2){
		cout<<1<<endl;
		return 0;
	}

	sort(all(v));
	vi ans; 

	ans.pb(v[0]);
	FOR(i,1,n){
		if(v[i]+*ans.rbegin()>x) break;
		else ans.pb(v[i]);
	}

	cout<<sz(ans)<<endl;

	return 0;
}
