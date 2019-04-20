#include<bits/stdc++.h>
using namespace std;

#define nax 400009
#define FOR(i,n,m) for(int i =(n);i<(m);i++)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define sz(v) int(v.size())
#define snd second
#define fst first
#define mp make_pair

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

map<ii,int> edges;
vi v[nax],tree[nax];
int low[nax],timer[nax],t=0,c=0,color[nax];
//color is a equivalence class
int vis[nax];
bool rev[nax];
ii edges2[nax];
int elem = 0;int max_color = 0;
int num_color[nax];
set <ii> bridges;

void mini(int &a,int b){
	a = min(a,b);
}

void dfs(int node, int parent){
	vis[node] = 1;
	low[node] = timer[node] = t++;

	for(int child:v[node]){
		if(child==parent) continue;

		if(vis[child]==1){
			mini(low[node],timer[child]);
			//Direction of the edge:
			tree[node].pb(child);
			if(edges.count(mp(child,node))){
				rev[edges[mp(child,node)]] = 1;
			}
		}else if(vis[child]==0){
			dfs(child,node);
			mini(low[node],low[child]);
			
			if(low[child]>timer[node]){
				//It is a bridge
				//We still need to check the minimum "big city"
				tree[child].pb(node);
				tree[node].pb(child);
				bridges.insert(mp(node,child));
			}else{
				tree[node].pb(child);
				//It is an internal edge:
				if(edges.count(mp(child,node))){
					rev[edges[mp(child,node)]] = 1;
				}
			}
		}
	}
	vis[node] = 2;
}

void dfs_(int node){
	vis[node] = true;

	for(int child :tree[node]){
		if(!vis[child]){
			if(bridges.count(mp(child,node)) || bridges.count(mp(node,child))){
				color[child] = ++c;
				num_color[color[child]]++;
			}else{
				color[child] = color[node];
				num_color[color[child]]++;
			}
			dfs_(child);
		}
	}
}

void dfs__(int node){
	vis[node] = 1;
	for(int child: tree[node]){
		if(!vis[child]){
			if(bridges.count(mp(child,node)) || bridges.count(mp(node,child))){
				//go from child to node
				if(edges.count(mp(node,child))){
					rev[edges[mp(node,child)]] = 1;
				}
			}
			dfs__(child);
		}
	}
}

int main(){
	memset(rev,0,sizeof rev);
	int n,m; cin>>n>>m;
	REP(i,m){
		int a,b; cin>>a>>b;
		a--;b--;
		v[a].pb(b);
		v[b].pb(a);
		edges[mp(a,b)] = i;
		edges2[i] = mp(a,b);
	}

	//Let's find the bridges!
	memset(vis,0,sizeof vis);
	dfs(0,-1);

	memset(num_color,0,sizeof num_color);
	num_color[0] = 1;
	color[0] = 0;
	memset(vis,0,sizeof vis);
	REP(i,n){
		if(!vis[i]){
			dfs_(i);
		}
	}

	int obj;
	max_color = 0;
	REP(i,n){
		if(num_color[color[i]]> max_color){
			max_color = num_color[color[i]];
			obj = i;
		}
	}

	memset(vis,0,sizeof vis);
	dfs__(obj);

	cout<<max_color<<endl;
	REP(i,m){
		if(rev[i]){
			cout<<edges2[i].snd+1<<" "<<edges2[i].fst+1<<endl;
		}else{
			cout<<edges2[i].fst+1<<" "<<edges2[i].snd+1<<endl;
		}
	}

	return 0;
}
