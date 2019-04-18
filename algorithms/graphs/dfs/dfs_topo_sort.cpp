
vi v;
int vis[max];
int p[max];
//initialize!
vi topo_sort;

bool dfs(int u = 0){
	for(int i:v[u]){
		if(!vis[i]){
			vis[i] = 1;
			p[i] = u;
			dfs(i);
		}else if(vis[i]==1){
			//There is a backedge! -> There is no toposort
		}
	}
	vis[i] = 2;
	topo_sort.pb(u);
}

bool dfs_(int n){
	REP(i,n){
		if(!vis[i])dfs(i);
	}
}

// In main
reverse(all(topo_sort));
// There exists a topo_sort iff it is a DAG