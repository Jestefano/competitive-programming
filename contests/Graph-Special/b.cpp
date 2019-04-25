#include<bits/stdc++.h>
using namespace std;

#define nax 10009
#define FOR(i,n,m) for(int i =(n);i<(m);i++)
#define REP(i,n) FOR(i,0,n)
#define pb push_back

typedef vector<int> vi;

int vis[nax],low[nax],color[nax],timer[nax],t=0,c=0;
stack<int> s;
int indeg[nax];
vi v[nax];

void mini(int &a,int b){
	a = min(a,b);
}

void dfs(int node){
	s.push(node);
	vis[node] = 1;
	low[node] = timer[node] = t++;
	for(int child: v[node]){
		if(vis[child]==1){
			mini(low[node],timer[child]);
		}else if(vis[child]==0){
			dfs(child);
			mini(low[node],low[child]);
		}
	}
	if(low[node] == timer[node]){
		while(1){
			int aux = s.top(); s.pop();
			color[aux] = c; if(aux==node) break;
		} 
		c++;
	}
	vis[node] = 2;
}

int main(){
	int k,n,m;

	cin>>k;
	REP(w,k){
		if(w) cout<<endl;
		cin>>n>>m;
		
		REP(i,n) v[i].clear();

		REP(i,m){
			int a,b; cin>>a>>b;
			a--;b--;
			v[a].pb(b);
		}

		t=0;c=0;
		memset(vis,0,sizeof vis);
		REP(i,n){
			if(!vis[i]) dfs(i);
		}

		memset(indeg,0,sizeof indeg);
		REP(i,n){
			for(int node:v[i]){
				if(color[i]!=color[node]){
					indeg[color[node]]++;
				}
			}
		}
		int ans = 0;
		REP(i,c){
			if(indeg[i]==0) ans++;
		}
		cout<<"Case "<<w+1<<": "<<ans;
	}

	return 0;
}
