#include<bits/stdc++.h>
using namespace std;

#define nax 3009
#define FOR(i,n,m) for(int i =(n);i<(m);i++)
#define REP(i,n) FOR(i,0,n)

typedef vector<int> vi;

int main(){
	string a,b;
	int dp[nax][nax];

	cin>>a>>b;

	REP(i,nax){
		dp[i][0] = 0;
		dp[0][i] = 0;
	}

	int n = int(a.size()), m = int(b.size());
	FOR(i,1,n+1){
		FOR(j,1,m+1){
			if(a[i-1]==b[j-1]){
				dp[i][j] = max(dp[i-1][j-1]+1,
					max(dp[i-1][j],dp[i][j-1]));
			}else{
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}

	string ans;
	int i = n,j = m;
	while(i>0&&j>0){
		if(dp[i][j]==(dp[i-1][j-1]+1)&&(a[i-1]==b[j-1])){
			ans = ans+a[i-1];
			i = i-1;
			j = j-1;
		}else if(dp[i-1][j]==dp[i][j]){
			i = i-1;
		}else{
			j = j-1;
		}
	}
	reverse(ans.begin(),ans.end());

	cout<<ans;

	return 0;
}
