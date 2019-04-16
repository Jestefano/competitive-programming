#include<bits/stdc++.h>
using namespace std;

#define max 1000
#define FOR(i,n,m) for(int i =(n);i<(m);i++)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define mp make_pair
#define fst first
#define snd second

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

//bridges
vi v[max];
bool vis[max];
int low[max],timer[max],t=0;
vii bridges;

void dfs(int node, int parent = -1){
	vis[node] = true;
	low[node] = timer[node] = t++;

	for(int u:v[node]){
		if(parent==u) continue;
		if(vis[u]){
			//This is a backedge:
			low[node] = min(low[node],timer[u]);
		}else{
			dfs(u,node);
			low[node] = min(low[u],low[node]);
			
			if(low[u]>timer[node]){
				bridges.pb(mp(node,u));
			}
		}
	}
}

int main(){
	int n,m; cin>>n>>m;
	REP(i,m){
		int a,b; cin>>a>>b;
		a--;b--;
		v[a].pb(b); v[b].pb(a);
	}

	memset(vis,0,sizeof vis);
	dfs(0);

	REP(i,bridges.size()){
		cout<<bridges[i].fst + 1<<" "<<bridges[i].snd + 1<<endl;
	}

	return 0;
}