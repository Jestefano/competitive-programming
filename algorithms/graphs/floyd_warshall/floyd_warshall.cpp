#include<bits/stdc++.h>
using namespace std;

#define nax 100
#define FOR(i,n,m) for(int i =(n);i<(m);i++)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define sz(v) int(v.size())
#define all(v) v.begin(),v.end()

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	//Floyd-Warshall:
	int tab[nax][nax],p[nax][nax];
	int n; cin>>n;
	int INF = 100000000;

	REP(i,n){
		REP(j,n){
			cin>>tab[i][j];
			if(tab[i][j]==0){
				//There is no edge:
				tab[i][j] = INF;
				p[i][j] = -1;
			}else p[i][j] = j;
		}
	}

	REP(k,n){
		REP(i,n){
			REP(j,n){
				if(tab[i][k]==INF) continue;
				if(tab[k][j]==INF) continue;
				if(tab[i][k]+tab[k][j]<tab[i][j]){
					tab[i][j] = tab[i][k] + tab[k][j];
					p[i][j] = p[i][k];
				}

			}
		}
	}

	bool neg_cycle = false;
	REP(k,n){
		REP(i,n){
			REP(j,n){
				if(tab[i][k]==INF) continue;
				if(tab[k][j]==INF) continue;
				if(tab[i][k]+tab[k][j]<tab[i][j]){
					neg_cycle = true;
				}
			}
		}
	}

	return 0;
}
