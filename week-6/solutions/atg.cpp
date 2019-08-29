#include<bits/stdc++.h>
using namespace std;

#define nax 100009
#define FOR(i,n,m) for(int i = (n);i<(m);i++)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define sz(v) int(v.size())

typedef vector<int> vi;

vi v[nax];
bool vis[nax];
int dp[nax];
int n,m;

void dfs_(int node){
	vis[node] = true;
	dp[node] = 0;
	for(int u:v[node]){
		if(vis[u]){
		 dp[node] = max(dp[node],dp[u]+1);
		 continue;
		}
		dfs_(u);
		dp[node] = max(dp[node],dp[u]+1);
	}
}

int dfs(){
	memset(vis,0,sizeof vis);
	REP(i,n){
		if(!vis[i]){
			dfs_(i);
		}
	}
	int ans = 0;
	REP(i,n){
		ans = max(ans,dp[i]);
	}
	return ans;
}


int main(){
	cin>>n>>m;

	REP(i,m){
		int x,y; cin>>x>>y;
		x--;y--;
		v[x].pb(y);
	}

	cout<<dfs();

	return 0;
}
