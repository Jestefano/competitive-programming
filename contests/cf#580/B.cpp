/*
Greedy: Minimum distance to 1 or -1
If you have an option (0) the answer is the sum 
Otherwise, check if the product is 1 or not.
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
	int n; cin>>n;
	vi v(n);
 
	REP(i,n) cin>>v[i];
 
	bool w = false;
	ll tot = 0;
	int ans = 1;
	REP(i,n){
		if(abs(v[i]-1)<abs(v[i]+1)){
			tot+= abs(v[i]-1);
		}else if(abs(v[i]-1)>abs(v[i]+1)){
			tot+=abs(v[i]+1);
			ans*=(-1);
		}else{
			tot+=abs(v[i]+1);
			w = true;
		}
	}
	if(w) cout<<tot;
	else if(ans==1){
		cout<<tot;
	}else cout<<tot+2;
 
 
	return 0;
}
