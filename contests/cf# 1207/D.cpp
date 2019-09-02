/*
Learn to count the number of ways using permutations.
And count the intersection respecting the fact that it has to be ordered.
*/
#include<bits/stdc++.h>
using namespace std;
 
#define FOR(i,n,m) for(int i = (n);i<(m);i++)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define sz(v) int(v.size())
#define nax 300009
#define all(v) v.begin(), v.end()
 
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
typedef vector<ll> vi;
 
vii v;
vi vec_;
ll fact[nax],n;
 
ll func(ll a, ll b, ll param){
	ll w = a;
	ll prod1 = 1;
	while(w<b){
		ll k = w, cont = 0;
		if(param==0){
			while(k<b && v[w].fst==v[k].fst){
				cont++; k++;
			}
		}else{
			while(k<b && v[w].snd==v[k].snd){
				cont++; k++;
			}
		}
		vec_.pb(k);
		
		if(param<=1){	
			prod1 = (prod1*fact[cont])%998244353;	
		}else{
			prod1 = (prod1*fact[cont])%998244353;	
		}
		w = k;
	}
	
	return prod1;
}
 
bool comp2(ii a, ii b){
	return a.snd > b.snd;
}
 
int main(){
	fact[0] = fact[1] = 1;
	FOR(i,2,nax){
		fact[i] = (fact[i-1]*i)%998244353;
	}
 
	cin>>n;
	v.resize(n);
 
	REP(i,n) cin>>v[i].fst>>v[i].snd;
 
	sort(all(v));
	ll aux = func(0, n, 0);
	//
	//cout<<aux<<endl;
 
	int w = 0, rpta = 1;
	ll min1,min2,max1 = -1,max2;
	
	REP(i,sz(vec_)){
		rpta = (rpta*func(w, vec_[i], 2))%998244353;
		
		min2 = n+1; max2 = -1;
		while(w<vec_[i]){
			min2 = min(min2,v[w].snd);
			max2 = max(max2,v[w].snd);
			w++;
		}
		if(min2<max1){
			rpta = 0;
		}
		min1 = min2;
		max1 = max2;
	}
 
	aux=(aux-rpta+998244353)%998244353;
	//cout<<rpta<<endl;
 
	sort(all(v),comp2);
	aux=(aux+func(0,n,1))%998244353;
	//cout<<func(0,n,1)<<endl;
	
	ll ans = (fact[n]+998244353-aux)%998244353;
	
	cout<<ans;
 
	return 0;
}
