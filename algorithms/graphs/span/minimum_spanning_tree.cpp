#include<bits/stdc++.h>
using namespace std;

#define nax 100
#define FOR(i,n,m) for(int i =(n);i<(m);i++)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define mp make_pair
#define snd second
#define fst first
#define all(v) v.begin(),v.end()
#define sz(v) int(v.size())

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

vi p,r;
vii v[nax];
vector<pair<int,ii> > edges;

void init_union(int n){
	p.assign(n,0); r.assign(n,0);
	REP(i,n) p[i] = i;
}

int Find(int node){
	return (node==p[node])? node:p[node] = Find(p[node]);
}

bool Equal(int a,int b){
	return Find(a)==Find(b);
}

void Union(int a,int b){
	if(!Equal(a,b)){
		int x = Find(a), y = Find(b);
		if(r[x]<r[y]){
			p[x] = y;
		}else{
			p[y] = x;
			if(r[x]==r[y]) r[x]++;
		}
	}
}

int main(){
	int n,m; cin>>n>>m;
	REP(i,m){
		int a,b,c; cin>>a>>b>>c;
		a--;b--;
		v[a].pb(mp(b,c));
		v[b].pb(mp(a,c));
		edges.pb(mp(c,mp(a,b)));
	}

	sort(all(edges));
	init_union(n);

	int tot_w = 0;
	vii min_span;
	REP(i,m){
		int w = edges[i].fst;
		int a = edges[i].snd.fst, b= edges[i].snd.snd;
		if(Equal(a,b)) continue;
		tot_w += w;
		Union(a,b);
		min_span.pb(mp(a,b));
	}

	cout<<tot_w<<endl;
	REP(i,sz(min_span)){
		cout<<min_span[i].fst<<" "<<min_span[i].snd<<endl;
	}

	return 0;
}
