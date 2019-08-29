#include<bits/stdc++.h>
using namespace std;

#define nax 1009
#define FOR(i,n,m) for(int i =(n);i<(m);i++)
#define REP(i,n) FOR(i,0,n)
#define all(v) v.begin(),v.end()

typedef long long ll;
typedef vector<int> vi;

int main(){
	char tab[nax][nax];
	ll dp[nax][nax];
	int h, w; cin>>h>>w;

	ll mod = 1000000007LL;

	REP(i,h){
		REP(j,w){
			cin>>tab[i][j];
		}
	}

	memset(dp,0LL,sizeof dp);
	dp[0][0]=1;
	REP(i,h){
		REP(j,w){
			if(i==0&& j==0) continue;
			if(tab[i][j]=='#') continue;
			if(i==0){
				dp[i][j] = dp[i][j-1];
			}else if(j==0){
				dp[i][j] = dp[i-1][j];
			}else{
				dp[i][j] = (dp[i][j-1]+dp[i-1][j])%mod;
			}
		}
	}

	cout<<dp[h-1][w-1]%mod;
	
	return 0;
}
