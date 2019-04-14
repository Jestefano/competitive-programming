#include<bits/stdc++.h>
using namespace std;

#define FOR(i,n,m) for(int i =(n);i<(m);i++)
#define REP(i,n) FOR(i,0,n)
#define max 1009
#define pb push_back
#define mp make_pair
#define sz(v) int(v.size())
#define fst first
#define snd second

typedef pair<int,int> ii;
typedef vector<int> vi;

int main(){
	int n,m,k;
	char tab[max][max];
	cin>>n>>m>>k;

	int a,b;
	REP(i,n){
		REP(j,m){
			cin>>tab[i][j];
			if(tab[i][j]=='X'){
				a = i; b = j;
			}
		}
	}

	if(k%2!=0){
		cout<<"IMPOSSIBLE";
		return 0;
	}

	//First we are going to make the bfs:
	int dist[max][max];
	bool vis[max][max];
	
	memset(dist,-1,sizeof dist);
	memset(vis,0,sizeof vis);

	queue<ii> q;
	dist[a][b] = 0;
	vis[a][b] = 1;
	q.push(mp(a,b));

	bool imp = true;
	while(!q.empty()){
		ii aux = q.front(); q.pop();
		FOR(i,-1,2){
			FOR(j,-1,2){
				if(abs(i)+abs(j)!=1) continue;
				int x = aux.fst + i, y = aux.snd+j;
				if(x<0||x>=n) continue;
				if(y<0||y>=m) continue;

				if(tab[x][y]=='*') continue;
				if(vis[x][y]) continue;

				vis[x][y] = true;
				dist[x][y] = dist[aux.fst][aux.snd] + 1;

				imp = false;
				q.push(mp(x,y));
			}
		}
	}

	if(imp){
		cout<<"IMPOSSIBLE";
		return 0;
	}

	vi v;
	int xa = a, ya = b;
	REP(w,k){
		int rot[4][2] = {{1,0},{0,-1},{0,1},{-1,0}};
		REP(pos,4){
			int x = xa + rot[pos][0], y = ya + rot[pos][1];
			if(x<0||x>=n) continue;
			if(y<0||y>=m) continue;
			
			if(dist[x][y]<k-w && tab[x][y]!='*'){
				xa = x;ya = y;
				v.pb(pos);
				break;
			}	
		}
	}

	REP(i,v.size()){
		if(v[i]==0) cout<<"D";
		if(v[i]==1) cout<<"L";
		if(v[i]==2) cout<<"R";
		if(v[i]==3) cout<<"U";
	}

	return 0;
}
