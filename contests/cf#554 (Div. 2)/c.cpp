#include<bits/stdc++.h>
using namespace std;

#define nax 21
#define FOR(i,n,m) for(int i =(n);i<(m);i++)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define mp make_pair
#define fst first
#define snd second

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;

int main(){
	ll a,b;
	cin>>a>>b;
	long long x = min(a,b), y = max(a,b);

	if(x==y){
		cout<<0;
		return 0;
	}
	//y>x
	vi v;
	vi divi;
	for(ll i = 1;i*i<=(y-x);i++){
		if((y-x)%i==0){
			divi.pb(i);
			divi.pb((y-x)/i);
		}
	}

	ll ans = 0,val_act=1000000000000000000LL;
	REP(i,divi.size()){
		ll w = x/divi[i];
		ll k = divi[i]*w - x;
		while(1){
			if(k<0||__gcd(w,(y-x)/divi[i])!=1){
				w++;
				k+=divi[i];
			} else break;
		}
		
		//cout<<((x+k))*(y+k)/divi[i]<<" "<<k<<endl;
		//cout<<((x+k))*(y+k)/divi[i]<<endl;
		if ((((x+k)/divi[i])*(y+k)) < (val_act)){
			val_act = ((x+k)/divi[i])*(y+k);
			 ans = k;
		}else if((((x+k)/divi[i])*(y+k)) == (val_act)){
			ans = min(ans,k);
		}
	}
	
	cout<<ans;

	return 0;
}
