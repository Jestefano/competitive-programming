#include<bits/stdc++.h>
using namespace std;

#define nax 100009
#define FOR(i,n,m) for(int i =(n);i<(m);i++)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define mp make_pair
#define fst first
#define snd second

typedef pair<long long,long long> ii;
typedef vector<ii> vii;

long long INF = 100000000000000LL;
long long  dist[nax];
int parent[nax];
vii v[nax];

int main(){
	int n,m;
	cin>>n>>m;
	REP(i,m){
		long long a,b,c; cin>>a>>b>>c;
		a--;b--;
		v[a].pb(mp(b,c)); v[b].pb(mp(a,c));
	}

	set<ii> s;
	s.insert(mp(0LL,0LL));
	parent[0] = -1;
	REP(i,n) dist[i] = INF;
	dist[0] = 0 ;
	while(!s.empty()){
		int w = s.begin()->snd;
		s.erase(*s.begin());
		for(ii child: v[w]){
			if(dist[child.fst]>dist[w]+child.snd){
				s.erase(mp(dist[child.fst],child.fst));
				dist[child.fst] = dist[w] + child.snd;
				s.insert(mp(dist[child.fst],child.fst));
				parent[child.fst] = w;
			}
		}
	}

	if(dist[n-1]==INF){
		cout<<-1;
	}else{
		vector<int> anss; int k = n-1;
		while(1){
			if(k==-1) break;
			
			anss.pb(k+1);

			k = parent[k];
		}
		reverse(anss.begin(),anss.end());
		
		REP(i,anss.size()){
			if(i) cout<<" ";
			cout<<anss[i];
		}
	}

	return 0;
}
