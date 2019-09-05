/*
The solution is greedy by the argument: rep(a_i)<=k & sum(a_i)>=3k ->
we can follow the solution
*/
#include<bits/stdc++.h>
using namespace std;

#define nax 100
#define FOR(i,n,m) for(int i =(n);i<(m);i++)
#define REP(i,n) FOR(i,0,n)
#define all(v) v.begin(), v.end()
#define sz(v) int(v.size())
#define fst first
#define snd second
#define mp make_pair
#define pb push_back

typedef pair<int,int> ii;
typedef vector<int> vi;

int main(){
	int n; cin>>n;
	map<int,int> m;
	REP(i,n){
		int a; cin>>a;
		m[a]++;
	}

	set<ii> s;
	for(map<int,int>::iterator it = m.begin();it!=m.end();it++){
		s.insert(mp(it->snd,it->fst));
	}

	vector<pair<pair<int,int>, int> > v;
	int cont = 0;
	while(sz(s)>=3){
		auto it1 = s.rbegin();
		auto it2 = s.rbegin();
		it2++;
		auto it3 = s.rbegin();
		it3++;
		it3++;
		ii aux1 = *it1, aux2 = *it2, aux3 = *it3;
		s.erase(aux1);
		s.erase(aux2);
		s.erase(aux3);
		aux1 = mp(aux1.fst-1,aux1.snd);
		aux2 = mp(aux2.fst-1,aux2.snd);
		aux3 = mp(aux3.fst-1,aux3.snd);

		if(aux1.fst!=0){
			s.insert(aux1);
		} 
		if(aux2.fst!=0){
			s.insert(aux2);
		}
		if(aux3.fst!=0){
			s.insert(aux3);
		}
		cont++;
		vi w;
		w.pb(aux1.snd);
		w.pb(aux2.snd);
		w.pb(aux3.snd);
		sort(all(w));
		v.pb(mp(mp(w[2],w[1]),w[0]));
	}

	cout<<cont<<endl;
	REP(i,cont){
		cout<<v[i].fst.fst<<" "<<v[i].fst.snd<<" "<<v[i].snd<<endl;
	}

	return 0;
}
