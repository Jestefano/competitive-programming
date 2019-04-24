#include<bits/stdc++.h>
using namespace std;

#define nax 300009
#define FOR(i,n,m) for(int i =(n);i<(m);i++)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define mp make_pair
#define fst first
#define snd second

typedef vector<int> vi;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;

vii v[nax];

int main(){
	int n,m; cin>>n>>m;
	REP(i,m){
		int a,b,c; cin>>a>>b>>c;
		a--;b--;
		v[a].pb(mp(b,c));
		v[b].pb(mp(a,c));
	}

	int INF =100000;
	set<ii> s;
	int p[nax],dist[nax];
	REP(i,n) dist[i] = INF;
	dist[0] = 0; p[0]=-1;
	s.insert(mp(0,0));
	while(!s.empty()){
		int node = (s.begin())->snd;
		s.erase(s.begin());
		for(ii aux:v[node]){
			int child = aux.fst, w = aux.snd;
			if(dist[child]>dist[node]+w){
				s.erase(mp(dist[child],child));
				dist[child] = dist[node]+w;
				p[child]=node;
				s.insert(mp(dist[child],child));
			}
		}
	}

	return 0;
}
