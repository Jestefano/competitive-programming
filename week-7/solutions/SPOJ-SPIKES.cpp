#include<bits/stdc++.h>
using namespace std;

#define MAX 45
#define FOR(i,n,m) for(int i =(n);i<(m);i++)
#define REP(i,n) FOR(i,0,n)
#define mp make_pair
#define fst first
#define snd second
#define pb push_back

typedef pair<int,int> ii;
typedef vector<ii> vi;

const int INF = 1000000;

int main(){
	char tab[MAX][MAX];
	int traps[MAX][MAX];
	int n,m,k; cin>>n>>m>>k;
	vi v;
  
  //This problem uses the idea of 0-1 bfs. There is an implicit graph in the matrix, and the edges are 0
  // if the cell is not 's', otherwise is 1. We use the treasure ('x') as source since there could
  // be multiples exit/entrance. Also if there is a place with minimum traps, that should be the entrance and exit.

	int x,y;
	REP(i,n){
		REP(j,m){
			traps[i][j] = INF;
			cin>>tab[i][j];
			if(tab[i][j] == 'x'){
				x = i; y = j;
			}
			if(tab[i][j]=='@'){
				v.pb(mp(i,j));
			}
		} 
	}

	list<ii> q;
	traps[x][y] = 0;
	q.push_front(mp(x,y));

	while(!q.empty()){
		ii u = q.front(); q.pop_front();

		FOR(i,-1,2){
			FOR(j,-1,2){
				if((abs(i) + abs(j)) !=1) continue;
				if((i+u.fst)<0 || (i+ u.fst) >=n || (j+u.snd) < 0 || (j+u.snd) >=m) continue;

				int aux = 0;
				if((tab[i+u.fst][j+u.snd]=='s')) aux++;
				
				if(tab[i+u.fst][j+u.snd] !='#' && traps[u.fst][u.snd] + aux < traps[u.fst+i][u.snd+j]){
					traps[i+u.fst][j+u.snd] = traps[u.fst][u.snd] + aux;
					
					if(aux){
						q.push_back(mp(i+u.fst,j+u.snd));
					}else{
						q.push_front(mp(i+u.fst,j+u.snd));
					}
				}
			}
		}
	}

	bool w = false;
	REP(i,v.size()){
		if(2*traps[v[i].fst][v[i].snd] <=k){
			w = true; break;
		}
	}

	if(w) cout<<"SUCCESS";
	else cout<<"IMPOSSIBLE";
	
	return 0;
}
