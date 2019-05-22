#include<bits/stdc++.h>
using namespace std;

#define nax 10000
#define FOR(i,n,m) for(int i =(n);i<(m);i++)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define mp make_pair
#define fst first
#define snd second

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int INF = 100000000;

int main(){
	int n; cin>>n;
	vi v(n); vii ans(n);

	REP(i,n){
		cin>>v[i];
	}

	stack<ii> s;
	int dif = n+1, dif_num = INF;
	REP(i,n){
		while(!s.empty() && v[i]<=s.top().fst){
			s.pop();
		}

		if(!s.empty()){
			ans[i] = s.top();
		}else{
			ans[i] = mp(-1,-1);
		}
		s.push(mp(v[i],i));
	}

	FOR(i,1,n){
		cout<<ans[i].fst<<" "<<ans[i].snd<<endl;
	}

	return 0;
}
