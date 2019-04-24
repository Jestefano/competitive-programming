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

vi v[nax];
vector<vector<int> > comp;
stack<int> s;
int vis[nax], p[nax], low[nax],timer[nax], t = 0;
int scc;

void mini(int &a,int b){
	a = min(a,b);
}

void dfs(int node, int parent){
	s.push(node);
	vis[node] = 1;
	low[node] = timer[node] = t++;
	for(int child: v[node]){
		if(child==parent) continue;
		if(vis[child]==1){
			mini(low[node],timer[child]);
		}else if(!vis[child]){
			dfs(child,node);

			mini(low[node],low[child]);

		}
	}
	vis[node] = 2;

	if(low[node]==timer[node]){
		scc++;
		vi aux;
		while(1){
			aux.pb(s.top());
			if(s.top()==node){
				s.pop(); break;
			}
			s.pop();
		}
		comp.pb(aux);
	}
}

int main(){
	int n,m; cin>>n>>m;

	REP(i,m){
		int a,b; cin>>a>>b;
		a--;b--;
		v[a].pb(b);
	}

	dfs(0,-1);
	
	REP(i,comp.size()){
		REP(j,comp[i].size()){
			cout<<comp[i][j]+ 1<<" ";
		}
		cout<<endl;
	}

	return 0;
}
