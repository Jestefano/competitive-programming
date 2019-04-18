#include<bits/stdc++.h>
using namespace std;

#define nax 200009
#define FOR(i,n,m) for(int i =(n);i<(m);i++)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define mp make_pair
#define fst first
#define snd second

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int n,m;
bool vis[nax], color[nax];
vi v[nax];
map<ii,int> edges;

bool bin[nax];

int main(){
	cin>>n>>m;

	REP(i,m){
		int a,b; cin>>a>>b;
		a--;b--;
		v[a].pb(b); v[b].pb(a);
		edges[mp(a,b)] = i;
	}

	memset(vis,0,sizeof vis);
	queue<int> q;
	q.push(0);
	vis[0] = true;
	bool bip = true;

	while(!q.empty() && bip){
		int node = q.front();
		q.pop();

		for(int child:v[node]){
			if(vis[child]){
				if(color[child]==color[node]){
					bip = false; break;
				}
				if(color[node]==0){
					if(edges.count(mp(node,child))){
						bin[edges[mp(node,child)]] = 0;
					}else{
						bin[edges[mp(child,node)]] = 1;
					}
				}else{
					if(edges.count(mp(node,child))){
						bin[edges[mp(node,child)]] = 1;
					}else{
						bin[edges[mp(child,node)]] = 0;
					}
				
				}
			}else{
				vis[child] = true;
				color[child] = !color[node];
				
				if(color[node]==0){
					if(edges.count(mp(node,child))){
						bin[edges[mp(node,child)]] = 0;
					}else{
						bin[edges[mp(child,node)]] = 1;
					}
				}else{
					if(edges.count(mp(node,child))){
						bin[edges[mp(node,child)]] = 1;
					}else{
						bin[edges[mp(child,node)]] = 0;
					}
				
				}
				q.push(child);
			}
		}
	}
	if(bip){
		cout<<"YES"<<endl;
		REP(i,m){
			cout<<bin[i];
		}
	}else{
		cout<<"NO"<<endl;
	}

	return 0;
}
