#include<bits/stdc++.h>
using namespace std;

#define nax 20009
#define FOR(i,n,m) for(int i =(n);i<(m);i++)
#define REP(i,n) FOR(i,0,n)
#define pb push_back

typedef vector<int> vi;

vi v[nax];
int low[nax],timer[nax],t,vis[nax],color[nax],c;
int indeg[nax],outdeg[nax],in,out;
stack<int> s;

void mini(int &a,int b){
	a = min(a,b);
}

void dfs(int node){
	vis[node] = 1;
	low[node] = timer[node] = t++;
	s.push(node);
	for(int child:v[node]){
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
			color[aux]=c; if(aux==node) break;
		}
		c++;
	}
	vis[node] = 2;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int k,n,m; cin>>k;

	REP(w,k){
		cin>>n>>m;
		REP(i,n) v[i].clear();
		REP(i,m){
			int a,b; cin>>a>>b;
			a--;b--;
			v[a].pb(b);
		}

		c=0;t=0;
		memset(vis,0,sizeof vis);
		REP(i,n){
			if(!vis[i]) dfs(i);
		}

		memset(indeg,0,sizeof indeg);
		memset(outdeg,0,sizeof outdeg);
		in = 0; out=0;
		REP(node,n){
			for(int child:v[node]){
				if(color[child]!=color[node]){
					outdeg[color[node]]++;
					indeg[color[child]]++;
				}
			}
		}
		REP(i,c){
			if(indeg[i]==0) in++;
			if(outdeg[i]==0) out++;
		}

		cout<<"Case "<<w+1<<": ";
		if(c!=1)cout<<max(in,out)<<endl;
		else cout<<0<<endl;
	}

	return 0;
}
