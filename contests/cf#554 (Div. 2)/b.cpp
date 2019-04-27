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

vi pot2;

int main(){
	ll x; cin>>x;
	pot2.pb(1);
	REP(i,nax){
		pot2.pb((*pot2.rbegin())*2);
	}

	int jugada = 0;
	vector<int> ans;
	while(1){
		bool fin = false;
		REP(i,pot2.size()){
			if(x==pot2[i]-1) fin = true;
		}
		if(fin) break;
		
		if(jugada%2==0){
			int w= pot2.size()-1;
			while(pot2[w]>=x)w--;
			
			while((pot2[w]&(~x))==0) w--;
			
			x = (x^(pot2[w+1]-1));
			ans.pb(w+1);
		}else{
			x++;
		}
		jugada++;
	}
	
	cout<<jugada<<endl;
	REP(i,ans.size()){
		cout<<ans[i]<<" ";
	}
	return 0;
}
