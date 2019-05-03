#include<bits/stdc++.h>
using namespace std;

#define nax 109
#define FOR(i,n,m) for(int i =(n);i<(m);i++)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define all(v) v.begin(),v.end()
#define mp make_pair
#define fst first
#define snd second
#define sz(v) int(v.size())

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

bool comp(ii a,ii b){
    if(a.fst-a.snd==b.fst-b.snd){
        return a.fst>b.fst;
    }
	return a.fst-a.snd>=b.fst-b.snd;
}

int main(){
	int n; cin>>n;
	vii v(n);
	REP(i,n){
		int a,b; cin>>a>>b;
		v.pb(mp(a,b));
	}
	sort(all(v),comp);
/*
	REP(i,n){
		cout<<v[i].fst<<" "<<v[i].snd<<endl;
	}*/

	ll ans = v[0].fst;
	ll act = v[0].fst-v[0].snd;
	FOR(i,1,n){
		ll need = v[i].fst - act;
		if(need<0) need = 0;
		ans+=need;
		act = act + need - v[i].snd;
	}

	cout<<ans<<endl;

	return 0;
}
