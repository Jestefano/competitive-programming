/*
Open the recursive formula
*/
#include<bits/stdc++.h>
using namespace std;

#define nax 100009
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
	ll t; cin>>t;

	while(t--){
		ll a,b,n; cin>>a>>b>>n;
		ll c = a^b;
		if(n%3==0) cout<<a<<endl;
		else if(n%3==1) cout<<b<<endl;
		else cout<<c<<endl;
	}

	return 0;
}
