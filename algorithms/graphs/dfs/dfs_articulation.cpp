#include<bits/stdc++.h>
using namespace std;

#define max 100
#define FOR(i,n,m) for(int i =(n);i<(m);i++)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define mp make_pair
#define fst first
#define snd second

typedef vector<int> vi;

bool vis[max],art[max];
int low[max],timer[max],t=0,child = 0;
vi v[max];

void dfs(int node, int parent= -1){
	vis[node] = true;
	low[node] = timer[node] = t++;

	for(int u:v[node]){
		if(parent==u) continue;
		if(vis[u]){
			low[node] = min(low[node],timer[u]);
		}else{
			dfs(u,node);
			low[node] = min(low[node],low[u]);
			
			if(low[u]>=timer[node] && parent!=-1){
				art[node] = true;
			}
			if(parent==-1) child++;
		}
	}
	if(parent == -1 && child>1){
		art[node] = true;
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

	memset(art,0,sizeof art);
	memset(vis,0,sizeof vis);
	vis[0] = true;
	dfs(0);
	REP(i,n){
		if(art[i]) cout<<i+1<<endl;
	}

	return 0;
}
