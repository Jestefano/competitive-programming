#include<bits/stdc++.h>
using namespace std;

#define MAX 109
#define FOR(i,n,m) for(int i = (n);i<(m);i++)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define fst first
#define snd second
#define mp make_pair

typedef pair<int,int> ii;
typedef long long ll;

int main(){
	int tab[MAX][MAX], n, m, dp[MAX][MAX];
	int t; bool vis[MAX][MAX];
	cin>>t;

	while(t--){
		memset(tab,0,sizeof tab);
		cin>>n>>m;

		REP(i,n){
			REP(j,m){
				cin>>tab[i][j];
				dp[i][j] = tab[i][j];
			}
		}

		FOR(k,1,10001){
			memset(vis,false,sizeof vis);
			//Primera coordenada
			REP(i,n){
				if(!vis[i][0] && tab[i][0]<k){
					queue<ii> q;
					vis[i][0] = true;
					q.push(mp(i,0));
					while(!q.empty()){
						ii u = q.front(); q.pop();
						FOR(x,-1,2){
							FOR(y,-1,2){
								if(abs(x) + abs(y)!=1) continue;
								if(x+u.fst <0 || x+u.fst>=n || y + u.snd<0 || y + u.snd>=m){
									continue;
								}
								//<k para que el agua salga!
								if(!vis[x+u.fst][y+u.snd] && tab[x+u.fst][y+u.snd]<k){
									vis[x+u.fst][y+u.snd] = true;
									q.push(mp(x+u.fst,y+u.snd));
								}
							}
						}
					}
				}
			}
			//Segunda coordenada
			REP(i,m){
				if(!vis[0][i]&& tab[0][i] <k){
					queue<ii> q;
					vis[0][i] = true;
					q.push(mp(0,i));
					while(!q.empty()){
						ii u = q.front(); q.pop();
						FOR(x,-1,2){
							FOR(y,-1,2){
								if(abs(x) + abs(y)!=1) continue;
								if(x+u.fst <0 || x+u.fst>=n || y + u.snd<0 || y + u.snd>=m){
									continue;
								}
								//<k para que el agua salga!
								if(!vis[x+u.fst][y+u.snd] && tab[x+u.fst][y+u.snd]<k){
									vis[x+u.fst][y+u.snd] = true;
									q.push(mp(x+u.fst,y+u.snd));
								}
							}
						}
					}
				}
			}	
			REP(i,m){
				if(!vis[n-1][i]&& tab[n-1][i] <k){
					queue<ii> q;
					vis[n-1][i] = true;
					q.push(mp(n-1,i));
					while(!q.empty()){
						ii u = q.front(); q.pop();
						FOR(x,-1,2){
							FOR(y,-1,2){
								if(abs(x) + abs(y)!=1) continue;
								if(x+u.fst <0 || x+u.fst>=n || y + u.snd<0 || y + u.snd>=m){
									continue;
								}
								//<k para que el agua salga!
								if(!vis[x+u.fst][y+u.snd] && tab[x+u.fst][y+u.snd]<k){
									vis[x+u.fst][y+u.snd] = true;
									q.push(mp(x+u.fst,y+u.snd));
								}
							}
						}
					}
				}
			}	
			REP(i,n){
				if(!vis[i][m-1]&& tab[i][m-1] <k){
					queue<ii> q;
					vis[i][m-1] = true;
					q.push(mp(i,m-1));
					while(!q.empty()){
						ii u = q.front(); q.pop();
						FOR(x,-1,2){
							FOR(y,-1,2){
								if(abs(x) + abs(y)!=1) continue;
								if(x+u.fst <0 || x+u.fst>=n || y + u.snd<0 || y + u.snd>=m){
									continue;
								}
								//<k para que el agua salga!
								if(!vis[x+u.fst][y+u.snd] && tab[x+u.fst][y+u.snd]<k){
									vis[x+u.fst][y+u.snd] = true;
									q.push(mp(x+u.fst,y+u.snd));
								}
							}
						}
					}
				}
			}	
			//Los demas:
			REP(i,n){
				REP(j,m){
					if(!vis[i][j]){
						dp[i][j] = max(dp[i][j],k);
					}
				}
			}
		}

		ll rpta = 0;
		REP(i,n){
			REP(j,m){
				rpta+= dp[i][j] - tab[i][j];
			}
		}
		cout<<rpta<<endl;
	}

	return 0;
}
