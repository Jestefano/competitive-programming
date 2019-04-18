#include<bits/stdc++.h>
using namespace std;

#define nax 100009
#define FOR(i,n,m) for(int i =(n);i<(m);i++)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define all(v) v.begin(),v.end()
#define mp make_pair
#define fst first
#define snd second

typedef vector<int> vi;

int low[nax],timer[nax],t = 0,num_child = 0;
bool vis[nax],art[nax];
vi v[nax];

void mini(int &a,int b){
	a = min(a,b);
}

void dfs(int node, int parent){
	vis[node] = true;
	low[node] = timer[node] = t++;
	for(int child : v[node]){
		if(child==parent) continue;
		if(vis[child]){
			mini(low[node],timer[child]);
		}else{
			dfs(child,node);
			mini(low[node],low[child]);
			if(low[child]>=timer[node] && parent!=-1){
				art[node] = true;
			}
			if(parent==-1) num_child++;
		}
	}
	if(num_child>1 && parent==-1) art[node] = 1;
}

int main(){
	int n,m; 

	while(cin>>n>>m,n||m){
		REP(i,n) v[i].clear();
		REP(i,m){
			int a,b; cin>>a>>b;
			a--;b--;
			v[a].pb(b); v[b].pb(a);
		}

		t= 0; num_child = 0;
		memset(art,0,sizeof art);
		memset(vis,0,sizeof vis);
		dfs(0,-1);
		int cont = 0;
		REP(i,n){
			if(art[i]) cont++;
		}
		cout<<cont<<endl;
	}

	return 0;
}
