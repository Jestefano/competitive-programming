#include<bits/stdc++.h>
using namespace std;

#define FOR(i,n,m) for(int i =(n);i<(m);i++)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define sz(v) int(v.size())
#define mp make_pair

typedef pair<int,int> ii;

int main(){
	int n,m,k;
	set<ii> s;
	set<int> no;
	cin>>n>>m>>k;

	REP(i,m){
		int a,b; cin>>a>>b;
		a--;b--;
		s.insert(mp(a,b));
		s.insert(mp(b,a));
	}
	REP(i,n) no.insert(i);

	bool con = true;
	queue<int> q; q.push(0);
	no.erase(0);

	while(!q.empty()){
		int aux = q.front();
		q.pop();
		vector<int> elim;
		for(auto it = no.begin();it!=no.end();it++){
			if(!s.count(mp(aux,*it))){
				q.push(*it);
				elim.pb(*it);
			}
		}
		REP(i,sz(elim)){
			no.erase(elim[i]);
		}
	}

	if(sz(no)!=0){
		con = false;
	}

	int m_ = 0, ms=0;
	if(con){
		//Connected components:

		FOR(i,1,n) no.insert(i);

		while(!no.empty()){
			int aux = *no.begin();
			no.erase(aux);
			q.push(aux);
			m_++;
			while(!q.empty()){
				aux = q.front();
				
				q.pop();
				vector<int> el;
				for(auto it = no.begin();it != no.end();it++){
					if(!s.count(mp(*it,aux))){
						el.pb(*it);
						q.push(*it);
					}
				}
				REP(i,sz(el)){
					no.erase(el[i]);
				}
			}
		}

		for(auto it = s.begin();it!=s.end();it++){
			if(it->first == 0)ms++;
		}

		if(k>=m_ && k<=(n-ms-1)){
			cout<<"possible";
		}else{
			cout<<"impossible";
		}
	}else{
		cout<<"impossible";
	}

	return 0;
}
