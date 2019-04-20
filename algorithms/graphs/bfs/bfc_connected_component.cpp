#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m; cin>>n>>m;
	REP(i,n){
		int a,b; cin>>a>>b;
		a--;b--;
		v[a].pb(b);
		v[b].pb(a);
	}

	memset(vis,0,sizeof vis);
	int con_comp = 0;
	queue<int> q;
	REP(i,n){
		if(!vis[i]){
			color[i] = con_comp++;
			q.push(i);
			vis[i] = true;
			while(!q.empty()){
				int node = q.front();
				for(int child: v[node]){
					if(!vis[child]){
						q.push(child);
						vis[child] = true;
						color[child] = color[node];
					}
				}
			}
		}
	}


	return 0;
}
