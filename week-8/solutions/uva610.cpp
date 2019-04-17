#include<bits/stdc++.h>
using namespace std;

#define max_ 1009
#define FOR(i,n,m) for(int i =(n);i<(m);i++)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define mp make_pair
#define fst first
#define snd second

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int n,m, timer[max_],low[max_],t = 0 ;
vi v[max_];
set<ii> rpta;
int vis[max_];

void mini(int &a,int b){
	a = min(a,b);
}

void dfs(int node, int parent){
	vis[node] = 1;
	low[node] = timer[node] = t++;
	for(int child: v[node]){
		if(child==parent) continue;

		if(vis[child]==1){
			//it is backedge:
			rpta.insert(mp(node,child));
			
			mini(low[node],timer[child]);
		}else if(vis[child]==0){
			dfs(child,node);

			rpta.insert(mp(node,child));

			mini(low[node],low[child]);
			if(low[child]>timer[node]){
				//node,child is bridge
				//We have to return!
				rpta.insert(mp(child,node));
			}
		}
	}
	vis[node] =2;
}

int main(){
	int cas= 1;
	while(cin>>n>>m,n||m){
		REP(i,n){
			v[i].clear();
		}
		REP(i,m){
			int a,b; cin>>a>>b;
			a--;b--;
			v[a].pb(b); v[b].pb(a);
		}

		rpta.clear();
		memset(vis,0,sizeof vis);
		dfs(0,-1);

		cout<<cas<<endl<<endl;
		for(auto it = rpta.begin();it!=rpta.end();it++){
			cout<<(it->fst+1)<<" "<<(it->snd+1)<<endl;
		}
		cout<<"#"<<endl;
		cas++;
	}

	return 0;
}
