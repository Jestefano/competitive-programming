/*
https://vjudge.net/contest/322571#problem/B
Count the number of connected components
*/
#include <iostream>
#include<cstring>
using namespace std;

#define nax 109
#define FOR(i,n,m) for(int i = (n);i<(m);i++)
#define REP(i,n) FOR(i,0,n)

typedef long long ll;

int c= 1,n,m;
int vis[nax][nax];
char tab[nax][nax];

void dfs(int a, int b){
	vis[a][b] = c;
	FOR(i,-1,2){
		FOR(j,-1,2){
			if(a+i<0 || a+i>=n || b+j<0 || b+j>=m)
				continue;
			if(vis[a+i][b+j]) continue;
			if(tab[a+i][b+j] == '.') continue;
			dfs(a+i,b+j);
		}
	}
}

void dfs_(){
	memset(vis,0,sizeof vis);
	c = 1;
	REP(i,n){
		REP(j,m){
			if(!vis[i][j] && tab[i][j]=='W'){
				c++;
				dfs(i,j);
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
	dfs_();

	cout<<c-1;

	return 0;
}
