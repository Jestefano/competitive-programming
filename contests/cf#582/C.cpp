/*
We can easily realize that we need an O(1) (or almost O(1)) solution to this problem
Because of that you should start searching for a formula.

Think about the pidgeon-hole principle. The numbers have to repeat in a cyclic-manner
at some point. So, since we know that there are only ten numbers of 1 digit, let's focus on that.
Finally, add the remainder points.

*/
#include<bits/stdc++.h>
using namespace std;

#define nax 1000
#define FOR(i,n,m) for(ll i =(n);i<(m);i++)
#define REP(i,n) FOR(i,0,n)

typedef unsigned long long ll;
typedef vector<ll> vi;

int main(){
	int t; cin>>t;

	while(t--){
		ll n,m; cin>>n>>m;
		ll k = n/m;

		ll ans = 0;
		FOR(i,1,11){
			ans+=(i*m)%10LL;
		}
		ans*=(k/10);
		FOR(i,1,k%10+1){
			ans+=(i*m)%10LL;
		}

		cout<<ans<<endl;
	}
	
	return 0;
}
