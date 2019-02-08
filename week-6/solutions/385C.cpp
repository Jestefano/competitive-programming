#include<bits/stdc++.h>
using namespace std;

#define MAX 10000003
#define FOR(i,n,m) for(int i = (n);i<(m);i++)
#define REP(i,n) FOR(i,0,n)

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int criba[MAX],val[MAX];
	ll s[MAX];
	unordered_map<ll,int> p;
	
  //This is a classic sieve, I was just testing whether it made a difference 
  //to have this little changes in the runtime
	criba[1] = 1; criba[2] = 2;
	for(ll i = 3; i < MAX; i+=2)
		criba[i] = i;
	for(ll i = 4; i < MAX; i+=2) 
		criba[i] = 2;

	for(ll i = 3; i < MAX;i+=2){
		if(criba[i]!=i) continue;
		for(ll j = i*i; j < MAX; j+=i){
			criba[j] = i;
		}
	}

	memset(val,0,sizeof val);
	int n; cin>>n;
	REP(i,n){
		int aux; cin>>aux;
		while(aux!=1){
			int k = criba[aux];
			while(aux%k==0) aux/=k;
			val[k]++;
		}
	}

	s[0] = 0;
	FOR(i,1,MAX) s[i] = s[i-1] + val[i]; 
	
	int m; cin>>m;
	REP(i,m){
		ll a,b; cin>>a>>b;
		if(b>10000000 && a>10000000) cout<<0<<endl;
		else if(b>10000000) cout<<s[10000000] - s[a-1]<<endl;
		else cout<<s[b] - s[a-1]<<endl;	
	}

	return 0;
}
