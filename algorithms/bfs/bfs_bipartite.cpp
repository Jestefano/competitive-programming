#include<bits/stdc++.h>
using namespace std;

#define FOR(i,n,m) for(int i =(n);i<(m);i++)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define maxx 2009

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<int,int> vii;

vi v[maxx];
bool vis[maxx], color[maxx], bip = true;

int main(){
	int n,m; cin>>n>>m;

	REP(i,m){
		int a,b; cin>>a>>b;
		a--;b--;
		v[a].pb(b); v[b].pb(a);
	}

	queue<int> q;
	memset(vis,0,sizeof vis);

	REP(i,n){
		if(vis[i]) continue;

		q.push(i);
		color[i] = true;
		vis[i] = true;

		while(!q.empty()){
			int node = q.front();
			q.pop();
			for(int child: v[node]){
				if(vis[child]){
					if(color[child]==color[node]){
						bip = false;
					}
				}else{
					vis[child] = true;
					color[child] = !color[node];
					q.push(child);
				}
			}
		}
	}

	if(bip) cout<<"It is bipartite";
	else cout<<"It is not bipartite";

	return 0;
}
