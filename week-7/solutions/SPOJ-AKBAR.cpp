#include<bits/stdc++.h>
using namespace std;

#define MAX 1000007
#define FOR(i,n,m) for(int i = (n);i<(m);i++)
#define REP(i,n) FOR(i,0,n)
#define pb push_back

typedef vector<int> vi;

vi v[MAX];
int p[MAX], f[MAX],st[MAX],dist[MAX];
bool vis[MAX];
int t,n,r,k;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    
    
    //In this problem we are using multiple source BFS, one source per soldier
    //We have to be careful with multiple visits of different soldiers to the same node
    //And also check the maximum reach of each soldier. Those are the main considerations
    
	cin>>t;
	REP(i,t){
		REP(j,MAX){
			v[j].clear(); p[j] = 0;
			f[j] = 0; st[j] = 0;
			vis[j] = 0;
			dist[j] = -1; vis[j] = false;
		}
		cin>>n>>r>>k;
		queue<int> q;
		
		REP(j,r){
			int a,b; cin>>a>>b;
			v[a].pb(b); v[b].pb(a);
		}
		REP(j,k){
			int a,b; cin>>a>>b;
			q.push(a); dist[a] = 0;
			st[a] = b; f[a] = a;
			p[a] = -1; vis[a] = true;
		}

		bool x = true;
		while(!q.empty() && x){
			int u = q.front(); q.pop();
			if(dist[u] == st[f[u]]) continue;

			for(int w:v[u]){
				if(!vis[w]){
					p[w] = u; vis[w] = true;
					dist[w] = dist[u] + 1;
					f[w] = f[u];
					q.push(w);
				}else if(f[w]!=f[u]){
					x = false; break;
				}
			}
		}

		FOR(j,1,n+1){
			if(vis[j]==false){
				x = false; break;
			}
		}
		
		if(x) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}

	return 0;
}
