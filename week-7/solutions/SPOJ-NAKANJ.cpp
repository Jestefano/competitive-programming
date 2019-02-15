#include<bits/stdc++.h>
using namespace std;

#define MAX 10
#define FOR(i,n,m) for(int i = (n);i<(m);i++)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define fst first
#define snd second
#define mp make_pair

typedef vector<int> vi;
typedef pair<int,int> ii;

int t, dist[MAX][MAX];
bool vis[MAX][MAX];

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    
    //This is a classic problem of bfs in a matrix (implicit graph)
    
	cin>>t;
	REP(i,t){
		REP(x,MAX){
			REP(y,MAX){
				dist[x][y] = -1;
				vis[x][y] = false;
			}
		}
		string c1,c2;
		cin>>c1>>c2;

		dist[c1[0]-'a'][c1[1]-'1'] = 0;

		queue<ii> q;
		q.push(mp(c1[0]-'a',c1[1]-'1'));
		bool x = true;
		
		while(!q.empty() && x){
			ii u = q.front(); q.pop();
			if(vis[u.fst][u.snd]) continue;
			vis[u.fst][u.snd] = true;
			FOR(x,-2,3){
				FOR(y,-2,3){
					if(abs(x) +abs(y) !=3) continue;
					if(abs(x)==3 || abs(y) ==3) continue;
					if(x+u.fst<0 || x+u.fst>=8 ||
						y+u.snd<0 || y+u.snd>=8) continue;
					if(!vis[x+u.fst][y+u.snd]){
						vis[x+u.fst][y+u.snd];
						q.push(mp(x+u.fst,y+u.snd));
						dist[x+u.fst][y+u.snd] = dist[u.fst][u.snd] + 1;
					}
				}
			}
		}

		cout<<dist[c2[0]-'a'][c2[1]-'1']<<endl;
	}

	return 0;
}
