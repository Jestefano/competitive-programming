#include<bits/stdc++.h>
using namespace std;

#define max 100
#define FOR(i,n,m) for(int i = (n);i<(m);i++)
#define REP(i,n) FOR(i,0,n)
#define pb push_back

typedef vector<int> vi;

int estado[max],p[max];
int cycle = 0, cycle_beg, cycle_end;

vi v[max];

void dfs_(int u){
	for(int w : v[u]){
		if(estado[w]==0){
			estado[w] = 1;
			p[w] = u;
			dfs_(w);
		}else if(estado[w]==1 && p[u]!=w){
			cycle_beg = u;
			cycle_end = w;
			cycle = true;
		}
	}
	estado[u] = 2;
}

void dfs(int n){
	memset(estado,0,sizeof estado);
	cycle = false;
	REP(i,n){
		if(estado[i]==0){
			p[i] = -1;
			estado[i] = 1;
			dfs_(i);
		}
	}

	if(cycle){
		int k = cycle_beg;
		while(cycle_end!=k){
			cout<<k<<endl;
			k = p[k];
		}
		cout<<k<<endl;
	}
}

int main(){
	int n,m; cin>>n>>m;

	REP(i,m){
		int a,b; cin>>a>>b;
		a--;b--;
		v[a].pb(b);
		v[b].pb(a);
	}

	dfs(n);

	return 0;
}