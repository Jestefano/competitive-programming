/*
Think the problem backwards: Given that you are in a position, is it possible to win?
That means that you are able to send the other person to a lose position
*/
#include<bits/stdc++.h>
using namespace std;

#define nax 100009
#define FOR(i,n,m) for(int i=(n);i<(m);i++)
#define REP(i,n) FOR(i,0,n)

typedef vector<int> vi;

int main(){
	int n,k; cin>>n>>k;
	vi v(n);
	REP(i,n) cin>>v[i];

	bool dp[nax];
	dp[0] = false;//lose

	FOR(i,1,k+1){
		dp[i] = false;
		REP(j,n){
			if(i-v[j]<0) continue;
			if(!dp[i-v[j]]) dp[i] = 1;
		}
	}

	if(dp[k]) cout<<"First";
	else cout<<"Second";

	return 0;
}
