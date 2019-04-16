#include<bits/stdc++.h>
using namespace std;

#define max_ 100
#define FOR(i,n,m) for(int i =(n);i<(m);i++)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define mp make_pair
#define sz(v) int(v.size())
#define fst first
#define snd second
#define all(v) v.begin(),v.end()

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

vi v[max_]; vii bridges;
bool vis[max_];
int low[max_],timer[max_],t = 0;

void min_self(int &a,int b){
	a = min(a,b);
}

void dfs(int node, int parent = -1){
	vis[node] = true;
	low[node] = timer[node] = t++;
	for(int child : v[node]){
		if(parent==child) continue;
		if(vis[child]){
			min_self(low[node],timer[child]);
		}else{
			dfs(child,node);
			min_self(low[node],low[child]);
			if(low[child]>timer[node]){
				int l = min(node,child);
				int t = max(node,child);
				bridges.pb(mp(l,t));
			}
		}
	}
}

int main(){
	int n,cont=0;
	while(cin>>n){
		REP(i,n){
			int w;
			char c; int a;
			cin>>w;cin>>c;
			v[w].clear();
			cin>>a;cin>>c;
			REP(j,a){
				int b; cin>>b;
				v[w].pb(b);
			}
		}

		bridges.clear();
		memset(vis,0,sizeof vis);
		REP(i,n){
			if(!vis[i]){
				t = 0;
				dfs(i);
			}
		}
		sort(all(bridges));

		if(cont) cout<<endl;
		cout<<sz(bridges)<<" critical links"<<endl;
		REP(i,sz(bridges)){
			cout<<bridges[i].fst<<" - "<<bridges[i].snd<<endl;
		}
		cout<<endl;
	}

	return 0;
}
