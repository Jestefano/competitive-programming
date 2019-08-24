#include<bits/stdc++.h>
using namespace std;

#define nax 100009
#define FOR(i,n,m) for(int i =(n);i<(m);i++)
#define REP(i,n) FOR(i,0,n)
#define pb push_back

typedef vector<int> vi;

int main(){
	int n; cin>>n;
	int a[nax][3],dp[nax][3];

	REP(i,n){
		REP(j,3) cin>>a[i][j];
	}

	REP(i,3) dp[0][i] = a[0][i];

	FOR(i,1,n){
		REP(j,3){
			dp[i][j] = max(dp[i-1][(j+1)%3]+a[i][j],
							dp[i-1][(j+2)%3]+a[i][j]);
		}
	}

	int m = 0;
	REP(i,3) m = max(dp[n-1][i],m);

	cout<<m;

	return 0;
}
