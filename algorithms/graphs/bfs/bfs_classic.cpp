vi v;
bool vis[MAX];
int dist[MAX], p[MAX];
queue<int> q;

memset(vis,0,sizeof vis);
vis[0] = true;
q.push(0);
p[0] = -1;
dist[0] = 0;

//We could have multisource.
while(!q.empty()){
	int aux = q.front();
	q.pop();
	for(int u:v[aux]){
		if(!vis[u]){
			vis[u] = true;
			q.push(u);
			dist[u] = dist[aux] + 1;
			p[u] = aux;
		}
	}
}