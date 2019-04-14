#include<bits/stdc++.h>
using namespace std;

#define max 300009
#define FOR(i,n,m) for(int i = (n);i<(m);i++)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define sz(v) int(v.size())
#define mp make_pair

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int n,k,d,dist[max],p[max];
	vi v[max];
	bool vis[max];
	queue<int> q;
	cin>>n>>k>>d;
	
	memset(vis,0,sizeof vis);
	memset(dist,-1,sizeof dist);
	memset(p,-1,sizeof p);
	
	REP(i,k){
		int a; cin>>a;
		a--;
		q.push(a);
		dist[a] = 0;
		p[a] = a;
		vis[a] = 1;
	}

	map<ii,int> aristas;
	REP(i,n-1){
		int a,b; cin>>a>>b;
		a--; b--;
		aristas[mp(a,b)] = i + 1;
		aristas[mp(b,a)] = i + 1;

		v[a].pb(b);
		v[b].pb(a);
	}

	set<int> cortar;
	while(!q.empty()){
		int aux = q.front();
		q.pop();

		if(dist[aux]==d + 1) continue;
		
		for(int u:v[aux]){
			if(!vis[u]){
				vis[u] = true;
				p[u] = p[aux];
				dist[u] = dist[aux] + 1; 
				q.push(u);
			}else{
				if(p[aux]==p[u]);
				else{
					cortar.insert(aristas[mp(u,aux)]);
				}
			}
		}
	}

	cout<<cortar.size()<<endl;
	int cont = 0;
	for(auto it = cortar.begin();it!= cortar.end();it++){
		
		if(cont) cout<<" ";
		cout<<*it;
		cont++;
	}

	return 0;
}
