#include<bits/stdc++.h>
using namespace std;

#define nax 10000
#define FOR(i,n,m) for(int i =(n);i<(m);i++)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define mp make_pair
#define fst first
#define snd second

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int INF = 100000000;

int main(){
	int n,k; cin>>n>>k; 
	vi v(n);

	REP(i,n) cin>>v[i];

	list<ii> l;
	REP(i,k){
		while(!l.empty() && l.front().fst >= v[i]){
			l.pop_front();
		}
		l.push_front(mp(v[i],i));
	}
	vi ans;
	ans.pb(l.back().fst);

	FOR(i,k,n){
		if(!l.empty() && l.back().snd< i-k+1){
			l.pop_back();
		}

		while(!l.empty() && l.front().fst >= v[i]){
			l.pop_front();
		}
		l.push_front(mp(v[i],i));

		ans.pb(l.back().fst);
	}

	REP(i,n-k+1){
		cout<<ans[i]<<endl;
	}

	return 0;
}
