#include<bits/stdc++.h>
using namespace std;

#define nax 100009
#define FOR(i,n,m) for(int i = (n);i<(m);i++)
#define REP(i,n) FOR(i,0,n)
#define pb push_back

typedef long long ll;
typedef vector<ll> vi;

int main(){
	ll n,d; cin>>n>>d;
	vi v;

	REP(i,n){
		int a; cin>>a; v.pb(a);
	}

	ll ans = 0;
	ll l = 0, r = 1;
	while(l<n-2){
		if(r<(n-1) && (v[r]-v[l])<=d){
			if(r-l>=2){
				ans+=(r-l)*(r-l-1)/2;
			}
			r++;
		}else{
			l++;
		}
		if(r==(n-1) && (v[r]-v[l])<=d){
			if(r-l>=2){
				ans+=(r-l)*(r-l-1)/2;
			}
			break;
		}
	}

	cout<<ans<<endl;

	return 0;
}
