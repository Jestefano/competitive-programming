/*
DP
*/
#include<bits/stdc++.h>
using namespace std;
 
#define nax 200009
#define FOR(i,n,m) for(int i = (n);i<(m);i++)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define fst first
#define snd second
#define mp make_pair
#define sz(v) int(v.size())
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
 
int main(){
	ll t,n,a,b;cin>>t;
	string s;
	ll dp[nax][2];
 
	while(t--){
		cin>>n>>b>>a;
		cin>>s;
 
		dp[0][0] = a;
		dp[0][1] = 10000000000000000LL;
		FOR(i,1,n){
			//a->pilar
			//b->gaseducto
			if(s[i]-'0'==1||s[i-1]-'0'==1){
				dp[i][1] = min(dp[i-1][1]+2*a+b,dp[i-1][0]+2*a+2*b);
				dp[i][0] = 10000000000000000LL;
			}else{
				dp[i][0] = min(dp[i-1][1]+a+2*b,dp[i-1][0]+a+b);
				dp[i][1] = min(dp[i-1][1]+2*a+b,dp[i-1][0]+2*a+2*b);
			}
		}
		/*REP(i,n){
			REP(j,2){
				cout<<dp[i][j]<<" ";
			}
			cout<<endl;
		}*/
 
		cout<<min(dp[n-1][1]+a+2*b,dp[n-1][0]+a+b)<<endl;
	}	
 
	return 0;
}
