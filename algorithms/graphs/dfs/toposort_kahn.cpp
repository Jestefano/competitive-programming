#include<bits/stdc++.h>
using namespace std;

#define nax 100009
#define FOR(i,n,m) for(int i =(n);i<(m);i++)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define all(v) v.begin(),v.end()
#define mp make_pair
#define fst first
#define snd second
#define sz(v) int(v.size())

typedef vector<int> vi;

//This algorithm only works if we already know that
//there is no backedge (run dfs!)

int n,m;
//Notice that we can change queue with anything we want! This give us an enormous flexibility!
queue<int> pq;
int indeg[nax];
vi v[nax],ans;

void topo_sort(){
	REP(i,n){
		if(!indeg[i]){
			pq.push(i);
			cout<<i<<endl;
		}
	}

	while(!pq.empty()){
		int node = pq.front();
		pq.pop();
		ans.pb(node);
		for(int child:v[node]){
			if(indeg[child]==1){
				pq.push(child);
			}else{
				indeg[child]--;
			}
		}
	}
}

int main(){
	cin>>n>>m;

	memset(indeg,0,sizeof indeg);
	REP(i,m){
		int a,b; cin>>a>>b;
		a--;b--;
		v[a].pb(b);
		indeg[b]++;
	}

	topo_sort();
	REP(i,sz(ans)){
		cout<<ans[i]+1<<" ";
	}

	return 0;
}
