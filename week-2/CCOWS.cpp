#include<bits/stdc++.h>
using namespace std;

#define nax 100
#define FOR(i,n,m) for(int i =(n);i<(m);i++)
#define REP(i,n) FOR(i,0,n)
#define all(v) v.begin(), v.end()

typedef long long ll;
typedef vector<ll> vi;

int main(){
	ll c; cin>>c;

	while(c--){
		ll a,b; cin>>a>>b;
		vi v(a);
		REP(i, a) cin>>v[i];
		sort(all(v));

		ll l = 0, t = 1000000009;
		while(t-l>1){
			ll mid = l + (t-l)/2;
			//Try with mid:
			ll prev_pos = 0;
			bool pos = true;
			REP(i,b-1){
				ll p = lower_bound(all(v),v[prev_pos]+mid) - v.begin();
				if(p==a){
					pos = false;
					break;
				} 
				prev_pos = p;
			}
			if(pos){
				l = mid;
			}else{
				t = mid;
			}
		}

		cout<<l<<endl;
	}

	return 0;
}
