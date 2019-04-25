#include<bits/stdc++.h>
using namespace std;

#define nax 100000
#define FOR(i,n,m) for(int i=(n);i<(m);i++)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define mp make_pair
#define sz(v) int(v.size())

typedef vector<int> vi;
typedef pair<int,int> ii;

vi v[nax], v_[nax];
int color[nax],c=0;
int timer[nax], low[nax],t = 0, vis[nax];
stack<int> s;

void mini(int &a,int b){
	a = min(a,b);
}

void dfs(int node){
	vis[node] = 1;
	timer[node] = low[node] = t++;
	s.push(node);
	for(int child: v[node]){
		if(vis[child]==1){
			mini(low[node],timer[child]);
		}else if(vis[child]==0){
			dfs(child);
			mini(low[node],low[child]);
		}
	}
	if(low[node]==timer[node]){
		while(1){
			int aux = s.top(); s.pop();
			color[aux] = c;
			if(aux==node) break;
		}
		c++;
	}
	vis[node] = 2;
}

void dfs_(int node){
	vis[node] = true;
	for(int child:v_[node]){
		if(!vis[child]){
			dfs_(child);
		}
	}
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	int n,m; cin>>n>>m;
	REP(i,m){
		int a,b; cin>>a>>b;
		a--;b--;
		v[a].pb(b);
		v_[b].pb(a);
	}

	memset(vis,0,sizeof vis);
	REP(i,n){
		if(!vis[i]) dfs(i);
	}
	//We need to compute a SCC with 0 as indegree
	//And there is only one capital!
	int outdeg[nax];
	memset(outdeg,0,sizeof outdeg);

	REP(i,n){
		for(int u:v[i]){
			if(color[i]!=color[u]){
				outdeg[color[i]]++;
			}
		}
	}
	int rep;
	REP(i,n){
		if(outdeg[color[i]]==0){
			rep = i;
			break;
		}
	}
	memset(vis,0,sizeof vis);
	dfs_(rep);

	bool no_vis=false;
	REP(i,n){
		if(vis[i]==0){
			no_vis=true;
		}
	}

	if(no_vis){
		cout<<0;
	}else{
		vi ans;
		REP(i,n){
			if(color[i]==color[rep]){
				ans.pb(i);
			}
		}
		cout<<sz(ans)<<endl;
		sort(ans.begin(),ans.end());
		REP(i,sz(ans)){
			if(i) cout<<" ";
			cout<<ans[i]+1;
		}
	}

	return 0;
}
