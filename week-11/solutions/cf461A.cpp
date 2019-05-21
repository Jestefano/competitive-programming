#include<bits/stdc++.h>
using namespace std;

#define nax 300009
#define FOR(i,n,m) for(int i=(n);i<(m);i++)
#define REP(i,n) FOR(i,0,n)
#define pb push_back

typedef long long ll;
typedef vector<ll> vi;

int main(){
	int n; cin>>n;
	vi v(n);
	REP(i,n) cin>>v[i];
	
	sort(v.begin(),v.end());

	ll s = 0, c = 2;
	REP(i,n-1){
		s+=(v[i]*c);
		c++;
	}
	s+=v[n-1]*(c-1);

	cout<<s<<endl;

	return 0;
}
