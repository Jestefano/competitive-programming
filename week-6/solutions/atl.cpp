/*
Given the two states (i,j) how can we locally maximize or minimize 
the objective function
*/
#include<bits/stdc++.h>
using namespace std;

#define nax 3009
#define FOR(i,n,m) for(int i=(n);i<(m);i++)
#define REP(i,n) FOR(i,0,n)

typedef long long ll;
typedef vector<ll> vi;

ll dp[nax][nax][2], n;
bool vis[nax][nax][2];
vi v;

ll f(int l = 0, int t = n-1,int k =0){

	if(l==t) return (k==0)?v[l]:-v[l];
	
	if(vis[l][t][k]) return dp[l][t][k];
	vis[l][t][k] = 1;
	
	if(k==0){
		return dp[l][t][k] = max(f(l+1,t,1-k)+v[l],
								f(l,t-1,1-k)+v[t]);
	}else{
		return dp[l][t][k] = min(f(l+1,t,1-k)-v[l],
								f(l,t-1,1-k)-v[t]);
	}
}

int main(){
	cin>>n;
	v.resize(n);
	REP(i,n) cin>> v[i];

	memset(vis,0,sizeof vis);
	memset(dp,0LL,sizeof dp);
	cout<<f()<<endl;

	return 0;
}
