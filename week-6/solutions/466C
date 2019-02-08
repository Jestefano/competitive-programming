#include<bits/stdc++.h>
using namespace std;

#define MAX 500009
#define FOR(i,n,m) for(int i =(n) ;i<(m) ;i++)
#define REP(i,n) FOR(i,0,n)

typedef long long ll;

int main(){
	ll n,v[MAX],s1[MAX],s2[MAX];
	cin>>n;
	ll tot = 0;
	REP(i,n){
		cin>>v[i];
		tot+=v[i];
	}
	if(tot%3==0){
		ll busc = tot/3;
		s1[0] = v[0];
		FOR(i,1,n) s1[i] = s1[i-1] + v[i];

		s2[0] = (v[0]==busc)? 1:0;
		FOR(i,1,n){
			s2[i] = s2[i-1];
			if(s1[i]==busc) s2[i]++;
		}
		//Ahora dp!
		ll w = 0;
		FOR(i,1,n-1){
			if(s1[i]==2*busc){
				w += s2[i-1];
			}
		}
		cout<<w;
	}else{
		cout<<0;
	}

	return 0;
}
