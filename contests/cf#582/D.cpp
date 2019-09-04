/*
The solution here relies on the fact that if the point of solution is some x
then the numbers that converge to that x are the closest (we compute the price 
by considering the closest numbers). And since we only need to run this in O(log(n))
we have no problem.
This is actually the solution to both problems.
*/
#include<bits/stdc++.h>
using namespace std;

#define nax 200009
#define FOR(i,n,m) for(ll i =(n);i<(m);i++)
#define REP(i,n) FOR(i,0,n)

typedef unsigned long long ll;
typedef vector<ll> vi;

int main(){
	int n,k; cin>>n>>k;
	ll repet[nax],count[nax];
	ll price[nax];
	vi a(n);
	
	memset(repet,0,sizeof repet);
	memset(count,0,sizeof count);
	memset(price,0LL,sizeof price);
	int w = 0;

	REP(i,n){
		cin>>a[i];
		repet[a[i]]++;
		if(repet[a[i]]==k){
			cout<<0<<endl;
			return 0;
		}
		count[a[i]]++;
	}

	ll ans = 0;
	REP(i,20){
		REP(j,nax){
			bool cont = false;
			int aux = j;
			REP(w,i+1){
				if(aux==0) cont = true;
				aux/=2;
			}
			if(cont) continue;

			if(count[aux]+repet[j]>=k){
				price[aux] += (k-count[aux])*(i+1);
				count[aux] = k;
				ans = price[aux];
			}else{
				count[aux] += repet[j];
				price[aux] += (i+1)*repet[j];
			}
		}
	}

	REP(i,nax){
		if(count[i]==k)
			ans = min(ans,price[i]);
	}

	cout<<ans;

	return 0;
}
