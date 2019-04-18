list<int> q;

vii v; 
int dist[max],p[max];
bool vis[max];
memset(vis,0,sizeof vis);
p[0] = -1; vis[0] = true;
dist[0] = 0;

//We could have multisource
while(!q.empty()){
	ii a = q.front();
	q.pop();
	
	for(ii u : v[a]){
		if(!vis[u.fst]){
			
			vis[u.fst] = true;
			p[u.fst] = a;

			if(u.snd){
				q.pb(u.fst);
				dist[u.fst] = dist[a] + 1;
			}else{
				q.push_front(u.fst);
				dist[u.fst] = dist[a];
			}
		}
	}
}