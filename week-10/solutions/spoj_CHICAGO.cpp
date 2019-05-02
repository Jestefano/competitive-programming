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

vii v[nax];

int main(){
	int n,m; 
	double prob[nax];

	while(cin>>n,n){
		cin>>m;

		REP(i,n) v[i].clear();

		REP(i,m){
			int a,b,p; cin>>a>>b>>p;
			a--;b--;
			v[a].pb(mp(b,p));
			v[b].pb(mp(a,p));
		}

		set<pair<double,int> > s;
		REP(i,n) prob[i] = 0.0;
		prob[0] = 1.0;

		s.insert(mp(1.0,0));
		while(!s.empty()){
			int node = s.begin()->snd;
			s.erase(s.begin());
			for(ii aux : v[node]){
				int child = aux.fst;
				double w = 1.0 * aux.snd;
				w = (w/100.0);
				if(prob[node]*w>prob[child]){
					s.erase(mp(-prob[child],child));
					prob[child] = prob[node] * w;
					s.insert(mp(-prob[child],child));
				}
			}
		}

		printf("%9f percent\n",100*prob[n-1]);
	}

	return 0;
}
