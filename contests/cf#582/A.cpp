/*
You have to notice that for this problem what we really care about is the parity
this is the case because the cost only relies on the changes in 1's
*/
#include<bits/stdc++.h>
using namespace std;

#define nax 3009
#define FOR(i,n,m) for(int i=(n);i<(m);i++)
#define REP(i,n) FOR(i,0,n)
#define mp make_pair
#define fst first
#define snd second
#define pb push_back
#define sz(v) int(v.size())
#define all(v) v.begin(),v.end()

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;

int main(){
	int n; cin>>n;
	vi v(n);
	REP(i,n) cin>>v[i];

	int par =0, impar = 0;
	REP(i,n){
		if(v[i]%2==0) par++;
		else impar++;
	}

	cout<<min(par,impar);


	return 0;
}
