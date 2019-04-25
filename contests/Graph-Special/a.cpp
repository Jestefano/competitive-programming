#include<bits/stdc++.h>
using namespace std;

#define nax 100000
#define FOR(i,n,m) for(int i=(n);i<(m);i++)
#define REP(i,n) FOR(i,0,n)
#define pb push_back

typedef vector<int> vi;

map<string,int> m;
vi v[nax];
int vis[nax];
bool var;

void dfs(int node, int parent){
	vis[node] = 1;
	for(int child:v[node]){
		if(!vis[child]){
			dfs(child,node);
		}else if(vis[child]==1){
			var = false;
		}
	}
	vis[node] = 2;
}

int main(){
	int t; cin>>t;
	int cas = 1;
	while(t--){
		int n; cin>>n;

		m.clear();
		int w =0;
		REP(i,nax) v[i].clear();
		REP(i,n){
			string s1,s2; cin>>s1>>s2;
			int x = (m.count(s1))?m[s1]:m[s1]=w++;
			int y = (m.count(s2))?m[s2]:m[s2]=w++;
			v[x].pb(y);
		}

		var = true;
		memset(vis,0,sizeof vis);
		REP(i,w){
			if(!vis[i]) dfs(i,-1);
		}
		cout<<"Case "<<cas<<": ";
		if(!var) cout<<"No"<<endl;
		else cout<<"Yes"<<endl;
		cas++;
	}

	return 0;
}
