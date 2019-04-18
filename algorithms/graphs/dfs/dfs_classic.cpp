vi v;
bool vis[max];
int p[max];
//initialize!

bool dfs(int u = 0){
	for(int i:v[u]){
		if(!vis[i]){
			vis[i] = true;
			p[i] = u;
			dfs(i);
		}
	}
}