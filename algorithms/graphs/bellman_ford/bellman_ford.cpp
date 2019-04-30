#include<bits/stdc++.h>
using namespace std;

#define nax 100
#define pb push_back
#define FOR(i,n,m) for(int i =(n);i<(m);i++)
#define REP(i,n) FOR(i,0,n)
#define fst first
#define snd second
#define mp make_pair

typedef pair<int,int> ii;

int INF = 1000, p[nax], d[nax];
vector<pair<int,ii> > edges;
bool neg_cicle = false;

void bellman_ford(int n, int m, int s){
	REP(i,n) d[i] = INF;
	d[s] = 0;
	p[s] = -1;
	REP(i,n-1){
		REP(j,m){
			int w = edges[j].fst;
			int node1 = edges[j].snd.fst, node2 = edges[j].snd.snd;
			if(d[node1]==INF) continue;
			if(d[node1]+w<d[node2]){
				d[node2] = d[node1] + w;
				p[node2] = node1;
			}
		}
	}
	
	neg_cicle = false;
	REP(j,m){
		int w = edges[j].fst;
		int node1 = edges[j].snd.fst, node2 = edges[j].snd.snd;
		if(d[node1]==INF) continue;
		if(d[node1]+w<d[node2]){
			neg_cicle = true;
		}
	}
	
}

int main(){
	int n,m; cin>>n>>m;
	REP(i,n){
		int a,b,c; cin>>a>>b>>c;
		a--;b--;
		edges.pb(mp(c,mp(a,b)));
	}
	bellman_ford(n,m,0);
	
	REP(i,n){
		cout<<d[i]<<endl;
	}
	cout<<neg_cicle<<endl;

	return 0;
}
