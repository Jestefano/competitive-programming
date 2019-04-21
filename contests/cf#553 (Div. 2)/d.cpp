#include<bits/stdc++.h>
using namespace std;

#define nax 100009
#define FOR(i,n,m) for(int i =(n);i<(m);i++)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define all(v) v.begin(),v.end()
#define mp make_pair
#define fst first
#define snd second

vector<long long> v;
vector<pair<long long,long long> > vv;
int main(){
	long long n; cin>>n;
	REP(i,n){
		int a,b; cin>>a>>b;
		vv.pb(mp(a,b));
		v.pb(a-b);
	}

	sort(all(v));
	long long s= 0;
	REP(i,n){
		s+=v[n-i-1]*(i+1) - vv[n-1-i].fst + n*(vv[n-i-1].snd);
	}

	cout<<s;

	return 0;
}
