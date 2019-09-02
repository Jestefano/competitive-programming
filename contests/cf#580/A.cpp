/*
Greedy: Choose the two biggest numbers
*/

#include<bits/stdc++.h>
using namespace std;
 
#define nax 1000
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
 
int main(){
	int n,m; cin>>n;
	vi v1(n);
	REP(i,n) cin>>v1[i];
	cin>>m;
	vi v2(m);
	REP(i,m) cin>>v2[i];
 
	sort(all(v1));
	sort(all(v2));
	cout<<v1[n-1]<<" "<<v2[m-1];
 
	return 0;
}
