/*
Think each of the number as binary numbers. If we have 3 or more 1's in a column
Then the answer is 3. Otherwise, we have all the degrees <= 2. With this we can run
BFS per node in order to find the smallest cycle.
*/

#include<bits/stdc++.h>
using namespace std;
 
#define nax 100009
#define FOR(i,n,m) for(ll i =(n);i<(m);i++)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define fst first
#define snd second
#define mp make_pair
#define sz(v) int(v.size())
#define all(v) v.begin() , v.end()
 
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
 
int main(){
	int n; cin>>n;
 
	vi v[nax];
	vii nums(n);
	REP(i,n){
		ll aux;
		cin>>aux;
		nums[i] = mp(i,aux);
	}
 
	set<ll> verif[nax];
	
	ll aux = 1;
	REP(i,60){
		vi pos;
		int cant = 0;
		REP(j,n){
			if((nums[j].second & aux)){
				cant++;
				pos.pb(nums[j].fst);
			}
		
		}
		aux*=2;
		
		if(cant>=3){
			cout<<3;
			return 0;
		}
		if(sz(pos)==2){
			if(!verif[pos[0]].count(pos[1])){
				verif[pos[0]].insert(pos[1]);
				v[pos[0]].pb(pos[1]);
			}
			
			if(!verif[pos[1]].count(pos[0])){
				verif[pos[1]].insert(pos[0]);
				v[pos[1]].pb(pos[0]);
			}
		}
	}
 
	//bfs en v:
 
	int ans = n+1;
	int d[nax], p[nax];
	REP(i,n){
		queue<int> q;
		set<int> vis;
		
		q.push(i);
		d[i] = 0;
		p[i] = -1;
		bool term = false;
		
		while(!q.empty()){
			int w = q.front();
			vis.insert(w);
			q.pop();
			for(int u:v[w]){
				if(p[w]==u) continue;
				if(vis.count(u)){
					ans = min(ans,d[w]+d[u]+1);
					term = true;
					break;
				}else{
					q.push(u);
					p[u] = w;
					d[u] = d[w]+1;
				}
			}
			if(term) break;
		}
	}
 
/*	REP(i,n) cout<<d[i]<<endl;*/
 
 
	if(ans!=n+1){
		cout<<ans;
	}else cout<<-1;
 
	return 0;
}
