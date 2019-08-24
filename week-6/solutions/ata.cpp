#include<bits/stdc++.h>
using namespace std;

#define FOR(i,n,m) for(int i = (n);i<(m);i++)
#define REP(i,n) FOR(i,0,n)
#define nax 100009

typedef vector<int> vi;

int main(){
	int n, dp[nax];
	cin>>n;
	vi v(n);
	REP(i,n) cin>>v[i];

	memset(dp,100000000,sizeof dp);
	dp[0] = 0;
	dp[1] = abs(v[1]-v[0]);

	FOR(i,2,n){
		dp[i] = min(dp[i-1]+abs(v[i]-v[i-1]),
				dp[i-2] + abs(v[i]-v[i-2]));
	}

	cout<<dp[n-1];

	return 0;
}
