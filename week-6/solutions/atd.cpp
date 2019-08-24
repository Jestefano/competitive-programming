#include<bits/stdc++.h>
using namespace std;

#define nax 100009
#define FOR(i,n,m) for(int i =(n);i<(m);i++)
#define REP(i,n) FOR(i,0,n)
#define pb push_back

typedef long long ll;

int main(){
	ll n,w[200],val[200],dp[nax],we;
	cin>>n>>we;

	REP(i,n){
		cin>>w[i]>>val[i];
	}

	REP(i,nax) dp[i] = 0;

	REP(i,n){
		for(int j=we;j>=0;j--){
			if(j-w[i]>=0){
				dp[j] = max(dp[j],
					dp[j-w[i]]+val[i]);
			}
		}
	}

	ll m = 0;
	REP(i,we+1){
		m = max(m,dp[i]);
	}

	cout<<m<<endl;

	return 0;
}
