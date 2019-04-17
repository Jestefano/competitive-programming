#include<bits/stdc++.h>
using namespace std;

#define max_ 100
#define FOR(i,n,m) for(int i =(n);i<(m);i++)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define mp make_pair
#define fst first
#define snd second

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

bool rpta,vis[max_][max_];
char tab[max_][max_];
int n,m;

void dfs(ii node, ii parent){
	vis[node.fst][node.snd] = true;
	FOR(i,-1,2){
		FOR(j,-1,2){
			if(abs(i)+abs(j)!=1) continue;
			int x = node.fst + i, y = node.snd + j;
			if(x<0||x>=n) continue;
			if(y<0||y>=m) continue;
			
			if(x==parent.fst && y==parent.snd) continue;
			if(tab[x][y]!=tab[node.fst][node.snd]) continue;

			if(vis[x][y]){
				rpta = true;
			}else{
				dfs(mp(x,y),node);
			}
		}
	}
}

int main(){
	cin>>n>>m;

	REP(i,n){
		REP(j,m){
			cin>>tab[i][j];
		}
	}	

	rpta = false;
	memset(vis,0,sizeof vis);
	REP(i,n){
		REP(j,m){
			if(!vis[i][j]){
				dfs(mp(i,j),mp(-1,-1));
			}
		}
	}
	if(rpta){
		cout<<"Yes";
	}else cout<<"No";

	return 0;
}
