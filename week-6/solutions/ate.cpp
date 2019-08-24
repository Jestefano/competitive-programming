#include<bits/stdc++.h>
using namespace std;

#define nax 100009
#define FOR(i,n,m) for(int i =(n);i<(m);i++)
#define REP(i,n) FOR(i,0,n)

typedef long long ll;

int main(){
	ll n,w,weight[101],values[101];
	ll dp[nax];
	cin>>n>>w;

	REP(i,n){
		cin>>weight[i]>>values[i];
	}

	REP(i,nax) dp[i] = 100000000000000LL;
	dp[0] = 0;

	
	REP(j,n){
		for(int i = nax-1;i>=0;i--){
			if(i-values[j]>=0){
				dp[i] = min(dp[i],
					dp[i-values[j]]+weight[j]);
			}
		}
	}

	int m = 0;

	REP(i,nax){
		if(dp[i]<=w){
			m = i;
		}
	}

	cout<<m;
	
	return 0;
}
