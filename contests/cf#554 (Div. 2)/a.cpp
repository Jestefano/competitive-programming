#include<bits/stdc++.h>
using namespace std;

#define nax 300009
#define FOR(i,n,m) for(int i =(n);i<(m);i++)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define mp make_pair
#define fst first
#define snd second

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;

int main(){
	ll n,m; cin>>n>>m;
	vi a,b;
	ll p1=0,p2=0;
	REP(i,n){
		ll aux; cin>>aux;
		if(aux%2==0) p1++;
	}
	REP(i,m){
		ll aux; cin>>aux;
		if(aux%2==0) p2++;
	}
	cout<< min(p1,m-p2) + min(n-p1,p2);

	return 0;
}
