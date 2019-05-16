#include<bits/stdc++.h>
using namespace std;

#define nax 200009
#define FOR(i,n,m) for(int i =(n);i<(m);i++)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define all(v) v.begin(),v.end()

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;

int n,vis[nax], indeg[nax];
bool cycle = false;
vi v[nax],ans;
int c[nax], d[nax];
int timer = 0;

void dfs_(int node){
	vis[node] = 1;
	for(int child:v[node]){
		if(vis[child]==1){
			cycle = true; return;
		}else if(vis[child]==0){
			dfs_(child);
		}
	}
	vis[node] = 2;
}

void dfs(){
	memset(vis,0,sizeof vis);
	REP(i,n){
		dfs_(i);
	}
}

bool comp(ii a, ii b){
	if(a.fst!=b.fst) return a.fst<b.fst;
	return a.snd<b.snd;
}

bool dfs__(int node){
	for(int child: v[node]){
		if(!vis[child]){
			dfs__(child);
		}
	}
	vis[node] = 1;
	timer+=c[node];
	if(timer>d[node]){
		return false;
	}
	ans.pb(node);
	return true;
}

int main(){
	cin>>n;
	vector<ii> k;

	REP(i,n){
		cin>>d[i]>>c[i];
		ll aux; cin>>aux;

		k.pb(mp(d[i],i));
		
		REP(j,aux){
			int w; cin>>w;
			w--;
			v[i].pb(w);
		}
	}

	dfs();
	if(cycle){
		cout<<"NO";
		return 0;
	}

	sort(all(k),comp);
	memset(vis,0,sizeof vis);

	REP(i,n){
		if(!vis[k[i].snd]){
			for(int child: v[k[i].snd]){
				if(!vis[child]){
					dfs__(child);
				}
			}
			vis[k[i].snd] = 1;
			timer+= c[k[i].snd];
			if(d[k[i].snd]<timer){
				cout<<"NO"; return 0;
			}
			ans.pb(k[i].snd);
		}
	}

	cout<<"YES"<<endl;
	REP(i,n){
		if(i) cout<<" ";
		cout<<ans[i]+1;
	}

	return 0;
}
