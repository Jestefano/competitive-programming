#include<bits/stdc++.h>
using namespace std;

#define nax 100009
#define FOR(i,n,m) for(int i =(n);i<(m);i++)
#define REP(i,n) FOR(i,0,n)
#define pb push_back

typedef long long ll; 
typedef vector<ll> vi;

int main(){
	ll n,k, dp[nax]; cin>>n>>k;
	vi v(n);

	REP(i,n) cin>>v[i];
	REP(i,n) dp[i] = 1000000000000LL;
	dp[0] = 0;

	REP(i,n){
		FOR(j,1,k+1){
			if(i+j>=n) break;
			dp[i+j] = min(dp[i]+abs(v[i]-v[i+j]),
						dp[i+j]);
		}
	}

	cout<<dp[n-1];

	return 0;
}
