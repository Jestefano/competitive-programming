#include<bits/stdc++.h>
using namespace std;

#define FOR(i,n,m) for(int i =(n);i<(m);i++)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define maxx 2009

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<int,int> vii;

vi v[maxx];
bool vis[maxx], color[maxx];

int main(){
	int n; cin>>n;

	REP(j,n){
		int a,b; cin>>a>>b;
		REP(i,a){
			v[i].clear();
		}
		REP(i,b){
			int c,d; cin>>c>>d;
			c--;d--;
			v[c].pb(d); v[d].pb(c);
		}

		memset(vis,0,sizeof vis);
		queue<int> q;
		bool rpta = true;
		REP(i,a){
			if(!vis[i]){
				q.push(i);
				vis[i] = true;
				color[i] = true;
				while(!q.empty()){
					int aux = q.front();
					q.pop();
					for(int child: v[aux]){
						if(vis[child]){
							if(color[child]==color[aux]){
								rpta = false;
							}
						}else{
							vis[child] = true;
							color[child] = !color[aux];
							q.push(child);
						}
					}
				}
			}
		}

		cout<<"Scenario #"<<j+1<<":"<<endl;
		if(rpta){
			cout<<"No suspicious bugs found!"<<endl;
		}else{
			cout<<"Suspicious bugs found!"<<endl;
		}
	}

	return 0;
}
