#include<bits/stdc++.h>
using namespace std;

#define FOR(i,n,m) for(int i =(n);i<(m);i++)
#define REP(i,n) FOR(i,0,n)
#define nax 10009
#define sz(v) int(v.size())
#define pb push_back

typedef vector<int> vi;
typedef pair<int,int> ii;

priority_queue<int> pq;
vi ans, v[nax];
int indeg[nax];
int vis[nax], rpta = true;

void toposort(){
	while(!pq.empty()){
		int node = -pq.top();
		pq.pop();
		ans.pb(node);
		for(int child : v[node]){
			if(indeg[child]==1){
				pq.push(-child);
			}else{
				indeg[child]--;
			}
		}
	}
}

void dfs(int node){
	vis[node] = 1;
	for(int child :v[node]){
		if(vis[child]==1){
			rpta = false;
		}else if(!vis[child]){
			dfs(child);
		}
	}
	vis[node] = 2;
}

int main(){
	int n,m; cin>>n>>m;
	memset(indeg,0,sizeof indeg);
	REP(i,m){
		int a,b; cin>>a>>b;
		a--;b--;
		indeg[b]++;
		v[a].pb(b);
	}

	memset(vis,0,sizeof vis);	
	REP(i,n){
		if(!vis[i]) dfs(i);
	}
	
	if(rpta==false){
		cout<<"Sandro fails.";
		return 0;
	}

	REP(i,n){
		if(!indeg[i]) pq.push(-i);
	}
	toposort();

	REP(i,sz(ans)){
		if(i) cout<<" ";
		cout<<ans[i]+1;
	}

	return 0;
}
