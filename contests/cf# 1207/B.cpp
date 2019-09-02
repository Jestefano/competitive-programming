/*
Brute force: Implement what they ask
*/
#include<bits/stdc++.h>
using namespace std;
 
#define FOR(i,n,m) for(int i = (n);i<(m);i++)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define sz(v) int(v.size())
#define nax 100
 
typedef pair<int,int> ii;
typedef vector<ii> vii;
 
int main(){
	int n,m; cin>>n>>m;
	bool a[nax][nax], b[nax][nax];
	vii v;
 
	REP(i,n){
		REP(j,m){
			cin>>a[i][j];
		}
	}
 
	memset(b,0,sizeof b);
 
	REP(i,n-1){
		REP(j,m-1){
			if(a[i][j]==1 && a[i+1][j]==1 && a[i][j+1]==1 && a[i+1][j+1]==1){
				b[i][j] = 1;
				b[i+1][j] = 1;
				b[i][j+1] = 1;
				b[i+1][j+1] = 1;
				v.pb(mp(i,j));
			}
		}
	}
 
	bool t = true;
 
	REP(i,n){
		REP(j,m){
			if(b[i][j] != a[i][j]) t = false;
		}
	}
 
	if(t){
		cout<<sz(v)<<endl;
		REP(i,sz(v)){
			cout<<v[i].fst+1<<" "<<v[i].snd+1<<endl;
		}
	}else{
		cout<<-1;
	}
 
	return 0;
}
