#include<bits/stdc++.h>
using namespace std;

#define nax 3005
#define FOR(i,n,m) for(int i =(n);i<(m);i++)
#define REP(i,n) FOR(i,0,n)
#define all(v) v.begin(),v.end()

typedef long long ll;
typedef vector<int> vi;

int n;
double dp[nax][nax];

int main(){
	cin>>n;
	vector<double> p(n);

	REP(i,n){
		cin>>p[i];
	}
	
	memset(dp,0,sizeof dp);
	dp[0][0] = p[0];
	FOR(i,1,n){
		REP(j,n){
			dp[i][j] = dp[i-1][j]*(1-p[i]);
			if(j>0) dp[i][j] += dp[i-1][j-1]*p[i];
			else dp[i][j] +=p[i];
		}
	}

	printf("%.10f",dp[n-1][n/2]);
  /*Use conditional probability*/
	
	return 0;
}
